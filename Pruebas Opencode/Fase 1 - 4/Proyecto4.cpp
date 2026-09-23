#include <iostream>
#include <vector>

using namespace std;

class Figura {
public:
    virtual double area() const =0;
    virtual double perimetro() const =0;
    virtual ~Figura() = default;
};

class Circulo : public Figura {
public:
    Circulo(double r) : r(r) {}
    double area() const override {
        cout << "Area Circulo: ";
        return 3.1416 * r * r;
    }
    double perimetro() const override{
        cout << "Perimetro Circulo: ";
        return 2 * 3.1416 * r;
    }
private:
    double r;
};

class Rectangulo : public Figura {
public:
    Rectangulo(double b, double h) : b(b), h(h) {}
    double area() const override {
        cout << "Area Rectangulo: ";
        return b * h;
    }
    double perimetro() const override{
        cout << "Perimetro Rectangulo: ";
        return 2 *(b+h);
    }
private:
    double b, h;
};

int main(){
    Circulo c(2.0);
    Rectangulo r(3,4);

    Figura* figuras[] = { &c, &r };
    for (auto* f : figuras)
        cout << f->area() << "\n" << f->perimetro() << "\n";
}