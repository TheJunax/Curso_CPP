#include <iostream>
#include <string>
using namespace std;

class CuentaBancaria {
public:
    CuentaBancaria(string titular, double saldo)
        : titular(titular), saldo(saldo) {}

    void mostrar() const {
        cout << titular << " $" << saldo;
    }

protected:
    string titular;
    double saldo;
};

class CuentaAhorros : public CuentaBancaria {
public:
    CuentaAhorros(string titular, double saldo, double tasa)
        : CuentaBancaria(titular, saldo), tasaInteres(tasa) {}

    double getTasa() const { return tasaInteres; }

private:
    double tasaInteres;
};

// POR VALOR: recibe una COPIA... y solo copia la parte CuentaBancaria
void imprimirPorValor(CuentaBancaria c) {
    cout << "(por valor) ";
    c.mostrar();
    cout << " | tamano aqui: " << sizeof(c) << "\n";
}

// POR REFERENCIA const: NO copia, el objeto llega completo
void imprimirPorRef(const CuentaBancaria& c) {
    cout << "(por ref)   ";
    c.mostrar();
    cout << "\n";
}

int main() {
    CuentaAhorros nu("Maria", 340000, 0.3);
    cout << "tamano real de CuentaAhorros: " << sizeof(nu) << "\n";

    imprimirPorValor(nu);   // SLICING: la copia pierde tasaInteres
    imprimirPorRef(nu);     // sin corte: es la misma Maria completa

    return 0;
}