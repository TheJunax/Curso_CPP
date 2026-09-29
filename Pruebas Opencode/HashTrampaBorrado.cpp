// HashTrampaBorrado.cpp — POR QUÉ el direccionamiento abierto necesita
// BORRADO PEREZOSO.
//
// Esto NO es el reto: es una demo de 40 líneas para que veas el error pasar.
// El reto (HashAbierto.cpp) va con estados, lápidas y rehash.
//
// Compilar: g++ -Wall -Wextra -g HashTrampaBorrado.cpp -o HashTrampaBorrado

#include <iostream>
using namespace std;

const int TAM = 5;   // 5 casillas, como el ejercicio

struct Casilla {
    int clave = -1;
    bool ocupada = false;
};

// Dispersor de juguete: 20, 21, 22 caen TODOS en la cubeta 2.
// Asi forzamos la colision sin depender de std::hash.
int dispersor(int clave) { return clave / 10; }

class TablaMala {
private:
    Casilla tabla[TAM];
    int cantidad = 0;

public:
    void insertar(int clave) {
        int i = dispersor(clave);
        while (tabla[i].ocupada) {          // exploracion lineal
            i = (i + 1) % TAM;
        }
        tabla[i] = {clave, true};
        ++cantidad;
    }

    bool buscar(int clave) {
        int i = dispersor(clave);
        // MIENTE EN LA DEFINICION: para en la primera casilla vacia.
        while (tabla[i].ocupada) {
            if (tabla[i].clave == clave) return true;
            i = (i + 1) % TAM;
        }
        return false;
    }

    // EL BUG ESTA ACA. Borrar de verdad deja un hueco en medio de la cadena.
    void eliminarMal(int clave) {
        int i = dispersor(clave);
        while (tabla[i].ocupada) {
            if (tabla[i].clave == clave) {
                tabla[i].ocupada = false;  // <-- rompe el invariante
                --cantidad;
                return;
            }
            i = (i + 1) % TAM;
        }
    }

    void imprimir() const {
        cout << "   ";
        for (int i = 0; i < TAM; ++i) {
            if (tabla[i].ocupada) cout << "[" << tabla[i].clave << "] ";
            else                  cout << "[ --- ] ";
        }
        cout << "   (" << cantidad << " claves)\n";
    }
};

int main() {
    TablaMala t;

    cout << "1. Insertamos 20, 21, 22 (los tres caen en la cubeta 2):\n";
    t.insertar(20);
    t.insertar(21);
    t.insertar(22);
    t.imprimir();
    cout << "   buscar(22) = " << t.buscar(22) << "  <- se encuentra\n\n";

    cout << "2. Ahora eliminamos DE VERDAD el 21 (dejando la casilla vacia):\n";
    t.eliminarMal(21);
    t.imprimir();
    cout << "   buscar(21) = " << t.buscar(21) << "  <- correcto, si lo borramos\n";
    cout << "   buscar(22) = " << t.buscar(22)
         << "  <- FALSO. El 22 SIGUE en la tabla.\n\n";

    cout << "3. Peor todavia: el bug es INTERMITENTE. Metemos el 23, que\n";
    cout << "   cae en la cubeta 2 y se queda en el hueco que dejo el 21:\n";
    t.insertar(23);
    t.imprimir();
    cout << "   buscar(22) = " << t.buscar(22)
         << "  <- VOLVIO a encontrarlo. El 23 tapo el agujero.\n\n";

    cout << "Conclusion: el dato NO se perdio jamas. La tabla MIENTE.\n";
    cout << "Es peor que perderlo: el programa cree que el dato no existe.\n";
    cout << "Y lo peor de todo: el fallo DEPENDE DEL ORDEN.\n";
    cout << "Con el 23 puesto, buscar(22) da 1; sin el 23, daba 0.\n";
    cout << "El mismo programa, los mismos datos, resultado distinto.\n";
    cout << "Un bug intermitente es el mas dificil de encontrar en produccion.\n";
    cout << "\nLa pregunta del profe es: como lo arregla la STL?\n";
    cout << "Pista: el borrado real no puede existir. Tiene que existir un tercer\n";
    cout << "estado entre 'ocupada' y 'vacia' que la busqueda NO tome por hueco.\n";
    return 0;
}
