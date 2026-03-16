#include "tabla_frecuencia.hpp"

#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

int calcularNumeroClases(int totalDatos) {
    double sturges = 1.0 + 3.322 * std::log10(static_cast<double>(totalDatos));
    return static_cast<int>(std::ceil(sturges));
}

std::string formatearDecimal(double valor, int precision) {
    std::ostringstream salida;
    salida << std::fixed << std::setprecision(precision) << valor;
    return salida.str();
}

ResumenFrecuencia construirTablaFrecuencias(const std::vector<double>& datos) {
    ResumenFrecuencia resumen{};
    resumen.minimo = std::numeric_limits<double>::max();
    resumen.maximo = std::numeric_limits<double>::lowest();

    for (double valor : datos) {
        if (valor < resumen.minimo) {
            resumen.minimo = valor;
        }
        if (valor > resumen.maximo) {
            resumen.maximo = valor;
        }
    }

    resumen.numeroClases = calcularNumeroClases(static_cast<int>(datos.size()));
    resumen.rango = resumen.maximo - resumen.minimo;
    resumen.amplitud = resumen.rango / resumen.numeroClases;
    if (resumen.amplitud <= 0) {
        resumen.amplitud = 1.0;
    }

    resumen.clases.reserve(resumen.numeroClases);

    int frecuenciaAcumulada = 0;
    double frecuenciaRelativaAcumulada = 0.0;

    for (int i = 0; i < resumen.numeroClases; ++i) {
        double limiteInferior = resumen.minimo + i * resumen.amplitud;
        double limiteSuperior = limiteInferior + resumen.amplitud;

        if (i == resumen.numeroClases - 1) {
            limiteSuperior = resumen.maximo;
        }

        int frecuencia = 0;

        for (double valor : datos) {
            bool perteneceClase = false;

            if (i == resumen.numeroClases - 1) {
                perteneceClase = valor >= limiteInferior && valor <= limiteSuperior;
            } else {
                perteneceClase = valor >= limiteInferior && valor < limiteSuperior;
            }

            if (perteneceClase) {
                ++frecuencia;
            }
        }

        frecuenciaAcumulada += frecuencia;
        double frecuenciaRelativa = static_cast<double>(frecuencia) / datos.size();
        frecuenciaRelativaAcumulada += frecuenciaRelativa;

        resumen.clases.push_back({
            i + 1,
            limiteInferior,
            limiteSuperior,
            frecuencia,
            (limiteInferior + limiteSuperior) / 2.0,
            frecuenciaAcumulada,
            frecuenciaRelativa,
            frecuenciaRelativaAcumulada,
            frecuenciaRelativa * 100.0,
        });
    }

    if (!resumen.clases.empty()) {
        resumen.clases.back().frecuenciaRelativaAcumulada = 1.0;
    }

    return resumen;
}

void imprimirResumen(const ResumenFrecuencia& resumen, int cantidadDatos) {
    const int anchoTabla = 80;

    std::cout << "\nResumen:\n";
    std::cout << "Numero de clases: " << resumen.numeroClases << '\n';
    std::cout << "Valor minimo: " << formatearDecimal(resumen.minimo) << '\n';
    std::cout << "Valor maximo: " << formatearDecimal(resumen.maximo) << '\n';
    std::cout << "Rango: " << formatearDecimal(resumen.rango) << '\n';
    std::cout << "Amplitud de clase: " << formatearDecimal(resumen.amplitud) << "\n\n";

    std::cout << std::left
              << std::setw(6) << "Clase"
              << std::setw(24) << "Limite"
              << std::setw(6) << "f"
              << std::setw(8) << "Xc"
              << std::setw(6) << "Fa"
              << std::setw(7) << "fr"
              << std::setw(7) << "fra"
              << std::setw(8) << "%"
              << '\n';

    std::cout << std::string(anchoTabla, '-') << '\n';

    for (const ClaseFrecuencia& clase : resumen.clases) {
        std::ostringstream limite;
         limite << "[" << formatearDecimal(clase.limiteInferior) << ", "
             << formatearDecimal(clase.limiteSuperior) << ")";

         if (clase.numero == resumen.numeroClases) {
             limite.str("");
             limite.clear();
             limite << "[" << formatearDecimal(clase.limiteInferior) << ", "
                 << formatearDecimal(clase.limiteSuperior) << "]";
         }

        std::cout << std::left
                  << std::setw(6) << clase.numero
                  << std::setw(24) << limite.str()
                  << std::setw(6) << clase.frecuencia
                  << std::setw(8) << formatearDecimal(clase.puntoMedio)
                  << std::setw(6) << clase.frecuenciaAcumulada
                  << std::setw(7) << formatearDecimal(clase.frecuenciaRelativa)
                  << std::setw(7) << formatearDecimal(clase.frecuenciaRelativaAcumulada)
                  << std::setw(8) << formatearDecimal(clase.porcentaje)
                  << '\n';
    }

    std::cout << std::string(anchoTabla, '-') << '\n';
    std::cout << std::left
              << std::setw(30) << "TOTAL"
              << std::setw(6) << cantidadDatos
              << std::setw(14) << ""
              << std::setw(7) << ""
              << std::setw(7) << formatearDecimal(1.0)
              << std::setw(8) << formatearDecimal(100.0)
              << '\n';
}