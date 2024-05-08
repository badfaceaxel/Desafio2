#include "RedMetro.h"
#include <iostream>
int TAMANO_INICIAL_TRANSFERENCIAS = 10;


bool RedMetro::existeEstacionTransferencia(const std::string& nombreEstacion) const {
    for (int i = 0; i < tamanoTransf; ++i) {
        if (estacionesTransf[i] == nombreEstacion) {
            return true;
        }
    }
    return false;
}


void RedMetro::imprimirEstacionesTransferencia() const {
    std::cout << "Estaciones de transferencia:" << std::endl;
    for (int i = 0; i < tamanoTransf; ++i) {
        std::cout << estacionesTransf[i] << std::endl;
    }
}


void RedMetro::expandirCapacidadTransf() {
    if (tamanoTransf == capacidadTransf) {
        capacidadTransf = (capacidadTransf == 0) ? TAMANO_INICIAL_TRANSFERENCIAS : capacidadTransf * 2;
        std::string* nuevoArray = new std::string[capacidadTransf];
        for (int i = 0; i < tamanoTransf; ++i) {
            nuevoArray[i] = estacionesTransf[i];
        }
        delete[] estacionesTransf;
        estacionesTransf = nuevoArray;
    }
}


RedMetro::~RedMetro() {
    for (int i = 0; i < tamano; ++i) {
        delete lineas[i];
    }
    delete[] lineas;
    delete[] nombresLineas;
    delete[] estacionesTransf;
}



char RedMetro::obtenerNombreLinea(int indice) const {
    return nombresLineas[indice];
}

LineaMetro* RedMetro::obtenerLineaMetro(int indice) const {
    return lineas[indice];
}


void RedMetro::agregarEstacionALineaEnPosicion(const char& nombreLinea, const std::string& nombreEstacion, int posicion, const int& tiempoAnterior, const int& tiempoSiguiente) {
    for (int i = 0; i < tamano; ++i) {
        if (nombresLineas[i] == nombreLinea) {
            lineas[i]->agregarEstacionEnPosicion(nombreEstacion, posicion, tiempoAnterior, tiempoSiguiente);
            return;
        }
    }
    std::cerr << "Error: La línea especificada no existe." << std::endl;
}


bool RedMetro::eliminarEstacionDeLinea(const char& nombreLinea, const std::string& nombreEstacion) {
    for (int i = 0; i < tamano; ++i) {
        if (nombresLineas[i] == nombreLinea) {
            return lineas[i]->eliminarEstacion(nombreEstacion);
        }
    }
    std::cerr << "Error: La línea especificada no existe." << std::endl;
    return false;
}



bool RedMetro::eliminarLinea(const char& nombreLinea) {
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


void RedMetro::agregarLinea(const char& nombreLinea) {
    // Verificar si la línea ya existe
    for (int i = 0; i < tamano; ++i) {
        if (nombresLineas[i] == nombreLinea) {
            std::cerr << "Error: Ya existe una linea con ese nombre." << std::endl;
            cout<<endl;
            cout<<endl;
            return;
        }
    }

    // Si la línea no existe, agregarla
    expandirCapacidad();
    lineas[tamano] = new LineaMetro();
    nombresLineas[tamano] = nombreLinea;
    tamano++;

    // Si es la primera línea que se crea, no preguntar por conexión
    if (tamano == 1) {
        cout<<"Ingrese el nombre de la primera estacion de la linea: ";
        string nombreEstacion1;
        cin>>nombreEstacion1;
        agregarEstacionALinea(nombreLinea, nombreEstacion1);
        std::cout << "Se ha creado la primera linea de la red de metro junto con su primera estacion." << std::endl;
        cout<<endl;
        cout<<endl;
        return;
    }

    std::cout << "Ingrese la línea a la cual desea conectar la nueva línea: ";
    char lineaTrans;
    std::cin >> lineaTrans;


    std::cout << "Ingrese el nombre de la estacion a la cual va a conectar la nueva línea: ";
    std::string nombreEstacion;
    std::cin >> nombreEstacion;

    // Verificar si la estación de transferencia ya existe
    if (!existeEstacionTransferencia(nombreEstacion)) {
        // Agregar la estación de transferencia al arreglo
        expandirCapacidadTransf();
        estacionesTransf[tamanoTransf++] = nombreEstacion;
    }


    //Guardar este nombre estacion en el arreglo estacionesTransf, y verificar que no este repetido

    /*
    // Verificar si la estación ingresada pertenece a la línea especificada
    bool estacionEncontrada = false;
    for (int i = 0; i < tamano; ++i) {
        if (nombresLineas[i] == lineaTrans && lineas[i]->contieneEstacion(nombreEstacion)) {
            estacionEncontrada = true;
            break;
        }
    }


    if (!estacionEncontrada) {
        std::cerr << "Error: La estación ingresada no pertenece a la línea especificada." << std::endl;
        return;
    }
    */

    // Agregar la estación de transferencia al arreglo
    //string nuevoNombre = nombreEstacion+nombreLinea;

    agregarEstacionALinea(nombreLinea, nombreEstacion+nombreLinea);
}

void RedMetro::expandirCapacidad() {
    if (tamano == capacidad) {
        capacidad = (capacidad == 0) ? 1 : capacidad * 2;
        LineaMetro** nuevoArrayLineas = new LineaMetro*[capacidad];
        char* nuevoArrayNombres = new char[capacidad];
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



void RedMetro::agregarEstacionALinea(const char& nombreLinea, const std::string& nombreEstacion) {
    int tiempoSiguiente = 0;
    for (int i = 0; i < tamano; ++i) {
        if (nombresLineas[i] == nombreLinea) {
            lineas[i]->agregarEstacionAlInicio(nombreEstacion, tiempoSiguiente);
            return;
        }
    }
    std::cerr << "Error: La línea especificada no existe." << std::endl;
}



int RedMetro::obtenerNumLineas() const {
    return tamano;
}

int RedMetro::obtenerNumEstacionesEnLinea(const char& nombreLinea) {
    for (int i = 0; i < tamano; ++i) {
        if (nombresLineas[i] == nombreLinea) {
            return lineas[i]->obtenerNumEstaciones();
        }
    }
    return -1; // Línea no encontrada
}

bool RedMetro::contieneEstacionEnLinea(const char& nombreLinea, const std::string& nombreEstacion) {
    for (int i = 0; i < tamano; ++i) {
        if (nombresLineas[i] == nombreLinea) {
            return lineas[i]->contieneEstacion(nombreEstacion);
        }
    }
    return false; // Línea no encontrada
}




