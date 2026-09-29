
#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* izq;
    Nodo* der;
};

Nodo* crearNodo(int dato) {
    Nodo* nuevo = new Nodo;
    nuevo->dato = dato;
    nuevo->izq = nullptr;
    nuevo->der = nullptr;
    return nuevo;
}


Nodo* insertar(Nodo* raiz, int valor) {
    if (raiz == nullptr) return crearNodo(valor);   // hueco encontrado

    if (valor < raiz->dato)
        raiz->izq = insertar(raiz->izq, valor);     // bajar a la izquierda
    else if (valor > raiz->dato)
        raiz->der = insertar(raiz->der, valor);     // bajar a la derecha

    return raiz;
}



bool buscar(Nodo* raiz, int valor) {
    if (raiz == nullptr) return false;              // no esta
    if (valor == raiz->dato) return true;           // encontrado

    if (valor < raiz->dato){
        return buscar(raiz->izq, valor);
    }
    else {
        return buscar(raiz->der, valor);
    }
}



Nodo* minimo(Nodo* raiz) {
    Nodo* actual = raiz;
    while (actual->izq != nullptr) actual = actual->izq;
    return actual;
}

Nodo* maximo(Nodo* raiz) {
    Nodo* actual = raiz;
    while (actual->der != nullptr) actual = actual->der;
    return actual;
}

// ------------------------------------------------------------
//  BORRAR
//   Caso 1: hoja         -> se elimina y el padre queda en nullptr
//   Caso 2: un hijo      -> el hijo sube a ocupar su lugar
//   Caso 3: dos hijos    -> se copia el SUCESOR (minimo del
//                           subarbol derecho) y se borra el sucesor
//  Siempre se usa asi:  raiz = borrar(raiz, valor);
// ------------------------------------------------------------
Nodo* borrar(Nodo* raiz, int valor) {
    if (raiz == nullptr) return nullptr;            // no estaba

    if (valor < raiz->dato) {
        raiz->izq = borrar(raiz->izq, valor);
    }
    else if (valor > raiz->dato) {
        raiz->der = borrar(raiz->der, valor);
    }
    else {
        // Lo encontramos

        // Caso 1 y 2: no tiene hijo izquierdo
        if (raiz->izq == nullptr) {
            Nodo* hijo = raiz->der;                 // puede ser nullptr (hoja)
            delete raiz;
            return hijo;
        }
        // Caso 2: no tiene hijo derecho
        if (raiz->der == nullptr) {
            Nodo* hijo = raiz->izq;
            delete raiz;
            return hijo;
        }
        // Caso 3: tiene dos hijos
        Nodo* sucesor = minimo(raiz->der);
        raiz->dato = sucesor->dato;                          // copiar
        raiz->der = borrar(raiz->der, sucesor->dato);        // borrar el sucesor
    }
    return raiz;
}

void inorden(Nodo* raiz) {
    if (raiz == nullptr) return;
    inorden(raiz->izq);
    cout << raiz->dato << " ";
    inorden(raiz->der);
}

// ------------------------------------------------------------
//  MOSTRAR el arbol "acostado":
//  la raiz queda a la izquierda, el lado derecho queda ARRIBA.
//  (Ladea la cabeza hacia la izquierda para verlo normal)
// ------------------------------------------------------------
void mostrarArbol(Nodo* raiz, int nivel) {
    if (raiz == nullptr) return;

    mostrarArbol(raiz->der, nivel + 1);

    for (int i = 0; i < nivel; i++) cout << "      ";
    cout << raiz->dato << endl;

    mostrarArbol(raiz->izq, nivel + 1);
}

void destruir(Nodo* raiz) {
    if (raiz == nullptr) return;
    destruir(raiz->izq);
    destruir(raiz->der);
    delete raiz;
}

// ------------------------------------------------------------
int main() {
    Nodo* raiz = nullptr;

    int datos[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++)
        raiz = insertar(raiz, datos[i]);

    cout << "Arbol (acostado):" << endl;
    mostrarArbol(raiz, 0);

    cout << endl << "Inorden (ordenado): ";
    inorden(raiz);
    cout << endl;

    cout << "Buscar 60: " << (buscar(raiz, 60) ? "SI esta" : "NO esta") << endl;
    cout << "Minimo: " << minimo(raiz)->dato << "   Maximo: " << maximo(raiz)->dato << endl;

    cout << endl << "Borrar 20 (hoja):" << endl;
    raiz = borrar(raiz, 20);
    mostrarArbol(raiz, 0);

    cout << endl << "Borrar 30 (un hijo):" << endl;
    raiz = borrar(raiz, 30);
    mostrarArbol(raiz, 0);

    cout << endl << "Borrar 50 (dos hijos, es la raiz):" << endl;
    raiz = borrar(raiz, 50);
    mostrarArbol(raiz, 0);

    destruir(raiz);
    return 0;
}
