#include <iostream>
#include <vector>
#include "csv.h"
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

  return 0;
}
