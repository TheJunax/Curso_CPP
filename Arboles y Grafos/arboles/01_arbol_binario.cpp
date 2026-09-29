/*
=====================================================================
  01 - ARBOL BINARIO (sin orden)
---------------------------------------------------------------------
  Cada nodo tiene como maximo 2 hijos (izquierdo y derecho).
  NO hay regla de orden: cada dato va donde uno lo ponga.

  En este archivo:
   - Crear nodos y armar el arbol "a mano"
   - Recorridos: preorden, inorden, postorden y por niveles
   - Altura, cantidad de nodos y cantidad de hojas

  Se usa el arbol del ejercicio 16.2:

              P
            /   \
           Q     R
          / \   / \
         S   T U   V
        /       \
       W         X

  Compilar:  g++ 01_arbol_binario.cpp -o arbol
=====================================================================
*/
#include <iostream>
#include <queue>      // solo para el recorrido por niveles
using namespace std;

// ---------- El nodo ----------
struct Nodo {
    char dato;
    Nodo* izq;   // hijo izquierdo
    Nodo* der;   // hijo derecho
};

// Crea un nodo nuevo sin hijos
Nodo* crearNodo(char dato) {
    Nodo* nuevo = new Nodo;
    nuevo->dato = dato;
    nuevo->izq = nullptr;
    nuevo->der = nullptr;
    return nuevo;
}

// ---------- Recorridos ----------

// Preorden: NODO -> izquierda -> derecha
void preorden(Nodo* nodo) {
    if (nodo == nullptr) return;
    cout << nodo->dato << " ";
    preorden(nodo->izq);
    preorden(nodo->der);
}

// Inorden: izquierda -> NODO -> derecha
void inorden(Nodo* nodo) {
    if (nodo == nullptr) return;
    inorden(nodo->izq);
    cout << nodo->dato << " ";
    inorden(nodo->der);
}

// Postorden: izquierda -> derecha -> NODO
void postorden(Nodo* nodo) {
    if (nodo == nullptr) return;
    postorden(nodo->izq);
    postorden(nodo->der);
    cout << nodo->dato << " ";
}

// Por niveles (de arriba hacia abajo, de izquierda a derecha).
// Se usa una cola: se saca un nodo, se imprime y se meten sus hijos.
void porNiveles(Nodo* raiz) {
    if (raiz == nullptr) return;

    queue<Nodo*> cola;
    cola.push(raiz);

    while (!cola.empty()) {
        Nodo* actual = cola.front();
        cola.pop();

        cout << actual->dato << " ";

        if (actual->izq != nullptr) cola.push(actual->izq);
        if (actual->der != nullptr) cola.push(actual->der);
    }
}

// ---------- Medidas del arbol ----------

// Altura = cantidad de niveles (arbol vacio = 0)
int altura(Nodo* nodo) {
    if (nodo == nullptr) return 0;

    int alturaIzq = altura(nodo->izq);
    int alturaDer = altura(nodo->der);

    if (alturaIzq > alturaDer) return alturaIzq + 1;
    else                       return alturaDer + 1;
}

// Cuenta todos los nodos
int contarNodos(Nodo* nodo) {
    if (nodo == nullptr) return 0;
    return 1 + contarNodos(nodo->izq) + contarNodos(nodo->der);
}

// Cuenta las hojas (nodos sin hijos) y las imprime
int contarHojas(Nodo* nodo) {
    if (nodo == nullptr) return 0;

    if (nodo->izq == nullptr && nodo->der == nullptr) {
        cout << nodo->dato << " ";
        return 1;
    }
    return contarHojas(nodo->izq) + contarHojas(nodo->der);
}

// Libera la memoria (en postorden: primero hijos, luego el padre)
void destruir(Nodo* nodo) {
    if (nodo == nullptr) return;
    destruir(nodo->izq);
    destruir(nodo->der);
    delete nodo;
}

// ---------- Programa principal ----------
int main() {
    // Armamos el arbol a mano
    Nodo* raiz = crearNodo('P');

    raiz->izq = crearNodo('Q');
    raiz->der = crearNodo('R');

    raiz->izq->izq = crearNodo('S');
    raiz->izq->der = crearNodo('T');
    raiz->izq->izq->izq = crearNodo('W');

    raiz->der->izq = crearNodo('U');
    raiz->der->der = crearNodo('V');
    raiz->der->izq->der = crearNodo('X');

    // Acceso directo con ->
    cout << "Raiz: " << raiz->dato << endl;
    cout << "Hijo izquierdo de la raiz: " << raiz->izq->dato << endl;
    cout << "Hijos de R: " << raiz->der->izq->dato << " y "
         << raiz->der->der->dato << endl << endl;

    cout << "Preorden:   "; preorden(raiz);   cout << endl;
    cout << "Inorden:    "; inorden(raiz);    cout << endl;
    cout << "Postorden:  "; postorden(raiz);  cout << endl;
    cout << "Por niveles: "; porNiveles(raiz); cout << endl << endl;

    cout << "Altura: " << altura(raiz) << endl;
    cout << "Cantidad de nodos: " << contarNodos(raiz) << endl;
    cout << "Hojas: ";
    int hojas = contarHojas(raiz);
    cout << "(total " << hojas << ")" << endl;

    destruir(raiz);
    return 0;
}
