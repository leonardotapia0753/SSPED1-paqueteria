#ifndef MENU_HPP
#define MENU_HPP

#include "paqueteria.hpp"

enum OPCS_MENU {SALIR = 0, 
                AGREGAR_INICIO, 
                AGREGAR_FINAL,
                INSERTAR,
                MOSTRAR_PAQUETES, 
                MOSTRAR_TABLA,
                ELIMINAR,
                ELIMINAR_INICIO,
                ELIMINAR_FINAL,
                RESPALDAR,
                RESPALDAR_TABLA,
                RESPALDAR_CSV,
                RECUPERAR};

void menu(Paqueteria& paqueteria)
{
    int op;

    while (true) {
        cout << "Menu Principal" << endl;
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
        cout << "0.  Salir" << endl;
        cout << "Escoge una opcion: ";
        cin >> op;
        cin.ignore();
        cout << endl;

        if (op == AGREGAR_INICIO) {
            Paquete paquete;

            cin >> paquete;
            paqueteria.agregarInicio(paquete);
        }

        else if (op == AGREGAR_FINAL) {
            Paquete paquete;

            cin >> paquete;
            paqueteria.agregarFinal(paquete);
        }

        else if (op == INSERTAR) {
            Paquete paquete;
            size_t pos;

            cout << "Ingresa la posicion de insercion: ";
            cin >> pos;
            cin.ignore();
            cin >> paquete;
            paqueteria.insertar(pos, paquete);
        }

        else if (op == MOSTRAR_PAQUETES) {
            paqueteria.mostrar();
        }

        else if (op == MOSTRAR_TABLA) {
            paqueteria.mostrarTabla();
        }

        else if (op == ELIMINAR) {
            size_t pos;

            cout << "Ingresa la posición del paquete a eliminar: ";
            cin >> pos;
            cin.ignore();
            paqueteria.eliminar(pos);
        }

        else if (op == ELIMINAR_INICIO) {
            paqueteria.eliminarInicio();
        }

        else if (op == ELIMINAR_FINAL) {
            paqueteria.eliminarFinal();
        }

        else if (op == RESPALDAR) {
            paqueteria.respaldar();
        }

        else if (op == RESPALDAR_TABLA) {
            paqueteria.respaldarTabla();
        }

        else if (op == RESPALDAR_CSV) {
            paqueteria.respaldarCSV();
        }

        else if (op == RECUPERAR) {
            paqueteria.recuperarCSV();
        }

        else if (op == SALIR) {
            break;
        }

        cout << endl;
    }
} 

#endif