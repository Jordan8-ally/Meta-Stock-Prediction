#include "LinearRegression.h"
#include "utils.h"
#include <iostream>

int main() {
    auto data = loadData("/Users/fever_dreamer/Desktop/C++/Meta_Stock_Prediction/data/meta_stock_data.csv");

    LinearRegression model;
    model.fit(data);
    int future_date = 20250101;
    double predicted_price = model.predict(future_date);

    std::cout << "Predicted price for Meta on " << future_date << " is: " << predicted_price << std::endl;
    
    return 0;
}