#ifndef PAQUETE_HPP
#define PAQUETE_HPP

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
        string getOrigen() const{
            return origen;
        }
        void setDestino(const string& valor) {
            destino = valor;
        }
        string getDestino() const{
            return destino;
        }
        void setDestinatario(const string& valor) {
            destinatario = valor;
        }
        string getDestinatario() const{
            return destinatario;
        }
        void setPeso(double valor) {
            peso = valor;
        }
        double getPeso() const{
            return peso;
        }

        friend istream& operator>>(istream& is, Paquete& paquete) {
            cout << "Origen: ";
            getline(cin, paquete.origen);
            cout << "Destino: ";
            getline(cin, paquete.destino);
            cout << "Destinatario: ";
            getline(cin, paquete.destinatario);
            cout << "Peso: ";
            cin >> paquete.peso;
            
            return is;
        }
};

#endif