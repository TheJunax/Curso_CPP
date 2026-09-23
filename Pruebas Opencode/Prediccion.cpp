#include <iostream>
using namespace std;

class Complejos {
public:
    Complejos(double a, double bi) : a(a), bi(bi) {
        cout << "  [constructor normal]\n";
    }

    Complejos(const Complejos& otro) : a(otro.a), bi(otro.bi) {
        cout << "  [constructor de copia]\n";
    }

    Complejos& operator=(const Complejos& otro) {
        cout << "  [operator= asignacion]\n";
        a = otro.a;
        bi = otro.bi;
        return *this;
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
    Complejos x(3, 4);
    cout << "--- A: Complejos y = x;\n";
    Complejos y = x;              // A

    cout << "--- B: Complejos z(y);\n";
    Complejos z(y);               // B

    cout << "--- C: w = x; (w ya existia)\n";
    Complejos w(1, 1);
    w = x;                        // C

    cout << "--- D: w = y = z;\n";
    w = y = z;                    // D

    cout << "Resultado: " << w << " / " << y << "\n";
    return 0;
}