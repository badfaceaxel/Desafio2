#ifndef ESTACION_H
#define ESTACION_H

#include <iomanip>
#include <string>
using namespace std;

class Estacion {
public:
    Estacion(const std::string& nombre, int tiempoSiguiente = 0) : nombre(nombre), siguiente(nullptr), tiempoSiguiente(tiempoSiguiente) {}
    string nombre;
    Estacion* siguiente;
    int tiempoSiguiente;
};

#endif
