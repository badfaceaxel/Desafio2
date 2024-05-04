#include "RedMetro.h"
#include <iostream>

void RedMetro::graficarRed() const {
    for (int i = 0; i < tamano; ++i) {
        std::cout << "Linea " << nombresLineas[i] << ":" << std::endl;
        lineas[i]->graficar();
        std::cout << std::endl;
    }
}


void RedMetro::agregarLinea(const std::string& nombreLinea) {
    expandirCapacidad();
    lineas[tamano] = new LineaMetro();
    nombresLineas[tamano] = nombreLinea;
    tamano++;
}

void RedMetro::expandirCapacidad() {
    if (tamano == capacidad) {
        capacidad = (capacidad == 0) ? 1 : capacidad * 2;
        LineaMetro** nuevoArrayLineas = new LineaMetro*[capacidad];
        std::string* nuevoArrayNombres = new std::string[capacidad];
        for (int i = 0; i < tamano; ++i) {
            nuevoArrayLineas[i] = lineas[i];
            nuevoArrayNombres[i] = nombresLineas[i];
        }
        delete[] lineas;
        delete[] nombresLineas;
        lineas = nuevoArrayLineas;
        nombresLineas = nuevoArrayNombres;
    }
}


//RedMetro::RedMetro() {}


//::RedMetro() : lineas(nullptr), nombresLineas(nullptr), capacidad(0), tamano(0) {}



void RedMetro::agregarEstacionALinea(const std::string& nombreLinea, const std::string& nombreEstacion) {
    for (int i = 0; i < tamano; ++i) {
        if (nombresLineas[i] == nombreLinea) {
            lineas[i]->agregarEstacionAlInicio(nombreEstacion);
            return;
        }
    }
    std::cerr << "Error: La línea especificada no existe." << std::endl;
}



int RedMetro::obtenerNumLineas() const {
    return tamano;
}

int RedMetro::obtenerNumEstacionesEnLinea(const std::string& nombreLinea) {
    for (int i = 0; i < tamano; ++i) {
        if (nombresLineas[i] == nombreLinea) {
            return lineas[i]->obtenerNumEstaciones();
        }
    }
    return -1; // Línea no encontrada
}

bool RedMetro::contieneEstacionEnLinea(const std::string& nombreLinea, const std::string& nombreEstacion) {
    for (int i = 0; i < tamano; ++i) {
        if (nombresLineas[i] == nombreLinea) {
            return lineas[i]->contieneEstacion(nombreEstacion);
        }
    }
    return false; // Línea no encontrada
}


