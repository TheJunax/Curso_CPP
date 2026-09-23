#include <iostream>
#include <string>
using namespace std;

class Empleado {
public:
    Empleado(string nombre, double salario)
        : nombre(nombre), salario(salario) {}

    void mostrar() const {
        cout << nombre << " gana $" << salario << "\n";
    }

protected:   // privado pa' afuera, pero visible pa' las derivadas
    string nombre;
    double salario;
};

class Gerente : public Empleado {
public:
    // El constructor del Gerente INICIALIZA a su base en la lista:
    Gerente(string nombre, double salario, double bono)
        : Empleado(nombre, salario), bono(bono) {}

    void mostrarBono() const {
        cout << "Bono de " << bono << "\n";
        // puede tocar nombre y salario: son protected, heredados
        cout << "Gerente: " << nombre << "\n";
    }

private:
    double bono;
};

int main() {
    Empleado e("Maria", 2000);
    e.mostrar();

    Gerente g("Juan", 5000, 1500);
    g.mostrar();        // metodo heredado de Empleado
    g.mostrarBono();    // metodo propio

    return 0;
}