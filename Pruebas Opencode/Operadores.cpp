#include <iostream>
using namespace std;

class Punto {
public:
    Punto(int x, int y) : x(x), y(y) {}

    // Sobrecarga de operator+ como METODO MIEMBRO:
    // p1 + p2  ->  p1.operator+(p2)
    Punto operator+(const Punto& otro) const {
        return Punto(x + otro.x, y + otro.y);
    }

    // Sobrecarga de operator==
    // p1 == p2  ->  p1.operator==(p2)
    bool operator==(const Punto& otro) const {
        return x == otro.x && y == otro.y;
    }

    // Getter para poder imprimir desde afuera
    int getX() const { return x; }
    int getY() const { return y; }

private:
    int x, y;
};

int main() {
    Punto a(2, 3);
    Punto b(4, 5);

    Punto c = a + b;   // el compilador lo traduce: a.operator+(b)
    cout << "c = (" << c.getX() << ", " << c.getY() << ")\n";

    if (a == b)
        cout << "a y b son iguales\n";
    else
        cout << "a y b son distintos\n";

    return 0;
}