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

