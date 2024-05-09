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
        std::cout << "J. Saber el tiempo de llegada entre estaciones de una misma linea\n";
        std::cout << "K. Mostrar estaciones de transferencia.\n";
        std::cout << "X. Salir\n";
        cout<<endl;
        std::cout << "Seleccione una opcion: ";
        std::string entrada;
        std::cin >> entrada;
        cout<<endl;
        cout<<endl;

        // Verificar si la longitud de la entrada es mayor que 1
        if (entrada.length() > 1) {//length es un metodo de string
            std::cout << "Error: Solo se permite ingresar un caracter. Por favor, ingrese una opcion valida." << std::endl;
            cout<<endl;
            cout<<endl;
            continue; // Volver al inicio del bucle
        }

        opcion = entrada[0];
        cout<<endl;
        cout<<endl;

        std::string nombreEstacion;

        std::string nombreEstacionFin;
        int posicion, tiempoAnterior, tiempoSiguiente, numEstaciones;
        char nombreLinea;

        switch (opcion) {
        case 'A':
        case 'a':
            std::cout << "Ingrese el nombre de la linea: ";
            std::cin >> nombreLinea;
            std::cout << "Ingrese el nombre de la estacion: ";
            std::cin >> nombreEstacion;
            std::cout << "Ingrese la posición en la que desea agregar la estación: ";
            std::cin >> posicion;
            numEstaciones = redMetro.obtenerNumEstacionesEnLinea(nombreLinea);
            if (posicion == 0){
                std::cout << "Ingrese el tiempo de la estacion anterior: ";
                std::cin >> tiempoAnterior;
                if(tiempoAnterior!=0){
                    std::cerr << "Error: El tiempo anterior tiene que ser 0." << std::endl;
                    cout<<endl;
                    cout<<endl;
                    break;
                }
                std::cout << "Ingrese el tiempo de la siguiente estacion: ";
                std::cin >> tiempoSiguiente;
                redMetro.agregarEstacionALineaEnPosicion(nombreLinea, nombreEstacion, posicion, tiempoAnterior, tiempoSiguiente);
                break;
            }
            else if ((posicion) == (numEstaciones)){
                std::cout << "Ingrese el tiempo de la siguiente estacion: ";
                std::cin >> tiempoSiguiente;
                if(tiempoSiguiente!=0){
                    std::cerr << "Error: El tiempo siguiente tiene que ser 0." << std::endl;
                    cout<<endl;
                    cout<<endl;
                    break;
                }
                std::cout << "Ingrese el tiempo de la anterior estacion: ";
                std::cin >> tiempoAnterior;
                redMetro.agregarEstacionALineaEnPosicion(nombreLinea, nombreEstacion, posicion, tiempoAnterior, tiempoSiguiente);
                cout<<endl;
                cout<<endl;
                break;
            }

            else {
                std::cout << "Ingrese el tiempo de la estacion anterior: ";
                std::cin >> tiempoAnterior;
                std::cout << "Ingrese el tiempo de la siguiente estacion: ";
                std::cin >> tiempoSiguiente;
                redMetro.agregarEstacionALineaEnPosicion(nombreLinea, nombreEstacion, posicion, tiempoAnterior, tiempoSiguiente);
                cout<<endl;
                cout<<endl;
                break;
            }

        case 'B':
        case 'b':
            //Verificar que la estacion no sea una estacion de transferencia (ya que estas no se pueden borrar)
            // Eliminar una estación de una línea
            std::cout << "Ingrese el nombre de la linea: ";
            std::cin >> nombreLinea;
            std::cout << "Ingrese el nombre de la estacion que desea eliminar: ";
            std::cin >> nombreEstacion;
            if (redMetro.eliminarEstacionDeLinea(nombreLinea, nombreEstacion)) {
                std::cout << "Estación eliminada exitosamente de la línea." << std::endl;
                cout<<endl;
                cout<<endl;
            } else {
                std::cerr << "Error: La estación no existe en la línea especificada." << std::endl;
                cout<<endl;
                cout<<endl;
            }
            break;
        case 'C':
        case 'c':
            // Saber cuántas líneas tiene la red Metro
            std::cout << "La red Metro tiene " << redMetro.obtenerNumLineas() << " lineas." << std::endl;
            cout<<endl;
            cout<<endl;
            break;
        case 'D':
        case 'd':
            // Saber cuántas estaciones tiene una línea dada
            std::cout << "Ingrese el nombre de la linea: ";
            cout<<endl;
            cout<<endl;
            std::cin >> nombreLinea;
            std::cout << "La linea " << nombreLinea << " tiene " << redMetro.obtenerNumEstacionesEnLinea(nombreLinea) << " estaciones." << std::endl;
            cout<<endl;
            cout<<endl;
            break;
        case 'E':
        case 'e':
            // Saber si una estación dada pertenece a una línea específica
            std::cout << "Ingrese el nombre de la estacion: ";
            std::cin >> nombreEstacion;
            std::cout << "Ingrese el nombre de la linea: ";
            std::cin >> nombreLinea;
            if (redMetro.contieneEstacionEnLinea(nombreLinea, nombreEstacion)) {
                std::cout << "La estacion " << nombreEstacion << " pertenece a la linea " << nombreLinea << "." << std::endl;
                cout<<endl;
                cout<<endl;
            } else {
                std::cout << "La estacion " << nombreEstacion << " no pertenece a la linea " << nombreLinea << "." << std::endl;
                cout<<endl;
                cout<<endl;
            }
            break;
        case 'F':
        case 'f':
            // Agregar una línea a la red Metro
            std::cout << "Ingrese el nombre de la linea: ";
            cout<<endl;
            cout<<endl;
            std::cin >> nombreLinea;
            redMetro.agregarLinea(nombreLinea);
            cout<<endl;
            cout<<endl;
            break;
        case 'G':
        case 'g':            //SOLAMENTE SE PUEDE BORRAR UNA LINEA SI NO CONTIENE ESTACIONES DE TRANSFERENCIA
            // Eliminar una línea de la red Metro
            std::cout << "Ingrese el nombre de la linea que desea eliminar: ";
            std::cin >> nombreLinea;
            if (redMetro.eliminarLinea(nombreLinea)) {
                std::cout << "Línea eliminada exitosamente de la red Metro." << std::endl;
                cout<<endl;
                cout<<endl;
            } else {
                std::cerr << "Error: La línea especificada no existe." << std::endl;
                cout<<endl;
                cout<<endl;
            }
            break;   //Con el arreglo estacionesTransf, corroborar cuantas estaciones de transferencia hay en la linea

        case 'H':
        case 'h':
            // Saber cuántas estaciones tiene la red Metro
            std::cout << "La red Metro tiene " << redMetro.obtenerNumEstacionesRed() << " estaciones." << std::endl;
            cout<<endl;
            cout<<endl;
            break;
        case 'J':
        case 'j':
            // Calcular tiempo entre estaciones
            std::cout << "Ingrese el nombre de la linea: ";
            std::cin >> nombreLinea;
            std::cout << "Ingrese el nombre de la estacion de inicio: ";
            std::cin >> nombreEstacion;
            std::cout << "Ingrese el nombre de la estacion de fin: ";
            std::cin >> nombreEstacionFin;
            for (int i = 0; i < redMetro.obtenerNumLineas(); ++i) {
                if (redMetro.obtenerNombreLinea(i) == nombreLinea) {
                    int tiempo = redMetro.obtenerLineaMetro(i)->obtenerTiempoEntreEstaciones(nombreEstacion, nombreEstacionFin);
                    if (tiempo != -1) {
                        std::cout << "El tiempo entre las estaciones " << nombreEstacion << " y " << nombreEstacionFin << " es: " << tiempo << " minutos." << std::endl;
                        cout<<endl;
                        cout<<endl;
                    }
                    break;
                }
            }
            break;
        case 'K':
        case 'k':
            // Mostrar estaciones de transferencia de la red Metro
            redMetro.imprimirEstacionesTransferencia();
            cout<<endl;
            cout<<endl;
            break;
        case 'X':
        case 'x':
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
        case 'i':
            redMetro.graficarRed();
            cout<<endl;
            cout<<endl;
            break;

        }

    } while (opcion != 'X');

    return 0;
}
