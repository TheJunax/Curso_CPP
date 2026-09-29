/*
=====================================================================
  06b - ARBOL GENERAL: representacion HIJO IZQUIERDO - HERMANO DERECHO
---------------------------------------------------------------------
  Otra forma de guardar un arbol con muchos hijos, usando solo
  DOS punteros por nodo (sin vector):

    primerHijo      -> apunta al primer hijo
    siguienteHermano -> apunta al siguiente hijo del mismo padre

  Arbol real:              Como se guarda:

         A                   A
       / | \                 |
      B  C  D                B -> C -> D
     / \                     |
    E   F                    E -> F

  ( | = primerHijo,   -> = siguienteHermano )

  Compilar:  g++ 06b_arbol_general_hijo_hermano.cpp -o hijo_hermano
=====================================================================
*/
#include <iostream>
using namespace std;

struct Nodo {
    char dato;
    Nodo* primerHijo;
    Nodo* siguienteHermano;
};

Nodo* crearNodo(char dato) {
    Nodo* nuevo = new Nodo;
    nuevo->dato = dato;
    nuevo->primerHijo = nullptr;
    nuevo->siguienteHermano = nullptr;
    return nuevo;
}

// Agrega un hijo AL FINAL de los hijos del padre
Nodo* agregarHijo(Nodo* padre, char dato) {
    Nodo* hijo = crearNodo(dato);

    if (padre->primerHijo == nullptr) {
        padre->primerHijo = hijo;               // es el primer hijo
    } else {
        Nodo* actual = padre->primerHijo;       // ir al ultimo hermano
        while (actual->siguienteHermano != nullptr)
            actual = actual->siguienteHermano;
        actual->siguienteHermano = hijo;
    }
    return hijo;
}

// Muestra con sangria
void mostrar(Nodo* nodo, int nivel) {
    if (nodo == nullptr) return;

    for (int i = 0; i < nivel; i++) cout << "    ";
    cout << "- " << nodo->dato << endl;

    // recorrer todos los hijos: primer hijo y luego sus hermanos
    Nodo* hijo = nodo->primerHijo;
    while (hijo != nullptr) {
        mostrar(hijo, nivel + 1);
        hijo = hijo->siguienteHermano;
    }
}

void preorden(Nodo* nodo) {
    if (nodo == nullptr) return;
    cout << nodo->dato << " ";
    Nodo* hijo = nodo->primerHijo;
    while (hijo != nullptr) {
        preorden(hijo);
        hijo = hijo->siguienteHermano;
    }
}

int contarHijos(Nodo* nodo) {
    int total = 0;
    Nodo* hijo = nodo->primerHijo;
    while (hijo != nullptr) {
        total++;
        hijo = hijo->siguienteHermano;
    }
    return total;
}

void destruir(Nodo* nodo) {
    if (nodo == nullptr) return;
    destruir(nodo->primerHijo);
    destruir(nodo->siguienteHermano);
    delete nodo;
}

// ------------------------------------------------------------
int main() {
    Nodo* raiz = crearNodo('A');

    Nodo* b = agregarHijo(raiz, 'B');
    agregarHijo(raiz, 'C');
    agregarHijo(raiz, 'D');

    agregarHijo(b, 'E');
    agregarHijo(b, 'F');

    mostrar(raiz, 0);

    cout << endl << "Preorden: ";
    preorden(raiz);
    cout << endl;

    cout << "Hijos de A: " << contarHijos(raiz) << endl;
    cout << "Hijos de B: " << contarHijos(b) << endl;

    destruir(raiz);
    return 0;
}
