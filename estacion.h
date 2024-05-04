#ifndef ESTACION_H
#define ESTACION_H

#include <iomanip>
#include <string>

class Estacion {
public:
    Estacion(const std::string& nombre) : nombre(nombre), siguiente(nullptr) {}
    std::string nombre;
    Estacion* siguiente;
};

#endif
