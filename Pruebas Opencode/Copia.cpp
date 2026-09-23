#include <iostream>
using namespace std;

class Complejos {
public:
    Complejos(double a, double bi) : a(a), bi(bi) {
        cout << "Constructor normal\n";
    }

    // Constructor de copia: se llama al NACER copiando de otro
    Complejos(const Complejos& otro) : a(otro.a), bi(otro.bi) {
        cout << "Constructor de copia\n";
    }

    // Operador de asignacion: se llama cuando YA EXISTE y copian encima
    Complejos& operator=(const Complejos& otro) {
        cout << "operator= (asignacion)\n";
        a = otro.a;
        bi = otro.bi;
        return *this;   // para poder encadenar: x = y = z
    }

    friend ostream& operator<<(ostream& os, const Complejos& c);

private:
    double a, bi;
};

ostream& operator<<(ostream& os, const Complejos& c) {
    os << c.a << " + " << c.bi << "i";
    return os;
}

int main() {
    Complejos a(5, 7);

    cout << "--- b nace copiando de a ---\n";
    Complejos b = a;          // NACER copiando -> constructor de copia

    cout << "--- c nace copiando de a (forma larga) ---\n";
    Complejos c(a);           // NACER copiando -> constructor de copia

    cout << "--- b ya existia, le copian encima ---\n";
    b = c;                    // YA EXISTE -> operator=

    cout << "--- b y c: " << b << " / " << c << "\n";
    return 0;
}