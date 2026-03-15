#ifndef LINEAR_REGRESSION_HPP
#define LINEAR_REGRESSION_HPP

#include <vector>
#include <string>

class LinearRegression {
private:
    std::vector<double> x; // Advertising
    std::vector<double> y; // Sales
    double B0; // Intercepto
    double B1; // Pendiente

public:
    // Constructor con dataset hardcoded
    LinearRegression();

    // Método para entrenar el modelo
    void fit();

    // Obtener la ecuación como string
    std::string getEquation() const;

    // Predicción para un valor de Advertising
    double predict(double x_value) const;

    // Predicciones para un conjunto de valores
    std::vector<double> predict(const std::vector<double>& x_values) const;
};

#endif