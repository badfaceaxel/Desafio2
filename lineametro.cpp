#include "LineaMetro.h"
#include <iostream>

void LineaMetro::graficar() const {
    std::cout << "Linea: ";
    for (int i = 0; i < tamano; ++i) {
        std::cout << std::setw(5) << estaciones[i]->nombre;
        if (i != tamano - 1) {
            std::cout << " -- ";
        }
    }
    std::cout << "\n          ";
    for (int i = 0; i < tamano; ++i) {
        std::cout << "  O";
        if (i != tamano - 1) {
            std::cout << " --------";
        }
    }
    std::cout << std::endl;
}



void LineaMetro::expandirCapacidad() {
    if (tamano == capacidad) {
        capacidad = (capacidad == 0) ? 1 : capacidad * 2;
        Estacion** nuevoArray = new Estacion*[capacidad];
        for (int i = 0; i < tamano; ++i) {
            nuevoArray[i] = estaciones[i];
        }
        delete[] estaciones;
        estaciones = nuevoArray;
    }
}

void LineaMetro::agregarEstacionAlInicio(const std::string& nombre) {
    expandirCapacidad();
    for (int i = tamano; i > 0; --i) {
        estaciones[i] = estaciones[i - 1];
    }
    estaciones[0] = new Estacion(nombre);
    tamano++;
}

void LineaMetro::agregarEstacionAlFinal(const std::string& nombre) {
    expandirCapacidad();
    estaciones[tamano] = new Estacion(nombre);
    tamano++;
}

void LineaMetro::agregarEstacionEnPosicion(const std::string& nombre, int posicion) {
    expandirCapacidad();
    if (posicion < 0 || posicion > tamano) {
        std::cerr << "Error: Posición inválida." << std::endl;
        return;
    }
    expandirCapacidad();
    for (int i = tamano; i > posicion; --i) {
        estaciones[i] = estaciones[i - 1];
    }
    estaciones[posicion] = new Estacion(nombre);
    tamano++;
}




bool LineaMetro::contieneEstacion(const std::string& nombre) {
    for (int i = 0; i < tamano; ++i) {
        if (estaciones[i]->nombre == nombre) {
            return true;
        }
    }
    return false;
}

int LineaMetro::obtenerNumEstaciones() const {
    return tamano;
}



