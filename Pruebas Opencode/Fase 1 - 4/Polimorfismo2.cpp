#include <iostream>
using namespace std;

class Figura {
public:
    virtual double area() const = 0;
    virtual ~Figura() = default;
};

class Circulo : public Figura {
public:
    Circulo(double r) : r(r) {}
    double area() const override {
        cout << "    Soy un Circulo en la direccion " << (void*)this << ": ";
        return 3.1416 * r * r;
    }
private:
    double r;
};

class Rectangulo : public Figura {
public:
    Rectangulo(double b, double h) : b(b), h(h) {}
    double area() const override {
        cout << "    Soy un Rectangulo en la direccion " << (void*)this << ": ";
        return b * h;
    }
private:
    double b, h;
};

int main() {
    Circulo c(2.0);
    Rectangulo r(3.0, 4.0);

    cout << "Direccion real de los objetos:\n";
    cout << "  Circulo c   -> " << (void*)&c << "\n";
    cout << "  Rectangulo r-> " << (void*)&r << "\n\n";

    Figura* f = &c;   // f guarda la direccion de c
    Figura* g = &r;   // g guarda la direccion de r

    cout << "f apunta a " << (void*)f << " -> llamo f->area():\n";
    cout << "    resultado: " << f->area() << "\n\n";

    cout << "g apunta a " << (void*)g << " -> llamo g->area():\n";
    cout << "    resultado: " << g->area() << "\n\n";

    return 0;
}