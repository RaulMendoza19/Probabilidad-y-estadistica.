#include <iostream>
#include <vector>

#include "tabla_frecuencia.hpp"

int main() {
    const std::vector<double> datos = {
        25.4, 26.1, 27.8, 28.2, 29.7, 30.5, 31.3, 32.9,
        33.4, 34.8, 35.2, 36.7, 37.1, 38.6, 39.9, 40.4,
        41.8, 42.3, 43.7, 44.1, 45.6, 46.2, 47.5, 48.9,
        49.4, 50.8, 51.6, 60.2, 65.5, 70.1, 78.4
    };

    std::cout << "Tabla de frecuencia agrupada\n";
    std::cout << "DataSet hardcoded de numeros reales\n";

    int cantidadDatos = static_cast<int>(datos.size());

    if (cantidadDatos < 30) {
        std::cerr << "Error: el dataset debe contener al menos 30 datos.\n";
        return 1;
    }

    ResumenFrecuencia resumen = construirTablaFrecuencias(datos);
    imprimirResumen(resumen, cantidadDatos);

    return 0;
}