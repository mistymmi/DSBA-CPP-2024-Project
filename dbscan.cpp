#include "dbscan.h"


double silhouetteScore(const std::vector<Point>& points, int clusterCount) {
    std::vector<double> silhouetteScores(points.size(), 0.0);

    for (size_t i = 0; i < points.size(); ++i) {
        int currentCluster = points[i].cluster;
        if (currentCluster == -1) continue;
        double a = 0.0;
        double b = std::numeric_limits<double>::infinity();

        int aCount = 0;
        std::map<int, double> clusterDistances;
        std::map<int, int> clusterCounts;

        for (size_t j = 0; j < points.size(); ++j) {
            if (i == j) continue;

            double dist = distance(points[i], points[j]);
            int neighborCluster = points[j].cluster;

            if (currentCluster == neighborCluster) {
                a += dist;
                aCount++;
            } else {
                clusterDistances[neighborCluster] += dist;
                clusterCounts[neighborCluster]++;
            }
        }

        if (aCount > 0) {
            a /= aCount;
        }

        for (const auto& pair : clusterDistances) {
            int cluster = pair.first;
            double distanceSum = pair.second;
            int count = clusterCounts[cluster];
            double meanDistance = distanceSum / count;

            if (meanDistance < b) {
                b = meanDistance;
            }
        }

        silhouetteScores[i] = (b - a) / std::max(a, b);
    }

    double totalSilhouetteScore = std::accumulate(silhouetteScores.begin(), silhouetteScores.end(), 0.0);
    return totalSilhouetteScore / points.size();
}

std::pair<double, int> autoTuneDBSCAN(std::vector<Point>& points) {
    double bestEps = 0.5;
    int bestMinPts = 3;
    double bestScore = -std::numeric_limits<double>::infinity();

    std::vector<double> epsValues = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
    std::vector<int> minPtsValues = {3, 4, 5, 6, 7, 8, 9, 10};

    for (double eps : epsValues) {
        for (int minPts : minPtsValues) {
            std::vector<Point> pointsCopy = points;
            dbscan(pointsCopy, eps, minPts);

            int clusterCount = std::max_element(pointsCopy.begin(), pointsCopy.end(), [](const Point& a, const Point& b) {
                return a.cluster < b.cluster;
            })->cluster + 1;
            if (clusterCount > 1) {
                double score = silhouetteScore(pointsCopy, clusterCount);
                if (score > bestScore) {
                    bestScore = score;
                    bestEps = eps;
                    bestMinPts = minPts;
                }
            }
        }
    }

    std::cout << "Best eps: " << bestEps << ", Best minPts: " << bestMinPts << ", Best score: " << bestScore << std::endl;
    return {bestEps, bestMinPts};
}

std::vector<int> regionQuery(const std::vector<Point>& points, Point p, double eps) {
    std::vector<int> neighbors;
    for (int i = 0; i < points.size(); ++i) {
        if (distance(p, points[i]) <= eps) {
            neighbors.push_back(i);
        }
    }
    return neighbors;
}

void expandCluster(std::vector<Point>& points, int pointIdx, std::vector<int>& neighbors, int clusterId, double eps, int minPts) {
    points[pointIdx].cluster = clusterId;

    std::queue<int> seeds;
    for (int neighborIdx : neighbors) {
        if (points[neighborIdx].cluster == -1) {
            seeds.push(neighborIdx);
            points[neighborIdx].cluster = clusterId;
        }
    }

    while (!seeds.empty()) {
        int currentIdx = seeds.front();
        seeds.pop();

        if (!points[currentIdx].visited) {
            points[currentIdx].visited = true;
            std::vector<int> newNeighbors = regionQuery(points, points[currentIdx], eps);
            if (newNeighbors.size() >= minPts) {
                for (int newIdx : newNeighbors) {
                    if (points[newIdx].cluster == -1) {
                        seeds.push(newIdx);
                        points[newIdx].cluster = clusterId;
                    }
                }
            }
        }
    }
}

void dbscan(std::vector<Point>& points, double eps, int minPts) {
    int clusterId = 0;
    for (int i = 0; i < points.size(); ++i) {
        if (!points[i].visited) {
            points[i].visited = true;
            std::vector<int> neighbors = regionQuery(points, points[i], eps);
            if (neighbors.size() < minPts) {
                points[i].cluster = -1;
            } else {
                expandCluster(points, i, neighbors, clusterId++, eps, minPts);
            }
        }
    }
}


