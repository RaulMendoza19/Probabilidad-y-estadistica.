#include "frecuencias.hpp"
#include <cmath>
#include <iomanip>
#include <iostream>

int calcularTotal(const std::vector<CategoriaFrecuencia>& datos) {
	int total = 0;
	for (const auto& item : datos) {
		total += item.frecuencia;
	}
	return total;
}

void calcularFrecuencias(std::vector<CategoriaFrecuencia>& datos) {
	const int total = calcularTotal(datos);
	if (total == 0) {
		return;
	}

	for (auto& item : datos) {
		item.frecuenciaRelativa = static_cast<double>(item.frecuencia) / total;
		item.porcentaje = static_cast<int>(std::round(item.frecuenciaRelativa * 100.0));
	}
}

void imprimirTabla(const std::vector<CategoriaFrecuencia>& datos) {
	std::cout << "Categoria\tF\tFr\t%\n";
	for (const auto& item : datos) {
		std::cout << item.nombre << "\t\t"
				  << item.frecuencia << "\t"
				  << std::fixed << std::setprecision(4) << item.frecuenciaRelativa << "\t"
				  << item.porcentaje << "\n";
	}
}
