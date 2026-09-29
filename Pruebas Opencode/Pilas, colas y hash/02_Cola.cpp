/*
  02 - COLA (QUEUE) — FIFO
  "El primero que entra, es el primero que sale."

  La pila mete y saca por el MISMO lado. La cola mete por un lado
  y saca por el otro:

      meter aca                          sacar aca
      (final)                            (frente)
         v                                  ^
    [ 10 ][ 20 ][ 30 ][ 40 ]
      ^
    este sale primero

  Compilar: g++ -Wall -Wextra -g 02_Cola.cpp -o cola
*/

#include <iostream>
#include <string>
#include <queue>

// Pila minima, para la comparacion del final (misma clase de 01_Pila.cpp).
template <typename T>
class Pila {
private:
    T* datos; int capacidad; int tope;
public:
    Pila(int cap) : datos(new T[cap]), capacidad(cap), tope(-1) {}
    ~Pila() { delete[] datos; }
    bool meter(const T& v) {
        if (tope + 1 == capacidad) return false;
        datos[tope + 1] = v; tope++; return true;
    }
    bool sacar(T& v) {
        if (tope == -1) return false;
        v = datos[tope]; tope--; return true;
    }
    T& cima() { return datos[tope]; }
};

// ARRAY CIRCULAR: el % capacidad hace que el final de vuelta al principio
// y los huecos liberados por el frente se reutilicen. Sin esto habria que
// correr todo el contenido: O(n) en vez de O(1).
template <typename T>
class Cola {
private:
    T*  datos;
    int capacidad;
    int frente;
    int final;
    int cantidad;

    int siguiente(int i) const { return (i + 1) % capacidad; }

public:
    Cola(int cap)
        : datos(new T[cap]), capacidad(cap), frente(0), final(-1), cantidad(0) {}

    ~Cola() { delete[] datos; }

    bool meter(const T& valor) {
        if (cantidad == capacidad) return false;
        final = siguiente(final);
        datos[final] = valor;
        cantidad++;
        return true;
    }

    bool sacar(T& valor) {
        if (vacia()) return false;
        valor = datos[frente];
        frente = siguiente(frente);
        cantidad--;
        return true;
    }

    // Se llama "mirar" y no "frente" porque el miembro ya se llama frente.
    T& mirar()             { return datos[frente]; }
    const T& mirar() const { return datos[frente]; }

    bool vacia() const               { return cantidad == 0; }
    int  tamano() const              { return cantidad; }
    int  capacidadMaxima() const     { return capacidad; }

    void imprimir() const {
        if (vacia()) { std::cout << "(cola vacia)"; return; }
        int i = frente;
        for (int k = 0; k < cantidad; k++) {
            std::cout << "[" << datos[i] << "] ";
            i = siguiente(i);   // recorre en circulo
        }
    }

    // Muestra el bloque completo para ver que es circular.
    void imprimirCrudo() const {
        for (int i = 0; i < capacidad; i++) {
            bool ocupado = false;
            int j = frente;
            for (int k = 0; k < cantidad; k++) {
                if (j == i) { ocupado = true; break; }
                j = siguiente(j);
            }
            if (ocupado) std::cout << "[" << datos[i] << "] ";
            else          std::cout << "(  .  ) ";
        }
    }
};

int main() {
    Cola<int> c(5);
    int valor = 0;

    std::cout << "=== COLA de int (capacidad 5) ===\n";
    std::cout << "vacia de arranque: " << (c.vacia() ? "true" : "false") << "\n";

    std::cout << "\n-- metiendo 10,20,30,40,50 --\n";
    for (int v : {10, 20, 30, 40, 50}) {
        c.meter(v);
        std::cout << "  tras meter(" << v << "): "; c.imprimirCrudo(); std::cout << "\n";
    }
    std::cout << "\n  meter(60) con la cola LLENA: " << (c.meter(60) ? "true" : "false") << "\n";
    std::cout << "\n  contenido (frente -> final): "; c.imprimir();
    std::cout << "\n  mirar() = " << c.mirar() << "  (el primero, sin sacarlo)\n";

    std::cout << "\n-- el array circular en accion --\n";
    std::cout << "  se sacan 10, 20, 30 (se liberan 3 huecos):\n";
    for (int i = 0; i < 3; i++) {
        c.sacar(valor);
        std::cout << "    salio " << valor << " -> "; c.imprimirCrudo(); std::cout << "\n";
    }
    std::cout << "\n  ahora se meten 60, 70 (REAPROVECHAN los huecos):\n";
    for (int v : {60, 70}) {
        c.meter(v);
        std::cout << "    tras meter(" << v << "): "; c.imprimirCrudo(); std::cout << "\n";
    }
    std::cout << "\n  contenido final: "; c.imprimir();
    std::cout << "\n  tamano: " << c.tamano() << " de " << c.capacidadMaxima() << "\n";

    std::cout << "\n-- se saca todo (FIFO) --\n    ";
    while (c.sacar(valor)) std::cout << valor << " ";
    std::cout << "\n  vacia al final : " << (c.vacia() ? "true" : "false");
    std::cout << "\n  sacar de vacia: " << (c.sacar(valor) ? "true" : "false") << "\n";

    std::cout << "\n=== la MISMA plantilla con std::string ===\n";
    Cola<std::string> cs(3);
    cs.meter(std::string("Ana"));
    cs.meter(std::string("Luis"));
    cs.meter(std::string("Zoe"));
    std::cout << "  "; cs.imprimir();
    std::cout << "\n  mirar() = " << cs.mirar() << "\n  sacar   = ";
    std::string t;
    while (cs.sacar(t)) std::cout << t << " ";
    std::cout << "\n";

    // Pila y cola: misma idea (guardar y sacar), distinto orden.
    std::cout << "\n=== PILA vs COLA ===\n";
    std::cout << "  meto 1,2,3 y miro el primero:\n\n";
    Pila<int> pila(3); pila.meter(1); pila.meter(2); pila.meter(3);
    Cola<int> cola(3); cola.meter(1); cola.meter(2); cola.meter(3);
    std::cout << "  PILA  cima()  = " << pila.cima()  << "  <- el ULTIMO que entro\n";
    std::cout << "  COLA  mirar() = " << cola.mirar() << "  <- el PRIMERO que entro\n";
    std::cout << "\n  Mismo dato, misma operacion, resultado OPUESTO.\n";

    // nuestra Cola<T> == std::queue<T>
    //   meter() == push()   sacar() == pop()   mirar() == front()
    std::cout << "\n=== equivalencia con la STL ===\n";
    std::queue<int> q;
    for (int v : {10, 20, 30}) q.push(v);
    std::cout << "  std::queue con 10,20,30 -> front() = " << q.front() << "\n";
    q.pop();
    std::cout << "  tras pop()              -> front() = " << q.front() << "\n";
    std::cout << "  back() = " << q.back() << " (el ULTIMO)\n";
    std::cout << "  empty() = " << (q.empty() ? "true" : "false")
              << ", size() = " << q.size() << "\n";

    return 0;
}
