#ifndef TABLA_FRECUENCIA_HPP
#define TABLA_FRECUENCIA_HPP

#include <string>
#include <vector>

struct ClaseFrecuencia {
    int numero;
    double limiteInferior;
    double limiteSuperior;
    int frecuencia;
    double puntoMedio;
    int frecuenciaAcumulada;
    double frecuenciaRelativa;
    double frecuenciaRelativaAcumulada;
    double porcentaje;
};

struct ResumenFrecuencia {
    int numeroClases;
    double minimo;
    double maximo;
    double rango;
    double amplitud;
    std::vector<ClaseFrecuencia> clases;
};

int calcularNumeroClases(int totalDatos);
std::string formatearDecimal(double valor, int precision = 2);
ResumenFrecuencia construirTablaFrecuencias(const std::vector<double>& datos);
void imprimirResumen(const ResumenFrecuencia& resumen, int cantidadDatos);

#endif