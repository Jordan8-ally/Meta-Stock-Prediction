#ifndef LINEARREGRESSION_H
#define LINEARREGRESSION_H

#include <vector>

struct StockData {
    double date;
    double price;   
};

class LinearRegression {
public:
    void fit(const std::vector<StockData>& data);
    double predict(double date) const;

private:
    double slope = 0.0;
    double intercept = 0.0;
};

#endif