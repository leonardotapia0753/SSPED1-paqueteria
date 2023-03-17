#ifndef ARREGLO_HPP
#define ARREGLO_HPP

#include <iostream>
#include <stdexcept>

#define INCREMENTO 5

using namespace std;

template <class T>
class Arreglo
{
private:
    T* datos;
    size_t cont;
    size_t tam;

public:
    Arreglo();
    Arreglo(const Arreglo<T>&);
    ~Arreglo();

    bool estaLlena() const;
    bool estaVacia() const;

    size_t cantidad() const;
    size_t capacidad() const;

    void expandir();
    void encoger();

    void agregarInicio(const T  elemento);
    void agregarFinal(const T  elemento);
    void insertar(const size_t pos, const T  elemento);

    void eliminarInicio();
    void eliminarFinal();
    void eliminar(const size_t pos);

    T& operator[](size_t pos);
    const T& operator[](size_t pos) const;

    const Arreglo<T>& operator=(const Arreglo<T>&);
};

template <class T>
Arreglo<T>::Arreglo()
{
    cont = 0;
    tam = INCREMENTO; 
    datos = new T[tam];
}

template <class T>
Arreglo<T>::Arreglo(const Arreglo<T>& arreglo)
{
    cout << "Constructor copia" << endl;
    T* aux = new T[arreglo.tam];

    for (size_t i = 0; i < arreglo.cont; i++)
    {
        aux[i] = arreglo.datos[i];
    }

    datos = aux;

    cont = arreglo.cont;
    tam = arreglo.tam;
}

template <class T>
Arreglo<T>::~Arreglo() 
{
    cout << "Liberando memoria..." << endl;
    delete[] datos;
}

template <class T>
bool Arreglo<T>::estaLlena() const
{
    return cont == tam;
}

template <class T>
bool Arreglo<T>::estaVacia() const
{
    return cont == 0;
}

template <class T>
size_t Arreglo<T>::cantidad() const
{
    return cont;
}

template <class T>
size_t Arreglo<T>::capacidad() const
{
    return tam;
}

template <class T>
void Arreglo<T>::expandir()
{
    T* aux = new T[tam + INCREMENTO];

    for (size_t i = 0; i < cont; i++)
    {
        aux[i] = datos[i];
    }

    delete[] datos;

    datos = aux;

    tam = tam + INCREMENTO;

    cout << endl << "Capacidad del arreglo: " << tam << endl;
    cout << "Cantidad de elementos almacenados: " << cont << endl << endl;
}

template <class T>
void Arreglo<T>::encoger()
{
    if (estaVacia())
    {
        cout << "No es posible encoger. Arreglo vacío." << endl;
        return;
    }
    else if (estaLlena())
    {
        cout << "No es posible encoger. Arreglo lleno." << endl;
        return;
    }

    T* aux = new T[cont];

    for (size_t i = 0; i < cont; i++)
    {
        aux[i] = datos[i];
    }

    delete[] datos;

    datos = aux;

    tam = cont;

    cout << endl << "Capacidad del arreglo: " << tam << endl;
    cout << "Cantidad de elementos almacenados: " << cont << endl << endl;
}

template <class T>
void Arreglo<T>::agregarInicio(const T  elemento)
{
    if (estaLlena())
        expandir();

    for (size_t i = cont; i > 0; i--)
        datos[i] = datos[i - 1];

    datos[0] = elemento;
    cont++;
}

template <class T>
void Arreglo<T>::agregarFinal(const T  elemento)
{
    if (estaLlena())
        expandir();

    datos[cont] = elemento;
    cont++;
}

template <class T>
void Arreglo<T>::insertar(const size_t pos, const T  elemento)
{
    if (estaLlena())
        expandir();

    if (pos > cont)
    {
        cout << "Posición no válida" << endl;
        return;
    }

    for (size_t i = cont; i > pos; i--)
        datos[i] = datos[i - 1];

    datos[pos] = elemento;
    cont++;
}

template <class T>
void Arreglo<T>::eliminarInicio()
{
    if (estaVacia())
    {
        cout << "Arreglo vacío" << endl;
        return;
    }

    for (size_t i = 0; i < cont - 1; i++)
        datos[i] = datos[i + 1];

    cont--;
}

template <class T>
void Arreglo<T>::eliminarFinal()
{
    if (estaVacia())
    {
        cout << "Arreglo vacío" << endl;
        return;
    }

    cont--;
}

template <class T>
void Arreglo<T>::eliminar(const size_t pos)
{
    if (estaVacia())
    {
        cout << "Arreglo vacío" << endl;
        return;
    }

    for (size_t i = pos; i < cont - 1; i++)
        datos[i] = datos[i + 1];

    cont--;
}

template <class T>
T& Arreglo<T>::operator[](size_t pos)
{
    if (pos >= cont)
        throw out_of_range("Posición no válida");

    return datos[pos];
}

template <class T>
const T& Arreglo<T>::operator[](size_t pos) const
{
    if (pos >= cont)
        throw out_of_range("Posición no válida");

    return datos[pos];
}

template <class T>
const Arreglo<T>& Arreglo<T>::operator=(const Arreglo<T>& arreglo)
{
    cout << "Operador de asignación" << endl;


    T* aux = new T[arreglo.tam];

    for (size_t i = 0; i < arreglo.cont; i++)
    {
        aux[i] = arreglo.datos[i];
    }

    delete[] datos;

    datos = aux;

    cont = arreglo.cont;
    tam = arreglo.tam;

    return *this;
}

#endif
