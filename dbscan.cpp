#include "dbscan.h"

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

