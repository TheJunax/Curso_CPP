#include <iostream>
#include <string>


class CuentaBancaria{
public:
    CuentaBancaria(std::string titular, double saldo):
    titular(titular), saldo(saldo) {}

    void depositar(int monto) {
        saldo += monto;
    }
    void mostrar(){
        std::cout << "Titular: " << titular << "  Saldo: " << saldo ;
    }
protected:
    std::string titular; 
    double saldo; 
    
};

class CuentaAhorros : public CuentaBancaria{
public:
    CuentaAhorros(std::string titular, double saldo,double tasaInteres) :
        CuentaBancaria(titular, saldo), tasaInteres(tasaInteres){}

    void aplicarInteres(){
        saldo = (saldo*tasaInteres) + saldo;
    }

private:
double tasaInteres;
};

int main(){
    CuentaBancaria MC("Juan", 153000);
    MC.mostrar();
    MC.depositar(200000);
    std::cout << "\n";

    MC.mostrar(); 
    std::cout << "\n";

    CuentaAhorros Nu("Maria", 340000, 0.3);
    Nu.mostrar();
    Nu.aplicarInteres();
    std::cout << "\n";

    Nu.mostrar();
    std::cout << "\n";

}