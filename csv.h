#ifndef CSV_H
#define CSV_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

struct Point {
    double x, y;
    int cluster;
    bool visited;

    Point(double x, double y) : x(x), y(y), cluster(-1), visited(false) {}
};

std::vector<Point> readCSV(const std::string& filename);

#endif
