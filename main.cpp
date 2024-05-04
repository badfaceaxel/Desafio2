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
        cout<<endl;
        std::cout << "Seleccione una opcion: ";
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
            redMetro.agregarEstacionALinea(nombreLinea, nombreEstacion);
            cout<<endl;
            cout<<endl;
            break;
        case 'B':

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
            cout<<endl;
            cout<<endl;
            break;
        case 'G':
            break;
        case 'H':

            break;            
        case 'I':
            redMetro.graficarRed();
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
        }

    } while (opcion != 'X');

    return 0;
}
