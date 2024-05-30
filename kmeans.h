#ifndef KMEANS_H
#define KMEANS_H

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include "csv.h"
#include "utils.h"

void initializeCentroids(std::vector<Point>& points, std::vector<Point>& centroids, int k);

void assignClusters(std::vector<Point>& points, std::vector<Point>& centroids);

void updateCentroids(std::vector<Point>& points, std::vector<Point>& centroids, int k);

bool checkConvergence(std::vector<Point>& oldCentroids, std::vector<Point>& newCentroids, double threshold);

void kmeans(std::vector<Point>& points, int k, double threshold = 0.001);

#endif