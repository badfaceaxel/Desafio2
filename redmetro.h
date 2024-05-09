#ifndef REDMETRO_H
#define REDMETRO_H

#include <string>
#include "LineaMetro.h"



class RedMetro {
public:
    RedMetro() : lineas(nullptr), nombresLineas(nullptr), capacidad(0), tamano(0), estacionesTransf(nullptr), capacidadTransf(0), tamanoTransf(0) {}
   ~RedMetro();
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
    void imprimirEstacionesTransferencia() const;

    bool existeEstacionTransferencia(const std::string& nombreEstacion) const;




private:
    LineaMetro** lineas;
    char* nombresLineas;
    int capacidad;
    int tamano;

    std::string* estacionesTransf; // Arreglo dinámico de strings
    int capacidadTransf;
    int tamanoTransf;

    void expandirCapacidadTransf();

    void expandirCapacidad();

};

#endif
