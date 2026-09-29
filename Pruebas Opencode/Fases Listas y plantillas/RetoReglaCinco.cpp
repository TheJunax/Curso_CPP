#include <iostream>
#include <utility>   // para std::move
using namespace std;

// RETO M3: la regla de cinco
// --------------------------
// Ya tienes la "regla de tres" lista (destructor, copia, asignacion de copia).
// TU TAREA: agregar el MOVIMIENTO (los otros dos de la regla de cinco):
//   1) Buffer(Buffer&& otro)        -> constructor de movimiento
//   2) Buffer& operator=(Buffer&&)  -> asignacion de movimiento
// Pistas:
//   - El move ROBA el puntero del otro (sin new, sin copiar datos)
//   - Deja al "donante" anulado: datos = nullptr; n = 0
//   - El main espera ver b.tam() == 0 y d.tam() == 0 (donantes vacios)
//   - delete[] sobre nullptr es seguro, por eso anular funciona

class Buffer {
public:
    // Constructor normal
    Buffer(int n) : n(n), datos(new int[n]) {}

    // ============ REGLA DE TRES (ya esta lista) ============

    // Destructor: libera el recurso
    ~Buffer() {
        cout << "  ~Buffer libera " << n << " ints\n";
        delete[] datos;
    }

    // Constructor de copia: copia profunda
    Buffer(const Buffer& otro) : n(otro.n), datos(new int[otro.n]) {
        for (int i = 0; i < n; ++i) datos[i] = otro.datos[i];
        cout << "  copia profunda de " << n << " ints\n";
    }

    // Asignacion de copia: copia profunda con guardia de autoasignacion
    Buffer& operator=(const Buffer& otro) {
        if (this != &otro) {
            delete[] datos;
            n = otro.n;
            datos = new int[otro.n];
            for (int i = 0; i < n; ++i) datos[i] = otro.datos[i];
        }
        cout << "  asignacion copia de " << n << " ints\n";
        return *this;
    }

    // ============ TU PARTE: REGLA DE CINCO ============
    // TODO 1: Buffer(Buffer&& otro)                 -> roba y anula
    // TODO 2: Buffer& operator=(Buffer&& otro)      -> suelta, roba y anula

    Buffer(Buffer&& otro)noexcept : n(otro.n), datos(otro.datos) {
        otro.datos = nullptr;
        otro.n =0;
    }
    Buffer &operator=(Buffer&& otro) noexcept{
        if(this == &otro){return *this;}
        delete[] datos;
        datos = otro.datos;
        n = otro.n;

        otro.datos = nullptr;
        otro.n =0;

        return *this;
    }

    // Utilidades
    void set(int i, int v) { datos[i] = v; }
    int get(int i) const { return datos[i]; }
    int tam() const { return n; }   // 0 = donante anulado

private:
    int n;
    int* datos;
};

int main() {
    cout << "1) a(3) con datos 10, 20, 30\n";
    Buffer a(3);
    a.set(0, 10); a.set(1, 20); a.set(2, 30);

    cout << "2) copia: Buffer b = a\n";
    Buffer b = a;

    cout << "3) move: Buffer d = move(b)\n";
    Buffer d = move(b);
    cout << "   d.tam() = " << d.tam() << " | b.tam() = " << b.tam()
         << "   (esperado: 3 y 0 -> b quedo anulado)\n";

    cout << "4) move asignacion: e = move(d)\n";
    Buffer e(1);
    e = move(d);
    cout << "   e.tam() = " << e.tam() << " | d.tam() = " << d.tam()
         << "   (esperado: 3 y 0 -> d quedo anulado)\n";

    cout << "5) fin: cada objeto libera lo suyo -> valgrind en 0\n";
    return 0;
}