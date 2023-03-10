#ifndef PAQUETE_H
#define PAQUETE_H

#include <string>

using std::string;
using std::istream;
using std::cin;
using std::cout;

class Paquete
{
    private:
        string origen;
        string destino;
        string destinatario;
        double peso;
    
    public:
        // Constructor
        Paquete() {}
        Paquete(const string& origen, 
                const string& destino, 
                const string& destinatario, 
                double peso) {
            // Diferenciar atributo y parámetro del constructor
            // Paquete::origen = origen;
            this->origen = origen;
            this->destino = destino;
            this->destinatario = destinatario;
            this->peso = peso;
        }

        // Métodos de acceso
        void setOrigen(const string& valor) {
            origen = valor;
        }
        string getOrigen() {
            return origen;
        }
        void setDestino(const string& valor) {
            destino = valor;
        }
        string getDestino() {
            return destino;
        }
        void setDestinatario(const string& valor) {
            destinatario = valor;
        }
        string getDestinatario() {
            return destinatario;
        }
        void setPeso(double valor) {
            peso = valor;
        }
        double getPeso() {
            return peso;
        }

        friend istream& operator>>(istream& is, Paquete& paquete) {
            cout << "Origen: ";
            cin >> paquete.origen;
            cout << "Destino: ";
            cin >> paquete.destino;
            cout << "Destinatario: ";
            cin >> paquete.destinatario;
            cout << "Peso: ";
            cin >> paquete.peso;
            
            return is;
        }
};

#endif
