#include <iostream>
#include <memory>   // unique_ptr, shared_ptr, make_unique, make_shared
using namespace std;

class Punto {
public:
    Punto(int x, int y) : x(x), y(y) {
        cout << "  Punto(" << x << "," << y << ") creado\n";
    }
    ~Punto() {
        cout << "  Punto(" << x << "," << y << ") destruido\n";
    }
    int getX() const { return x; }
private:
    int x, y;
};

int main() {
    cout << "1) unique_ptr creado con make_unique (sin new a la vista):\n";
    unique_ptr<Punto> p = make_unique<Punto>(10, 20);
    cout << "   p->getX() = " << p->getX() << "\n";

    cout << "2) unique_ptr NO se copia, solo se MUEVE:\n";
    unique_ptr<Punto> q = move(p);       // p transfiere la propiedad a q
    cout << "   despues del move: p=" << (p ? "valido" : "nullptr")
         << " | q->getX()=" << q->getX() << "\n";

    cout << "3) fin del main: los unique_ptr mueren y liberan SOLOS\n";
    return 0;
}   // <-- aqui q muere y hace delete automaticamente