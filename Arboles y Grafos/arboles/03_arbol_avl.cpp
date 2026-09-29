/*
=====================================================================
  03 - ARBOL AVL (arbol de busqueda que se equilibra solo)
---------------------------------------------------------------------
  Es un BST normal, pero despues de cada insercion revisa si
  algun nodo quedo desequilibrado y lo arregla con ROTACIONES.

  Factor de equilibrio (FE) = altura(izq) - altura(der)
    FE = -1, 0 o 1   -> equilibrado
    FE =  2          -> cargado a la IZQUIERDA
    FE = -2          -> cargado a la DERECHA

  Los 4 casos:
    Izq-Izq  -> una rotacion a la derecha
    Der-Der  -> una rotacion a la izquierda
    Izq-Der  -> rotar izquierda el hijo, luego derecha el nodo
    Der-Izq  -> rotar derecha el hijo, luego izquierda el nodo

  Compilar:  g++ 03_arbol_avl.cpp -o avl
=====================================================================
*/
#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    int altura;     // cada nodo guarda su altura
    Nodo* izq;
    Nodo* der;
};

Nodo* crearNodo(int dato) {
    Nodo* nuevo = new Nodo;
    nuevo->dato = dato;
    nuevo->altura = 1;          // un nodo solo tiene altura 1
    nuevo->izq = nullptr;
    nuevo->der = nullptr;
    return nuevo;
}

int altura(Nodo* nodo) {
    if (nodo == nullptr) return 0;
    return nodo->altura;
}

int mayor(int a, int b) {
    if (a > b) return a;
    return b;
}

void actualizarAltura(Nodo* nodo) {
    nodo->altura = 1 + mayor(altura(nodo->izq), altura(nodo->der));
}

int factorEquilibrio(Nodo* nodo) {
    if (nodo == nullptr) return 0;
    return altura(nodo->izq) - altura(nodo->der);
}

/*
  ROTACION A LA DERECHA (sobre y)

          y                 x
         / \               / \
        x   C     -->     A   y
       / \                   / \
      A   B                 B   C
*/
Nodo* rotarDerecha(Nodo* y) {
    Nodo* x = y->izq;
    Nodo* B = x->der;

    x->der = y;      // y baja a la derecha de x
    y->izq = B;      // B se pasa a la izquierda de y

    actualizarAltura(y);   // primero y (quedo abajo)
    actualizarAltura(x);   // luego x (quedo arriba)
    return x;              // x es la nueva raiz de este subarbol
}

/*
  ROTACION A LA IZQUIERDA (sobre x)

        x                     y
       / \                   / \
      A   y       -->       x   C
         / \               / \
        B   C             A   B
*/
Nodo* rotarIzquierda(Nodo* x) {
    Nodo* y = x->der;
    Nodo* B = y->izq;

    y->izq = x;
    x->der = B;

    actualizarAltura(x);
    actualizarAltura(y);
    return y;
}

// ------------------------------------------------------------
//  INSERTAR
//  Uso:  raiz = insertar(raiz, valor);
// ------------------------------------------------------------
Nodo* insertar(Nodo* nodo, int valor) {
    // 1) Insertar como en un BST normal
    if (nodo == nullptr) return crearNodo(valor);

    if (valor < nodo->dato)      nodo->izq = insertar(nodo->izq, valor);
    else if (valor > nodo->dato) nodo->der = insertar(nodo->der, valor);
    else return nodo;            // repetido

    // 2) Actualizar la altura de este nodo
    actualizarAltura(nodo);

    // 3) Revisar si quedo desequilibrado
    int fe = factorEquilibrio(nodo);

    // Caso Izquierda-Izquierda
    if (fe > 1 && valor < nodo->izq->dato) {
        cout << "  [Rotacion derecha en " << nodo->dato << "]" << endl;
        return rotarDerecha(nodo);
    }
    // Caso Derecha-Derecha
    if (fe < -1 && valor > nodo->der->dato) {
        cout << "  [Rotacion izquierda en " << nodo->dato << "]" << endl;
        return rotarIzquierda(nodo);
    }
    // Caso Izquierda-Derecha
    if (fe > 1 && valor > nodo->izq->dato) {
        cout << "  [Rotacion doble izq-der en " << nodo->dato << "]" << endl;
        nodo->izq = rotarIzquierda(nodo->izq);
        return rotarDerecha(nodo);
    }
    // Caso Derecha-Izquierda
    if (fe < -1 && valor < nodo->der->dato) {
        cout << "  [Rotacion doble der-izq en " << nodo->dato << "]" << endl;
        nodo->der = rotarDerecha(nodo->der);
        return rotarIzquierda(nodo);
    }

    return nodo;    // estaba equilibrado
}

void inorden(Nodo* nodo) {
    if (nodo == nullptr) return;
    inorden(nodo->izq);
    cout << nodo->dato << " ";
    inorden(nodo->der);
}

// Muestra el arbol acostado (derecha arriba), con su FE
void mostrarArbol(Nodo* nodo, int nivel) {
    if (nodo == nullptr) return;
    mostrarArbol(nodo->der, nivel + 1);
    for (int i = 0; i < nivel; i++) cout << "        ";
    cout << nodo->dato << "(FE " << factorEquilibrio(nodo) << ")" << endl;
    mostrarArbol(nodo->izq, nivel + 1);
}

void destruir(Nodo* nodo) {
    if (nodo == nullptr) return;
    destruir(nodo->izq);
    destruir(nodo->der);
    delete nodo;
}

// ------------------------------------------------------------
int main() {
    Nodo* raiz = nullptr;

    int datos[] = {10, 20, 30, 40, 50, 25};
    for (int i = 0; i < 6; i++) {
        cout << "Insertar " << datos[i] << endl;
        raiz = insertar(raiz, datos[i]);
    }

    cout << endl << "Arbol AVL final (acostado):" << endl;
    mostrarArbol(raiz, 0);

    cout << endl << "Inorden: ";
    inorden(raiz);
    cout << endl << "Altura: " << altura(raiz) << endl;

    // Prueba: insertar 1..15 en orden.
    // Un BST normal quedaria como una lista (altura 15).
    // El AVL queda con altura 4.
    Nodo* otro = nullptr;
    cout << endl << "Insertando 1 a 15 en orden..." << endl;
    for (int i = 1; i <= 15; i++) otro = insertar(otro, i);
    cout << "Altura del AVL: " << altura(otro) << " (un BST normal tendria 15)" << endl;

    destruir(raiz);
    destruir(otro);
    return 0;
}
