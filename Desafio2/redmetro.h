#ifndef REDMETRO_H
#define REDMETRO_H

#include <string>
#include "LineaMetro.h"

class RedMetro {
public:
    RedMetro() : lineas(nullptr), nombresLineas(nullptr), capacidad(0), tamano(0) {}

    void graficarRed() const;
    void agregarLinea(const std::string& nombreLinea);
    void agregarEstacionALinea(const std::string& nombreLinea, const std::string& nombreEstacion);

    int obtenerNumLineas() const;
    int obtenerNumEstacionesEnLinea(const std::string& nombreLinea);
    bool contieneEstacionEnLinea(const std::string& nombreLinea, const std::string& nombreEstacion);

private:
    LineaMetro** lineas;
    std::string* nombresLineas;
    int capacidad;
    int tamano;

    void expandirCapacidad();
};

#endif
