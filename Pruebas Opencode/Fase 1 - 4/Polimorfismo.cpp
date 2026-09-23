#include <iostream>
using namespace std;

class Figura {
public:
    virtual double area() const {   // LA PALABRA MAGICA: virtual
        cout << "[Figura generica] ";
        return 0;
    }
    // Destructor virtual: clave cuando hay herencia (lo vemos ya)
    virtual ~Figura() = default;
};

class Circulo : public Figura {
public:
    Circulo(double r) : r(r) {}
    double area() const override {
        cout << "[Circulo] ";
        return 3.1416 * r * r;
    }
private:
    double r;
};

class Rectangulo : public Figura {
public:
    Rectangulo(double b, double h) : b(b), h(h) {}
    double area() const override {
        cout << "[Rectangulo] ";
        return b * h;
    }
private:
    double b, h;
};

int main() {
    Circulo c(2.0);
    Rectangulo r(3.0, 4.0);

    Figura* figuras[] = { &c, &r };

    cout << "--- CON virtual (despacho dinamico) ---\n";
    for (auto* f : figuras)
        cout << "area: " << f->area() << "\n";
    //  ^ f es Figura*, pero ahora SI consulta al objeto real detras

    return 0;
}