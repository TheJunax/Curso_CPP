#include <iostream>
#include <string>

class CuentaBancaria{
    private:
        double saldo;
    public:
        double depositar(double valor){
            saldo += valor;
            return saldo;
        }
        double retirar(double valor){
            if(valor > saldo){
                std::cout << "No hay saldo suficiente \n";
                return 0;
            }
            saldo -= valor;
            std::cout << "Retiro Exitoso\n";
            return saldo;
        }
};

class Persona{
    private:
        std::string nombre;
        int edad;
    public:
    void establecerDatos(std::string nombre, int edad){   // SIN const: modifica
        this->nombre = nombre;
        this->edad   = edad;
    }
    void mostrarDatos() const{                            // CON const: solo lee
        std::cout << "Nombre: " << this->nombre << " Edad: " << this->edad;
    }
};

int main(){
    Persona p;
    p.establecerDatos("Maria", 25);
    p.mostrarDatos();
    return 0;
}