#ifndef REDMETRO_H
#define REDMETRO_H

#include <string>
#include "LineaMetro.h"

class RedMetro {
public:
    RedMetro() : lineas(nullptr), nombresLineas(nullptr), capacidad(0), tamano(0) {}

    char obtenerNombreLinea(int indice) const;
    LineaMetro* obtenerLineaMetro(int indice) const;
    void agregarEstacionALineaEnPosicion(const char& nombreLinea, const std::string& nombreEstacion, int posicion, const int& tiempoAnterior, const int& tiempoSiguiente);
    bool eliminarEstacionDeLinea(const char& nombreLinea, const std::string& nombreEstacion);
    bool eliminarLinea(const char& nombreLinea);
    int obtenerNumEstacionesRed() const;
    void graficarRed() const;
    void agregarLinea(const char& nombreLinea);
    void agregarEstacionALinea(const char& nombreLinea, const std::string& nombreEstacion);

    int obtenerNumLineas() const;
    int obtenerNumEstacionesEnLinea(const char& nombreLinea);
    bool contieneEstacionEnLinea(const char& nombreLinea, const std::string& nombreEstacion);

private:
    LineaMetro** lineas;
    char* nombresLineas;
    int capacidad;
    int tamano;

    void expandirCapacidad();
};

#endif
