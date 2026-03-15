#include "frecuencias.hpp"

int main() {
    std::vector<CategoriaFrecuencia> datos = {
        {"Carro", 15, 0.0, 0},
        {"Avion", 13, 0.0, 0},
        {"Tren", 4, 0.0, 0},
        {"Barco", 8, 0.0, 0}
    };

    calcularFrecuencias(datos);
    imprimirTabla(datos);

    return 0;
}
