#include "LinearRegression.h"
#include <numeric>

void LinearRegression::fit(const std::vector<StockData>& data) {
    double x = 0.0, y = 0.0, xy = 0.0, xx = 0.0;
    size_t n = data.size();

    for (const auto& stock : data) {
        x += stock.date;
        y += stock.price;
        xy += stock.date * stock.price;
        xx += stock.date * stock.date;
    }

    slope = (n * (x * y) - (x * y)) / (n * (x * x) - x * x);
    intercept = ((y * x * x) - (y * x * y)) / ((n * x * x) - (x * x));
    
}

double LinearRegression::predict(double date) const {
    return slope * date + intercept;
}
