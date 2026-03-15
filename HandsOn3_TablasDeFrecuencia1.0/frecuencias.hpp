#ifndef FRECUENCIAS_HPP
#define FRECUENCIAS_HPP

#include <string>
#include <vector>

struct CategoriaFrecuencia {
	std::string nombre;
	int frecuencia;
	double frecuenciaRelativa;
	int porcentaje;
};

int calcularTotal(const std::vector<CategoriaFrecuencia>& datos);
void calcularFrecuencias(std::vector<CategoriaFrecuencia>& datos);
void imprimirTabla(const std::vector<CategoriaFrecuencia>& datos);

#endif