#include "utils.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <numeric>
#include <stdexcept>

std::vector<StockData> loadData(const std::string& filename) {
    std::vector<StockData> data;
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Could not open the file: " + filename);
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        StockData stock;
        std::string Date, Price;

        if (ss >> Date >> Price) {
            try {
                stock.date = std::stoi(Date);
                stock.price = std::stod(Price);
                data.push_back(stock);
            }
            catch (const std::invalid_argument& e ) {
                std::cerr << "Warning: Error parsing the lines: " << line << std::endl;
            }
            
        }
    }
return data;

}

double calculateMean(const std::vector<double>& data) {
    double sum = std::accumulate(data.begin(), data.end(), 0.0);
    return sum / data.size();
}