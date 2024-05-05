#include "RedMetro.h"
#include <iostream>

void RedMetro::agregarEstacionALineaEnPosicion(const std::string& nombreLinea, const std::string& nombreEstacion, int posicion) {
    for (int i = 0; i < tamano; ++i) {
        if (nombresLineas[i] == nombreLinea) {
            lineas[i]->agregarEstacionEnPosicion(nombreEstacion, posicion);
            return;
        }
    }
    std::cerr << "Error: La línea especificada no existe." << std::endl;
}


bool RedMetro::eliminarEstacionDeLinea(const std::string& nombreLinea, const std::string& nombreEstacion) {
    for (int i = 0; i < tamano; ++i) {
        if (nombresLineas[i] == nombreLinea) {
            return lineas[i]->eliminarEstacion(nombreEstacion);
        }
    }
    std::cerr << "Error: La línea especificada no existe." << std::endl;
    return false;
}



bool RedMetro::eliminarLinea(const std::string& nombreLinea) {
    for (int i = 0; i < tamano; ++i) {
        if (nombresLineas[i] == nombreLinea) {
            delete lineas[i];
            for (int j = i; j < tamano - 1; ++j) {
                lineas[j] = lineas[j + 1];
                nombresLineas[j] = nombresLineas[j + 1];
            }
            tamano--;
            return true;
        }
    }
    std::cerr << "Error: La línea especificada no existe." << std::endl;
    return false;
}


int RedMetro::obtenerNumEstacionesRed() const {
    int numEstaciones = 0;
    for (int i = 0; i < tamano; ++i) {
        numEstaciones += lineas[i]->obtenerNumEstaciones();
    }
    return numEstaciones;
}


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


