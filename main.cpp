#include <iostream>
#include <vector>
#include "graphs.h"
#include "csv.h"
#include "dbscan.h"
#include "kmeans.h"

int main() {
    std::vector<Point> points = readCSV("filepath/filename.csv");

    // Apply k-means
    int k = 3; // Number of clusters for k-means
    kmeans(points, k);
    for (const auto& point : points) {
        std::cout << "x: " << point.x << ", y: " << point.y
                  << ", cluster: " << point.cluster << std::endl;
    }

    drawClusters(points);

    std::vector<Point> points1 = readCSV("filepath/name.csv");
    double eps = 0.005;
    int minPts = 1;
    dbscan(points1, eps, minPts);
    for (const auto& point : points1) {
        std::cout << "x: " << point.x << ", y: " << point.y
                  << ", cluster: " << point.cluster << std::endl;
    }

    drawClusters(points1);

    return 0;
}
