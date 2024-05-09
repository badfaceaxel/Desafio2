#ifndef LINEAMETRO_H
#define LINEAMETRO_H

#include <string>
#include "Estacion.h"

class LineaMetro {
public:
    LineaMetro() : estaciones(nullptr), capacidad(0), tamano(0) {}

    int obtenerTiempoEntreEstaciones(const std::string& nombreEstacionInicio, const std::string& nombreEstacionFin);
    bool eliminarEstacion(const std::string& nombre);
    void graficar() const;
    void agregarEstacionAlInicio(const std::string& nombre, int tiempoSiguiente);
    void agregarEstacionAlFinal(const std::string& nombre, int tiempoAnterior);
    void agregarEstacionEnPosicion(const std::string& nombre, int posicion, int tiempoAnterior, int tiempoSiguiente);

    bool contieneEstacion(const std::string& nombre);
    int obtenerNumEstaciones() const;
    string obtenerNombreEstacion(int indice) const;


private:
    Estacion** estaciones;
    int capacidad;
    int tamano;

    void expandirCapacidad();

};

#endif
