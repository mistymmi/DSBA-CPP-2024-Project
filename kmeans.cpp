#include <vector>
#include <cstdlib>
#include <ctime>
#include "kmeans.h"


void initializeCentroids(std::vector<Point>& points, std::vector<Point>& centroids, int k) {
    srand(time(0));
    for (int i = 0; i < k; ++i) {
        int index = rand() % points.size();
        centroids.push_back(points[index]);
    }
}

void assignClusters(std::vector<Point>& points, std::vector<Point>& centroids) {
    for (auto& point : points) {
        double minDist = distance(point, centroids[0]);
        point.cluster = 0;
        for (int i = 1; i < centroids.size(); ++i) {
            double dist = distance(point, centroids[i]);
            if (dist < minDist) {
                minDist = dist;
                point.cluster = i;
            }
        }
    }
}

void updateCentroids(std::vector<Point>& points, std::vector<Point>& centroids, int k) {
    std::vector<int> counts(k, 0);
    std::vector<Point> newCentroids;
    newCentroids.reserve(k);
for (int i = 0; i < k; ++i)
        newCentroids.push_back(Point(0, 0));


    for (auto& point : points) {
        newCentroids[point.cluster].x += point.x;
        newCentroids[point.cluster].y += point.y;
        counts[point.cluster]++;
    }

    for (int i = 0; i < k; ++i) {
        if (counts[i] > 0) {
            newCentroids[i].x /= counts[i];
            newCentroids[i].y /= counts[i];
        }
        centroids[i] = newCentroids[i];
    }
}

bool checkConvergence(std::vector<Point>& oldCentroids, std::vector<Point>& newCentroids, double threshold) {
    for (int i = 0; i < oldCentroids.size(); ++i) {
        if (distance(oldCentroids[i], newCentroids[i]) > threshold) {
            return false;
        }
    }
    return true;
}

void kmeans(std::vector<Point>& points, int k, double threshold) {
    std::vector<Point> centroids;
    initializeCentroids(points, centroids, k);

    std::vector<Point> oldCentroids;
    bool converged = false;

    while (!converged) {
        oldCentroids = centroids;

        assignClusters(points, centroids);
        updateCentroids(points, centroids, k);

        converged = checkConvergence(oldCentroids, centroids, threshold);
    }
}


