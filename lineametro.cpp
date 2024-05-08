#include "LineaMetro.h"
#include <iostream>

bool LineaMetro::eliminarEstacion(const std::string& nombre) {
    int indiceEliminar = -1;
    for (int i = 0; i < tamano; ++i) {
        if (estaciones[i]->nombre == nombre) {
            indiceEliminar = i;
            break;
        }
    }

    if (indiceEliminar == -1) {
        return false; // Estación no encontrada
    }

    if (indiceEliminar == 0) {
        // Eliminar la primera estación (no se suma tiempoSiguiente)
        delete estaciones[0];
        for (int j = 0; j < tamano - 1; ++j) {
            estaciones[j] = estaciones[j + 1];
        }
    } else if (indiceEliminar == tamano - 1) {
        // Eliminar la última estación (tiempoSiguiente de la anterior = 0)
        delete estaciones[tamano - 1];
        estaciones[tamano - 2]->tiempoSiguiente = 0;
    } else {
        // Eliminar una estación intermedia (sumar tiempoSiguiente a la anterior)
        estaciones[indiceEliminar - 1]->tiempoSiguiente += estaciones[indiceEliminar]->tiempoSiguiente;
        delete estaciones[indiceEliminar];
        for (int j = indiceEliminar; j < tamano - 1; ++j) {
            estaciones[j] = estaciones[j + 1];
        }
    }

    tamano--;
    return true;
}


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

void LineaMetro::agregarEstacionAlInicio(const std::string& nombre, int tiempoSiguiente) {
    expandirCapacidad();
    for (int i = tamano; i > 0; --i) {
        estaciones[i] = estaciones[i - 1];
    }
    estaciones[0] = new Estacion(nombre, tiempoSiguiente);
    if (tamano > 0) {
        estaciones[1]->tiempoSiguiente = tiempoSiguiente;
    }
    tamano++;
}

void LineaMetro::agregarEstacionAlFinal(const std::string& nombre, int tiempoAnterior) {
    expandirCapacidad();
    estaciones[tamano] = new Estacion(nombre);
    if (tamano > 0) {
        estaciones[tamano - 1]->tiempoSiguiente = tiempoAnterior;
    }
    tamano++;
}


void LineaMetro::agregarEstacionEnPosicion(const std::string& nombre, int posicion, int tiempoAnterior, int tiempoSiguiente) {
    expandirCapacidad();
    if (posicion < 0 || posicion > tamano) {
        std::cerr << "Error: Posición inválida." << std::endl;
        return;
    }
    for (int i = tamano; i > posicion; --i) {
        estaciones[i] = estaciones[i - 1];
    }
    estaciones[posicion] = new Estacion(nombre, tiempoSiguiente);
    if (posicion > 0) {
        estaciones[posicion - 1]->tiempoSiguiente = tiempoAnterior;
    }
    if (posicion < tamano - 1) {
        estaciones[posicion + 1]->tiempoSiguiente = tiempoSiguiente;
    }
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



int LineaMetro::obtenerTiempoEntreEstaciones(const std::string& nombreEstacionInicio, const std::string& nombreEstacionFin) {
    int indiceInicio = -1, indiceFin = -1;
    for (int i = 0; i < tamano; ++i) {
        if (estaciones[i]->nombre == nombreEstacionInicio) {
            indiceInicio = i;
        } else if (estaciones[i]->nombre == nombreEstacionFin) {
            indiceFin = i;
        }
        if (indiceInicio != -1 && indiceFin != -1) {
            break;
        }
    }

    if (indiceInicio == -1 || indiceFin == -1) {
        std::cerr << "Error: Una o ambas estaciones no existen en la línea." << std::endl;
        return -1;
    }

    int tiempo = 0;
    if (indiceInicio < indiceFin) {
        for (int i = indiceInicio; i < indiceFin; ++i) {
            tiempo += estaciones[i]->tiempoSiguiente;
        }
    } else {
        for (int i = indiceFin; i < indiceInicio; ++i) {
            tiempo += estaciones[i]->tiempoSiguiente;
        }
    }

    return tiempo;
}
