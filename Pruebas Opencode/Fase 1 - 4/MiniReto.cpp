#include <iostream>
#include <string>
using namespace std;

class Persona {
public:
    Persona(string n) : nombre(n) {};   // ¿qué dice el compilador
    string VerificarNombre() const {return nombre;}

private:
    const string nombre;
};

int main() {
    Persona juan("Juan");
    string n = juan.VerificarNombre();
    std::cout << "Verificando desde fuera; nombre: " << n;
    return 0;
}