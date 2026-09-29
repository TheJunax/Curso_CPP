// StackRef.cpp — Por que std::stack usa std::deque y NO std::vector.
//
// std::stack<T, Container> es SOLO un adaptador: elige el contenedor de abajo.
// La diferencia entre vector y deque no es el algoritmo de la pila (push/pop
// son iguales); es QUE LE PASA A UNA REFERENCIA QUE YA TENIAS.
//
// Compilar: g++ -Wall -Wextra -g StackRef.cpp -o StackRef

#include <iostream>
#include <stack>
#include <vector>
#include <deque>
using namespace std;

int main() {
    // =====================================================================
    cout << "=== A. stack sobre std::vector (el que NO quiere la STL) ===\n";
    // =====================================================================
    // OJO con la capacidad: libstdc++ duplica 1 -> 2 -> 4 -> 8. Con 3
    // elementos la capacidad ya es 4, asi que un cuarto push NO reubica.
    // Para forzar la reubicacion hay que LLENAR la capacidad y meter uno mas.
    {
        stack<int, vector<int>> s;
        s.push(1); s.push(2); s.push(3);     // capacidad interna = 4

        int& r = s.top();          // r apunta al 3, que es la cima
        r = 999;                   // tocamos la cima a proposito
        cout << "  toco la cima: r = " << r
             << "  -> s.top() = " << s.top() << "   (funciona)\n";

        s.push(4);                 // 4 de 4: lleno, todavia SIN reubicar
        cout << "  push(4): capacidad llena. s.top() = " << s.top()
             << ", r = " << r << " (r todavia viva)\n";

        s.push(5);                 // <-- ESTE reubica: copia a un bloque nuevo
        cout << "  push(5): ahora SI reubico (1->2->4->8)\n";
        cout << "  s.top() = " << s.top() << "  <- correcto\n";
        cout << "  r = " << r << "  <- r apunta al bloque VIEJO, ya liberado\n\n";
    }

    // =====================================================================
    cout << "=== B. stack sobre std::deque (el que usa la STL por defecto) ===\n";
    // =====================================================================
    {
        stack<int> s;              // = stack<int, deque<int>>
        s.push(1); s.push(2); s.push(3);

        int& r = s.top();
        r = 999;
        cout << "  toco la cima: r = " << r
             << "  -> s.top() = " << s.top() << "   (funciona)\n";

        s.push(4);
        s.push(5);                 // deque NO reubica: agrega bloques nuevos
        cout << "  push(4) y push(5): deque agrego bloques, NO movio nada\n";
        cout << "  s.top() = " << s.top() << "  <- correcto\n";
        cout << "  r = " << r << "  <- r SIGUE VIVA: el bloque viejo no se toco\n\n";
    }

    // =====================================================================
    cout << "=== C. OJO: esto pasa en LOS DOS, y no tiene nada que ver ===\n";
    // =====================================================================
    {
        stack<int> s;
        s.push(1); s.push(2); s.push(3);
        int& r = s.top();          // r = 3, la cima
        s.push(4);
        cout << "  tras push(4): s.top() = " << s.top() << ", pero r = " << r << "\n";
        cout << "  r es una referencia VALIDA... a la 3, que ya no es la cima.\n";
        cout << "  'Referencia a la cima' es efimera por definicion:\n";
        cout << "  en cuanto la cima se mueve, tu referencia apunta a otra cosa.\n";
        cout << "  Por eso el patron de uso de una pila es:\n";
        cout << "      top() -> leo -> pop()\n";
        cout << "  y NUNCA:\n";
        cout << "      int& r = s.top(); ... s.push(x); ... usar r\n";
    }

    return 0;
}
