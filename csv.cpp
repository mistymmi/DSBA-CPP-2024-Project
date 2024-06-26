#include "csv.h"

std::vector<Point> readCSV(const std::string& filename) {
    std::vector<Point> points;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Could not open the file!" << std::endl;
        return points;
    }

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string xStr, yStr;
        if (std::getline(ss, xStr, ',') && std::getline(ss, yStr, ',')) {
            double x = std::stod(xStr);
            double y = std::stod(yStr);
            points.emplace_back(x, y);
        }
    }

    file.close();
    return points;
}

void normalizePoints(std::vector<Point>& points) {
    double minX = std::numeric_limits<double>::max();
    double maxX = std::numeric_limits<double>::min();
    double minY = std::numeric_limits<double>::max();
    double maxY = std::numeric_limits<double>::min();

    for (const auto& point : points) {
        if (point.x < minX) minX = point.x;
        if (point.x > maxX) maxX = point.x;
        if (point.y < minY) minY = point.y;
        if (point.y > maxY) maxY = point.y;
    }

    for (auto& point : points) {
        point.x = (point.x - minX) / (maxX - minX);
        point.y = (point.y - minY) / (maxY - minY);
    }
}


