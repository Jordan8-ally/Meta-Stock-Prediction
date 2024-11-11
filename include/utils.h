#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>
#include "LinearRegression.h"

std::vector<StockData> loadData(const std::string& filename);
double calculateMean(const std::vector<double>& data);
#endif