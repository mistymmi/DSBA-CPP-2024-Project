#include <iostream>
#include <vector>
#include "graphs.h"
#include "csv.h"
#include "dbscan.h"
#include "kmeans.h"

void exportClusters(const std::vector<Point>& points, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << "x,y,cluster\n";
        for (const auto& point : points) {
            file << point.x << "," << point.y << "," << point.cluster << "\n";
        }
        file.close();
    } else {
        std::cerr << "Unable to open file for writing: " << filename << std::endl;
    }
}

int main() {
    std::vector<Point> points = readCSV("file.csv");
    normalizePoints(points);
    int k = 3;
    kmeans(points, k);
    for (const auto& point : points) {
        std::cout << "x: " << point.x << ", y: " << point.y
                  << ", cluster: " << point.cluster << std::endl;
    }

    drawClusters(points);
    exportClusters(points, "kmeans_data.csv");

    std::vector<Point> points1 = readCSV("file.csv");
    normalizePoints(points1);
    auto [bestEps, bestMinPts] = autoTuneDBSCAN(points1);
    dbscan(points1, bestEps, bestMinPts);
    for (const auto& point : points1) {
        std::cout << "x: " << point.x << ", y: " << point.y
                  << ", cluster: " << point.cluster << std::endl;
    }

    drawClusters(points1);
    exportClusters(points1, "dbscan_data.csv");

    return 0;
}
