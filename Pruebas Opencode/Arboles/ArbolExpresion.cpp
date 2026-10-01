/*
    ARBOL DE EXPRESION - version limpia, solo notacion infija.

    Es un arbol binario donde:
      - las HOJAS son numeros
      - los nodos internos son OPERADORES

        (3 + 4) * 5

              *
             / \
            +   5
           / \
          3   4

    El recorrido INORDEN (izq, nodo, der) es lo unico que reproduce
    la notacion infija: el operador sale EN EL MEDIO, que es donde
    estaba escrito.

    Para construirlo de forma automatica se usa el truco clasico: pasar
    la expresion a POSTFIJA y armarla con una pila.
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct Nodo {
    char dato;      // un digito '0'..'9' o un operador
    Nodo* izq;
    Nodo* der;
};

Nodo* crearNodo(char dato) {
    Nodo* nuevo = new Nodo;
    nuevo->dato = dato;
    nuevo->izq = nullptr;
    nuevo->der = nullptr;
    return nuevo;
}

// El criterio "es operador o no" esta en UN solo lugar: si manana
// se agrega '^' o '%', se toca esta linea y no el resto del archivo.
bool esOperador(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

double evaluar(Nodo* nodo) {
    if (!esOperador(nodo->dato))
        return nodo->dato - '0';            // '7' -> 7

    // Es operador: primero resuelvo los dos lados, despues opero.
    double izq = evaluar(nodo->izq);
    double der = evaluar(nodo->der);

    if (nodo->dato == '+') return izq + der;
    if (nodo->dato == '-') return izq - der;
    if (nodo->dato == '*') return izq * der;
    return izq / der;
}

void infija(Nodo* nodo) {
    if (nodo == nullptr) return;
    if (esOperador(nodo->dato)) cout << "(";
    infija(nodo->izq);
    cout << nodo->dato;
    infija(nodo->der);
    if (esOperador(nodo->dato)) cout << ")";
}

// De postfija "8 2 / 3 1 - *" a arbol:
//   numero  -> se mete en la pila
//   operador-> saca DOS, cuelgan como hijos, el operador vuelve a la pila
// Al final lo que queda en la pila es la raiz.
Nodo* construirDesdePostfija(const string& expresion) {
    stack<Nodo*> pila;

    for (char c : expresion) {
        if (c == ' ') continue;
        Nodo* nuevo = crearNodo(c);

        if (esOperador(c)) {
            // OJO: el primero que sale es el DERECHO, no el izquierdo.
            // "8 2 /" significa 8 / 2, no 2 / 8.
            nuevo->der = pila.top(); pila.pop();
            nuevo->izq = pila.top(); pila.pop();
        }
        pila.push(nuevo);
    }
    return pila.top();
}

void destruir(Nodo* nodo) {
    if (nodo == nullptr) return;
    destruir(nodo->izq);
    destruir(nodo->der);
    delete nodo;   // los hijos ya se liberaron, el nodo sigue vivo
}

int main() {
    cout << "=== Desde postfija: 8 2 / 3 1 - * ===" << endl;

    Nodo* raiz = construirDesdePostfija("8 2 / 3 1 - *");

    cout << "Infija:    "; infija(raiz);   cout << endl;
    cout << "Resultado: " << evaluar(raiz) << endl;

    destruir(raiz);
    return 0;
}
