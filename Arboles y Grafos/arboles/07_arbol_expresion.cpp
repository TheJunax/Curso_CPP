/*
=====================================================================
  07 - ARBOL DE EXPRESION
---------------------------------------------------------------------
  Es un arbol binario donde:
    - las HOJAS son numeros
    - los nodos internos son OPERADORES (+ - * /)

  La expresion  (3 + 4) * 5  se ve asi:

            *
           / \
          +   5
         / \
        3   4

  Los recorridos dan las 3 notaciones:
    Inorden   -> infija   (3 + 4) * 5
    Preorden  -> prefija  * + 3 4 5
    Postorden -> postfija 3 4 + 5 *

  VERSION 1: armar el arbol a mano
  VERSION 2: armarlo automaticamente desde una expresion
             postfija, usando una pila

  (Para simplificar, los numeros son de un solo digito)

  Compilar:  g++ 07_arbol_expresion.cpp -o expresion
=====================================================================
*/
#include <iostream>
#include <string>
#include <stack>
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

bool esOperador(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Evaluar: si es hoja devuelve el numero, si no, opera los dos lados
double evaluar(Nodo* nodo) {
    if (!esOperador(nodo->dato))
        return nodo->dato - '0';            // convierte '7' en 7

    double izq = evaluar(nodo->izq);
    double der = evaluar(nodo->der);

    if (nodo->dato == '+') return izq + der;
    if (nodo->dato == '-') return izq - der;
    if (nodo->dato == '*') return izq * der;
    return izq / der;                       // '/'
}

// Infija con parentesis (inorden)
void infija(Nodo* nodo) {
    if (nodo == nullptr) return;
    if (esOperador(nodo->dato)) cout << "(";
    infija(nodo->izq);
    cout << nodo->dato;
    infija(nodo->der);
    if (esOperador(nodo->dato)) cout << ")";
}

void prefija(Nodo* nodo) {      // preorden
    if (nodo == nullptr) return;
    cout << nodo->dato << " ";
    prefija(nodo->izq);
    prefija(nodo->der);
}

void postfija(Nodo* nodo) {     // postorden
    if (nodo == nullptr) return;
    postfija(nodo->izq);
    postfija(nodo->der);
    cout << nodo->dato << " ";
}

// ------------------------------------------------------------
//  VERSION 2: construir desde una expresion POSTFIJA
//   - Si es numero: se crea un nodo y se mete en la pila
//   - Si es operador: se sacan 2 nodos de la pila, se cuelgan
//     como hijos del operador y el operador vuelve a la pila
//   - Al final, en la pila queda la raiz
// ------------------------------------------------------------
Nodo* construirDesdePostfija(string expresion) {
    stack<Nodo*> pila;

    for (int i = 0; i < (int)expresion.size(); i++) {
        char c = expresion[i];
        if (c == ' ') continue;

        Nodo* nuevo = crearNodo(c);

        if (esOperador(c)) {
            nuevo->der = pila.top(); pila.pop();   // OJO: primero sale el derecho
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
    delete nodo;
}

// ------------------------------------------------------------
int main() {
    // VERSION 1: a mano  ->  (3 + 4) * 5
    Nodo* raiz = crearNodo('*');
    raiz->izq = crearNodo('+');
    raiz->der = crearNodo('5');
    raiz->izq->izq = crearNodo('3');
    raiz->izq->der = crearNodo('4');

    cout << "=== Armado a mano ===" << endl;
    cout << "Infija:   "; infija(raiz);   cout << endl;
    cout << "Prefija:  "; prefija(raiz);  cout << endl;
    cout << "Postfija: "; postfija(raiz); cout << endl;
    cout << "Resultado: " << evaluar(raiz) << endl;

    // VERSION 2: desde postfija  ->  8 2 / 3 1 - *   =  (8/2)*(3-1) = 8
    Nodo* otro = construirDesdePostfija("8 2 / 3 1 - *");

    cout << endl << "=== Desde postfija: 8 2 / 3 1 - * ===" << endl;
    cout << "Infija:   "; infija(otro);  cout << endl;
    cout << "Prefija:  "; prefija(otro); cout << endl;
    cout << "Resultado: " << evaluar(otro) << endl;

    destruir(raiz);
    destruir(otro);
    return 0;
}
