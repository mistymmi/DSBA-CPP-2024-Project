#ifndef DBSCAN_H
#define DBSCAN_H

#include <vector>
#include <cmath>
#include <queue>
#include "csv.h"
#include "utils.h"

std::vector<int> regionQuery(const std::vector<Point>& points, Point p, double eps);

void expandCluster(std::vector<Point>& points, int pointIdx, std::vector<int>& neighbors, int clusterId, double eps, int minPts);

void dbscan(std::vector<Point>& points, double eps, int minPts);


#endif