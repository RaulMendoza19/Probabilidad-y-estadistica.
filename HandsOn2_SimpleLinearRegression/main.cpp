#include "LinearRegression.hpp"
#include <iostream>
#include <vector>

int main() {
    LinearRegression model;
    model.fit();

    std::cout << "Ecuacion de Regresion: " << model.getEquation() << std::endl;

    std::vector<double> nuevosX = {20, 25, 35, 50, 60};
    std::vector<double> predicciones = model.predict(nuevosX);

    std::cout << "\nPredicciones:" << std::endl;
    for(size_t i=0; i<nuevosX.size(); i++){
        std::cout << "Advertising = " << nuevosX[i]
                  << " -> Sales = " << predicciones[i] << std::endl;
    }

    return 0;
}