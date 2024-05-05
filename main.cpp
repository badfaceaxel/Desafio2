#include <iostream>
#include <string>
#include "Estacion.h"
#include "LineaMetro.h"
#include "RedMetro.h"
using namespace std;

int main() {
    RedMetro redMetro;

    char opcion;
    do {
        std::cout << "      RED METRO    "<<endl;
        cout<<endl;
        std::cout << "\n** Menu **\n";
        std::cout << "A. Agregar una estacion a una linea\n";
        std::cout << "B. Eliminar una estacion de una linea\n";
        std::cout << "C. Saber cuantas lineas tiene la red Metro\n";
        std::cout << "D. Saber cuantas estaciones tiene una linea dada\n";
        std::cout << "E. Saber si una estacion dada pertenece a una linea especifica\n";
        std::cout << "F. Agregar una linea a la red Metro\n";
        std::cout << "G. Eliminar una linea de la red Metro\n";
        std::cout << "H. Saber cuantas estaciones tiene la red Metro\n";
        std::cout << "I. Graficar la red Metro\n";
        std::cout << "X. Salir\n";
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;
        cout<<endl;
        cout<<endl;

        std::string nombreLinea, nombreEstacion;
        int posicion;

        switch (opcion) {
        case 'A':
            // Agregar una estación a una línea
            std::cout << "Ingrese el nombre de la linea: ";
            std::cin >> nombreLinea;
            std::cout << "Ingrese el nombre de la estacion: ";
            std::cin >> nombreEstacion;
            std::cout << "Ingrese la posición en la que desea agregar la estación: ";
            std::cin >> posicion;
            redMetro.agregarEstacionALineaEnPosicion(nombreLinea, nombreEstacion, posicion);
            cout<<endl;
            cout<<endl;
            break;
        case 'B':
            // Eliminar una estación de una línea
            std::cout << "Ingrese el nombre de la linea: ";
            std::cin >> nombreLinea;
            std::cout << "Ingrese el nombre de la estacion que desea eliminar: ";
            std::cin >> nombreEstacion;
            if (redMetro.eliminarEstacionDeLinea(nombreLinea, nombreEstacion)) {
                std::cout << "Estación eliminada exitosamente de la línea." << std::endl;
            } else {
                std::cerr << "Error: La estación no existe en la línea especificada." << std::endl;
            }
            cout<<endl;
            cout<<endl;
            break;
        case 'C':
            // Saber cuántas líneas tiene la red Metro
            std::cout << "La red Metro tiene " << redMetro.obtenerNumLineas() << " lineas." << std::endl;
            cout<<endl;
            cout<<endl;
            break;
        case 'D':
            // Saber cuántas estaciones tiene una línea dada
            std::cout << "Ingrese el nombre de la linea: ";
            std::cin >> nombreLinea;
            std::cout << "La linea " << nombreLinea << " tiene " << redMetro.obtenerNumEstacionesEnLinea(nombreLinea) << " estaciones." << std::endl;
            cout<<endl;
            cout<<endl;
            break;
        case 'E':
            // Saber si una estación dada pertenece a una línea específica
            std::cout << "Ingrese el nombre de la estacion: ";
            std::cin >> nombreEstacion;
            std::cout << "Ingrese el nombre de la linea: ";
            std::cin >> nombreLinea;
            if (redMetro.contieneEstacionEnLinea(nombreLinea, nombreEstacion)) {
                std::cout << "La estacion " << nombreEstacion << " pertenece a la linea " << nombreLinea << "." << std::endl;
            } else {
                std::cout << "La estacion " << nombreEstacion << " no pertenece a la linea " << nombreLinea << "." << std::endl;
            }
            cout<<endl;
            cout<<endl;
            break;
        case 'F':
            // Agregar una línea a la red Metro
            std::cout << "Ingrese el nombre de la linea: ";
            std::cin >> nombreLinea;
            redMetro.agregarLinea(nombreLinea);
            std::cout<<std::endl;
            std::cout<<std::endl;
            break;
        case 'G':
            // Eliminar una línea de la red Metro
            std::cout << "Ingrese el nombre de la linea que desea eliminar: ";
            std::cin >> nombreLinea;
            if (redMetro.eliminarLinea(nombreLinea)) {
                std::cout << "Línea eliminada exitosamente de la red Metro." << std::endl;
            } else {
                std::cerr << "Error: La línea especificada no existe." << std::endl;
            }
            std::cout<<endl;
            std::cout<<endl;
            break;
        case 'H':
            // Saber cuántas estaciones tiene la red Metro
            std::cout << "La red Metro tiene " << redMetro.obtenerNumEstacionesRed() << " estaciones." << std::endl;
            cout<<endl;
            cout<<endl;
            break;
        case 'X':
            // Salir del programa
            std::cout << "Saliendo del programa..." << std::endl;
            cout<<endl;
            cout<<endl;
            break;
        default:
            std::cout << "Opcion no valida. Por favor ingrese una opcion valida." << std::endl;
            cout<<endl;
            cout<<endl;
            break;
        case 'I':
            redMetro.graficarRed();
            cout<<endl;
            cout<<endl;
            break;

        }

    } while (opcion != 'X');

    return 0;
}