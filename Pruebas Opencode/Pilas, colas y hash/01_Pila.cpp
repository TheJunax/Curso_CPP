/*
  01 - PILA (STACK) — LIFO
  "El ultimo que entra, es el primero que sale."

  Compilar: g++ -Wall -Wextra -g 01_Pila.cpp -o pila
*/

#include <iostream>
#include <string>
#include <stack>

// Invariante: tope == -1 <=> vacia; tope == cantidad - 1
template <typename T>
class Pila {
private:
    T*  datos;
    int capacidad;
    int tope;

public:
    Pila(int cap) : datos(new T[cap]), capacidad(cap), tope(-1) {}
    ~Pila() { delete[] datos; }

    // Devuelve false si esta llena (si devuelve void, nadie se entera).
    bool meter(const T& valor) {
        if (tope + 1 == capacidad) return false;
        datos[tope + 1] = valor;
        tope++;
        return true;
    }

    // T& de salida: con T se haria una copia.
    bool sacar(T& valor) {
        if (estaVacia()) return false;
        valor = datos[tope];
        tope--;
        return true;
    }

    // T&: prestamo al interior. Se invalida si la pila se reutiliza.
    T& cima()             { return datos[tope]; }
    const T& cima() const { return datos[tope]; }

    bool estaVacia() const       { return tope == -1; }
    int  tamano() const          { return tope + 1; }
    int  capacidadMaxima() const { return capacidad; }

    void imprimir() const {
        if (estaVacia()) { std::cout << "(pila vacia)"; return; }
        for (int i = 0; i <= tope; i++) std::cout << "| " << datos[i] << " | ";
    }
};


int main() {
    Pila<int> p(5);
    int valor = 0;

    std::cout << "=== PILA de int (capacidad 5) ===\n";
    std::cout << "vacia de arranque: " << (p.estaVacia() ? "true" : "false") << "\n";

    std::cout << "\n-- metiendo 1..5 --\n";
    for (int i = 1; i <= 5; i++)
        std::cout << "  meter(" << i << "): " << (p.meter(i) ? "true" : "false") << "\n";

    std::cout << "\n  meter(6) con la pila LLENA: " << (p.meter(6) ? "true" : "false") << "\n";
    std::cout << "\n  contenido (fondo -> tope): "; p.imprimir();
    std::cout << "\n  tamano: " << p.tamano() << " de " << p.capacidadMaxima();
    std::cout << "\n  cima: " << p.cima() << "\n";

    std::cout << "\n\n-- sacando todo (LIFO: sale el ultimo) --\n    ";
    while (p.sacar(valor)) std::cout << valor << " ";
    std::cout << "\n  vacia al final : " << (p.estaVacia() ? "true" : "false");
    std::cout << "\n  sacar de vacia: " << (p.sacar(valor) ? "true" : "false") << "\n";

    std::cout << "\n=== la MISMA plantilla con std::string ===\n";
    Pila<std::string> ps(3);
    ps.meter(std::string("uno"));
    ps.meter(std::string("dos"));
    ps.meter(std::string("tres"));
    std::cout << "  cima: " << ps.cima() << "\n";
    std::cout << "  meter(\"cuatro\") con capacidad 3: "
              << (ps.meter(std::string("cuatro")) ? "true" : "false") << "\n";
    std::string texto;
    std::cout << "  sacar: ";
    while (ps.sacar(texto)) std::cout << texto << " ";
    std::cout << "\n";

    // nuestra Pila<T> == std::stack<T>
    //   meter() == push()   sacar() == pop()   cima() == top()
    std::cout << "\n=== equivalencia con la STL ===\n";
    std::stack<int> st;
    st.push(10); st.push(20); st.push(30);
    std::cout << "  std::stack con 10,20,30 -> top() = " << st.top() << "\n";
    st.pop();
    std::cout << "  tras pop()              -> top() = " << st.top() << "\n";
    std::cout << "  empty() = " << (st.empty() ? "true" : "false")
              << ", size() = " << st.size() << "\n";

    std::cout << "\n=== RETO 1: balanceo de parentesis ===\n";
    // std::cout << balanceado("(a+(b*c)") << "  (esperado: false)\n";
    // std::cout << balanceado("(a+b*c)")  << "  (esperado: true)\n";
    // std::cout << balanceado("([)]")     << "  (esperado: false)\n";

    return 0;
}
