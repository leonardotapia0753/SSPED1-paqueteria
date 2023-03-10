#ifndef MENU_H
#define MENU_H

#include "paqueteria.h"

void menu(Paqueteria& paqueteria)
{
    int op;

    while (true) {
        cout << "Menu Principal" << endl;
        cout << "1. Agregar Paquete" << endl;
        cout << "2. Mostrar Paquetes" << endl;
        cout << "3. Mostrar Tabla" << endl;
        cout << "0. Salir" << endl;
        cout << "Escoge una opcion: ";
        cin >> op;
        cout << endl;

        if (op == 1) {
            Paquete paquete;

            cin >> paquete;
            paqueteria.agregar(paquete);
        }

        if (op == 2) {
            paqueteria.mostrar();
        }

        if (op == 3) {
            paqueteria.mostrarTabla();
        }

        if (op == 0) {
            break;
        }

        cout << endl;
    }
} 

#endif
