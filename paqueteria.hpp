#ifndef PAQUETERIA_HPP
#define PAQUETERIA_HPP


#include <iostream>
#include <iomanip>
#include <fstream>

#include "paquete.hpp"

#define MAX 5

using namespace std;

class Paqueteria
{
private:
    Paquete paquetes[MAX];
    size_t cont;

public:
    Paqueteria();
    ~Paqueteria();

    bool estaLlena() const;
    bool estaVacia() const;

    void agregarInicio(const Paquete &paquete);
    void agregarFinal(const Paquete &paquete);
    void insertar(const size_t pos, const Paquete &paquete);

    void eliminarInicio();
    void eliminarFinal();
    void eliminar(const size_t pos);

    void mostrar() const;
    void mostrarTabla() const;

    void respaldar() const;
    void respaldarTabla() const;
    void respaldarCSV() const;

    void recuperarCSV();
};

Paqueteria::Paqueteria()
{
    cont = 0;
}

Paqueteria::~Paqueteria() {}

bool Paqueteria::estaLlena() const
{
    return cont == MAX;
}

bool Paqueteria::estaVacia() const
{
    return cont == 0;
}

void Paqueteria::agregarInicio(const Paquete &paquete)
{
    if (estaLlena())
    {
        cout << endl << "Paqueteria Llena" << endl;
        return;
    }

    for (size_t i = cont; i > 0; i--)
        paquetes[i] = paquetes[i - 1];

    paquetes[0] = paquete;
    cont++;
}

void Paqueteria::agregarFinal(const Paquete &paquete)
{
    if (estaLlena())
    {
        cout << endl << "Paqueteria Llena" << endl;
        return;
    }

    paquetes[cont] = paquete;
    cont++;
}

void Paqueteria::insertar(const size_t pos, const Paquete &paquete)
{
    if (estaLlena())
    {
        cout << endl << "Paqueteria Llena" << endl;
        return;
    }

    if (pos > cont)
    {
        cout << endl << "Posición no válida" << endl;
        return;
    }

    for (size_t i = cont; i > pos; i--)
        paquetes[i] = paquetes[i - 1];

    paquetes[pos] = paquete;
    cont++;
}

void Paqueteria::eliminarInicio()
{
    if (estaVacia())
    {
        cout << endl << "Paqueteria Vacia" << endl;
        return;
    }

    for (size_t i = 0; i < cont - 1; i++)
        paquetes[i] = paquetes[i + 1];

    cont--;
}

void Paqueteria::eliminarFinal()
{
    if (estaVacia())
    {
        cout << "Paqueteria Vacia" << endl;
        return;
    }

    cont--;
}

void Paqueteria::eliminar(const size_t pos)
{
    if (estaVacia())
    {
        cout << "Paqueteria Vacia" << endl;
        return;
    }

    for (size_t i = pos; i < cont - 1; i++)
        paquetes[i] = paquetes[i + 1];

    cont--;
}

void Paqueteria::mostrar() const
{
    for (size_t i = 0; i < cont; i++)
    {
        const Paquete &paquete = paquetes[i];

        cout << "Paquete[" << i << "]:" << endl;
        cout << "\tOrigen: " << paquete.getOrigen() << endl;
        cout << "\tDestino: " << paquete.getDestino() << endl;
        cout << "\tDestinatario: " << paquete.getDestinatario() << endl;
        cout << "\tPeso: " << paquete.getPeso() << endl
             << endl;
    }
}

void Paqueteria::mostrarTabla() const
{
    cout << left;
    cout << setw(10) << "Origen" << "|";
    cout << setw(10) << "Destino" << "|";
    cout << setw(15) << "Destinatario" << "|";
    cout << setw(5) << "Peso" << "|" << endl;

    for (size_t i = 0; i < cont; i++)
    {
        const Paquete &paquete = paquetes[i];

        cout << left;
        cout << setw(10) << paquete.getOrigen() << "|";
        cout << setw(10) << paquete.getDestino() << "|";
        cout << setw(15) << paquete.getDestinatario() << "|";
        cout << setw(5) << right << paquete.getPeso() << "|" << endl;
    }
}

void Paqueteria::respaldar() const
{
    ofstream archivo("paqueteria.txt");

    if (archivo.fail())
    {
        cout << "Error al crear el archivo." << endl;

        return;
    }

    for (size_t i = 0; i < cont; i++)
    {
        const Paquete &paquete = paquetes[i];

        archivo << "Paquete[" << i << "]:" << endl;
        archivo << "\tOrigen: " << paquete.getOrigen() << endl;
        archivo << "\tDestino: " << paquete.getDestino() << endl;
        archivo << "\tDestinatario: " << paquete.getDestinatario() << endl;
        archivo << "\tPeso: " << paquete.getPeso() << endl
                << endl;
    }

    archivo.close();
}

void Paqueteria::respaldarTabla() const
{
    ofstream archivo("paqueteria_tabla.txt");

    if (archivo.fail())
    {
        cout << "Error al crear el archivo." << endl;

        return;
    }

    archivo << left;
    archivo << setw(10) << "Origen" << "|";
    archivo << setw(10) << "Destino" << "|";
    archivo << setw(15) << "Destinatario" << "|";
    archivo << setw(5) << "Peso" << "|" << endl;

    for (size_t i = 0; i < cont; i++)
    {
        const Paquete &paquete = paquetes[i];

        archivo << left;
        archivo << setw(10) << paquete.getOrigen() << "|";
        archivo << setw(10) << paquete.getDestino() << "|";
        archivo << setw(15) << paquete.getDestinatario() << "|";
        archivo << setw(5) << right << paquete.getPeso() << "|" << endl;
    }

    archivo.close();
}

void Paqueteria::respaldarCSV() const
{
    ofstream archivo("paqueteria.csv");

    if (archivo.fail())
    {
        cout << "Error al crear el archivo." << endl;

        return;
    }

    archivo << left;
    archivo << "Origen" << ",";
    archivo << "Destino" << ",";
    archivo << "Destinatatio" << ",";
    archivo << "Peso" << endl;

    for (size_t i = 0; i < cont; i++)
    {
        const Paquete &paquete = paquetes[i];

        archivo << paquete.getOrigen() << ",";
        archivo << paquete.getDestino() << ",";
        archivo << paquete.getDestinatario() << ",";
        archivo << paquete.getPeso() << endl;
    }

    archivo.close();
}

void Paqueteria::recuperarCSV()
{
    ifstream archivo("paqueteria.csv");

    if (archivo.fail())
    {
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    string origen, destino, destinatario, peso;
    string headers;

    getline(archivo, headers);

    while (true)
    {
        getline(archivo, origen, ',');
        if (archivo.eof())
            break;
        getline(archivo, destino, ',');
        getline(archivo, destinatario, ',');
        getline(archivo, peso);

        Paquete paquete;
        paquete.setOrigen(origen);
        paquete.setDestino(destino);
        paquete.setDestinatario(destinatario);
        paquete.setPeso(stod(peso));

        agregarFinal(paquete);
    }

    archivo.close();
}

#endif