#include <iostream>
#include <vector>
#include "graphs.h"
#include "csv.h"
#include "dbscan.h"
#include "kmeans.h"

int main() {
    std::vector<Point> points = readCSV("filepath.csv");

    int k = 3;
    kmeans(points, k);
    for (const auto& point : points) {
        std::cout << "x: " << point.x << ", y: " << point.y
                  << ", cluster: " << point.cluster << std::endl;
    }

    drawClusters(points);

    std::vector<Point> points1 = readCSV("filepath.csv");
    auto [bestEps, bestMinPts] = autoTuneDBSCAN(points1);
    dbscan(points1, bestEps, bestMinPts);
    for (const auto& point : points1) {
        std::cout << "x: " << point.x << ", y: " << point.y
                  << ", cluster: " << point.cluster << std::endl;
    }

    drawClusters(points1);

    return 0;
}
