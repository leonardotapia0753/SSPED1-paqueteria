#ifndef MENU_HPP
#define MENU_HPP

#include "paqueteria.hpp"
#include "arreglo.hpp"

void menu_paqueteria(Paqueteria& paqueteria)
{
    while (true) {
        cout << "Menu de Paquetería: " << paqueteria.getNombre() << endl;
        cout << "1.  Agregar Paquete al Inicio" << endl;
        cout << "2.  Agregar Paquete al Final" << endl;
        cout << "3.  Insertar Paquete" << endl;
        cout << "4.  Mostrar Paquetes" << endl;
        cout << "5.  Mostrar Tabla" << endl;
        cout << "6.  Eliminar Paquete" << endl;
        cout << "7.  Eliminar Paquete al Inicio" << endl;
        cout << "8.  Eliminar Paquete al Final" << endl;
        cout << "9.  Respaldar" << endl;
        cout << "10. Respaldar Tabla" << endl;
        cout << "11. Respaldar CSV" << endl;
        cout << "12. Recuperar" << endl;
        cout << "13. Encoger" << endl;
        cout << "0.  Salir" << endl;
        cout << "Escoge una opción: ";

        string op;
        cin >> op;
        cin.ignore();

        cout << endl;

        if (op == "1") {
            Paquete paquete;

            cin >> paquete;
            paqueteria.agregarInicio(paquete);
        }

        else if (op == "2") {
            Paquete paquete;

            cin >> paquete;
            paqueteria.agregarFinal(paquete);
        }

        else if (op == "3") {
            Paquete paquete;
            size_t pos;

            cout << "Ingresa la posición de inserción: ";
            cin >> pos;
            cin.ignore();
            cin >> paquete;
            paqueteria.insertar(pos, paquete);
        }

        else if (op == "4") {
            paqueteria.mostrar();
        }

        else if (op == "5") {
            paqueteria.mostrarTabla();
        }

        else if (op == "6") {
            paqueteria.eliminarInicio();
        }

        else if (op == "7") {
            paqueteria.eliminarFinal();
        }

        else if (op == "8") {
            paqueteria.respaldar();
        }

        else if (op == "9") {
            paqueteria.respaldarTabla();
        }

        else if (op == "10") {
            paqueteria.respaldarCSV();
        }

        else if (op == "11") {
            paqueteria.recuperarCSV();
        }

        else if (op == "12") {
            paqueteria.encoger();
        }

        else if (op == "0") {
            break;
        }

        cout << endl;
    }
} 

void menu() {

    Arreglo<Paqueteria> paqueterias;

    while (true) {
        cout << "Menú de Paqueterías." << endl;
        cout << "1. Crear Paquetería" << endl;
        cout << "2. Eliminar Paquetería" << endl;
        cout << "3. Buscar Paquetería" << endl;
        cout << "0. Salir" << endl;
        cout << "Escoge una opción: ";

        string op;

        cin >> op;
        cin.ignore();

        cout << endl;

        if (op == "1") {
            string nombre;
            cout << "Nombre de paquetería: ";
            getline(cin, nombre);
            cout << endl;

            Paqueteria paqueteria;
            paqueteria.setNombre(nombre);
            
            paqueterias.agregarFinal(paqueteria);
        }

        else if (op == "2") {
            size_t posicion;

            cout << "Posición a eliminar: ";
            cin >> posicion;
            cin.ignore();

            paqueterias.eliminar(posicion);
        }

        else if (op == "3") {
            string nombre;
            cout << "Nombre de la paquetería: ";
            getline(cin, nombre);
            cout << endl;

            for (size_t i = 0; i < paqueterias.cantidad(); i++)
            {
                if (nombre == paqueterias[i].getNombre()) {
                    menu_paqueteria(paqueterias[i]);
                    break;
                }
            }
        }

        else if (op == "0") {
            break;
        }

        else {
            cout << "Opción no valida. Intenta de nuevo.";
        }

        cout << endl;
    }
}

#endif