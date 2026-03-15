#include "LinearRegression.hpp"
#include <iostream>
#include <sstream>

LinearRegression::LinearRegression() {
    // Dataset Benetton (Advertising vs Sales)
    x = {23, 26, 30, 34, 43, 48, 52, 57, 58};
    y = {651, 762, 856, 1063, 1190, 1298, 1421, 1440, 1518};
    B0 = 0;
    B1 = 0;
}

void LinearRegression::fit() {
    int n = x.size();
    double sumX=0, sumY=0;
    for(int i=0; i<n; i++){
        sumX += x[i];
        sumY += y[i];
    }
    double meanX = sumX/n;
    double meanY = sumY/n;

    double num=0, den=0;
    for(int i=0; i<n; i++){
        num += (x[i]-meanX)*(y[i]-meanY);
        den += (x[i]-meanX)*(x[i]-meanX);
    }
    B1 = num/den;
    B0 = meanY - B1*meanX;
}

std::string LinearRegression::getEquation() const {
    std::ostringstream eq;
    eq << "Sales = " << B0 << " + " << B1 << " * Advertising";
    return eq.str();
}

double LinearRegression::predict(double x_value) const {
    return B0 + B1*x_value;
}

std::vector<double> LinearRegression::predict(const std::vector<double>& x_values) const {
    std::vector<double> results;
    for(double val : x_values){
        results.push_back(predict(val));
    }
    return results;
}