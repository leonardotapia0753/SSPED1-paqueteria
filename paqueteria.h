#ifndef PAQUETERIA_H
#define PAQUETERIA_H

#include "paquete.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::left;
using std::right;

class Paqueteria
{
    private:
        Paquete paquetes[5];
        size_t cont;
    public:
        Paqueteria();
        ~Paqueteria();

        void agregar(const Paquete& paquete);
        void mostrar();
        void mostrarTabla();
};

Paqueteria::Paqueteria() 
{
    cont = 0;
}

Paqueteria::~Paqueteria() {}

void Paqueteria::agregar(const Paquete& paquete)
{
    if (cont >= 5) {
        cout << "Paqueteria llena" << endl;
        return;
    }

    paquetes[cont] = paquete;
    cont++;
}

void Paqueteria::mostrar()
{
    for (size_t i = 0; i < cont; i++) {
        Paquete& paquete = paquetes[i];

        cout << "Paquete[" << i << "]:" << endl;
        cout << "\tOrigen: " << paquete.getOrigen() << endl;
        cout << "\tDestino: " << paquete.getDestino() << endl;
        cout << "\tDestinatario: " << paquete.getDestinatario() << endl;
        cout << "\tPeso: " << paquete.getPeso() << endl << endl;
    }
}

void Paqueteria::mostrarTabla()
{
    cout << left;
    cout << setw(10) << "Origen" << "|";
    cout << setw(10) << "Destino" << "|";
    cout << setw(15) << "Destinatario" << "|";
    cout << setw(5) << "Peso" << "|" << endl;

    for (size_t i = 0; i < cont; i++) {
        Paquete& paquete = paquetes[i];

        cout << left;
        cout << setw(10) << paquete.getOrigen() << "|" ;
        cout << setw(10) << paquete.getDestino() << "|";
        cout << setw(15) << paquete.getDestinatario() << "|";
        cout << setw(5) << right << paquete.getPeso() << "|" << endl;
    }
}

#endif
