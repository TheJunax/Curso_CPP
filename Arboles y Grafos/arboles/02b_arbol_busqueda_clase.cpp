/*
=====================================================================
  02b - ARBOL BINARIO DE BUSQUEDA (BST)  -  version con CLASE
---------------------------------------------------------------------
  Es lo mismo que 02_arbol_busqueda.cpp, pero metido en una clase.

  Ventajas:
   - Desde main no hay que manejar la raiz ni escribir
     "raiz = insertar(raiz, x)". Solo:  arbol.insertar(x);
   - El destructor libera la memoria solo al terminar.

  Truco: las funciones recursivas necesitan recibir un nodo,
  asi que se hacen PRIVADAS (terminan en "Rec") y las publicas
  solo las llaman empezando desde la raiz.

  Compilar:  g++ 02b_arbol_busqueda_clase.cpp -o bst_clase
=====================================================================
*/
#include <iostream>
using namespace std;

class ArbolBusqueda {
private:
    struct Nodo {
        int dato;
        Nodo* izq;
        Nodo* der;
    };

    Nodo* raiz;

    Nodo* crearNodo(int dato) {
        Nodo* nuevo = new Nodo;
        nuevo->dato = dato;
        nuevo->izq = nullptr;
        nuevo->der = nullptr;
        return nuevo;
    }

    Nodo* insertarRec(Nodo* nodo, int valor) {
        if (nodo == nullptr) return crearNodo(valor);
        if (valor < nodo->dato)      nodo->izq = insertarRec(nodo->izq, valor);
        else if (valor > nodo->dato) nodo->der = insertarRec(nodo->der, valor);
        return nodo;
    }

    bool buscarRec(Nodo* nodo, int valor) {
        if (nodo == nullptr) return false;
        if (valor == nodo->dato) return true;
        if (valor < nodo->dato) return buscarRec(nodo->izq, valor);
        else                    return buscarRec(nodo->der, valor);
    }

    Nodo* minimoRec(Nodo* nodo) {
        while (nodo->izq != nullptr) nodo = nodo->izq;
        return nodo;
    }

    Nodo* borrarRec(Nodo* nodo, int valor) {
        if (nodo == nullptr) return nullptr;

        if (valor < nodo->dato)      nodo->izq = borrarRec(nodo->izq, valor);
        else if (valor > nodo->dato) nodo->der = borrarRec(nodo->der, valor);
        else {
            if (nodo->izq == nullptr) {             // hoja o solo hijo derecho
                Nodo* hijo = nodo->der;
                delete nodo;
                return hijo;
            }
            if (nodo->der == nullptr) {             // solo hijo izquierdo
                Nodo* hijo = nodo->izq;
                delete nodo;
                return hijo;
            }
            Nodo* sucesor = minimoRec(nodo->der);   // dos hijos
            nodo->dato = sucesor->dato;
            nodo->der = borrarRec(nodo->der, sucesor->dato);
        }
        return nodo;
    }

    void inordenRec(Nodo* nodo) {
        if (nodo == nullptr) return;
        inordenRec(nodo->izq);
        cout << nodo->dato << " ";
        inordenRec(nodo->der);
    }

    void mostrarRec(Nodo* nodo, int nivel) {
        if (nodo == nullptr) return;
        mostrarRec(nodo->der, nivel + 1);
        for (int i = 0; i < nivel; i++) cout << "      ";
        cout << nodo->dato << endl;
        mostrarRec(nodo->izq, nivel + 1);
    }

    int alturaRec(Nodo* nodo) {
        if (nodo == nullptr) return 0;
        int a = alturaRec(nodo->izq);
        int b = alturaRec(nodo->der);
        if (a > b) return a + 1;
        else       return b + 1;
    }

    void destruirRec(Nodo* nodo) {
        if (nodo == nullptr) return;
        destruirRec(nodo->izq);
        destruirRec(nodo->der);
        delete nodo;
    }

public:
    ArbolBusqueda()  { raiz = nullptr; }         // constructor
    ~ArbolBusqueda() { destruirRec(raiz); }      // destructor

    void insertar(int valor) { raiz = insertarRec(raiz, valor); }
    bool buscar(int valor)   { return buscarRec(raiz, valor); }
    void borrar(int valor)   { raiz = borrarRec(raiz, valor); }
    int  altura()            { return alturaRec(raiz); }
    bool estaVacio()         { return raiz == nullptr; }

    void inorden() { inordenRec(raiz); cout << endl; }
    void mostrar() { mostrarRec(raiz, 0); }
};

// ------------------------------------------------------------
int main() {
    ArbolBusqueda arbol;

    int datos[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++)
        arbol.insertar(datos[i]);

    cout << "Arbol (acostado):" << endl;
    arbol.mostrar();

    cout << endl << "Inorden: ";
    arbol.inorden();
    cout << "Altura: " << arbol.altura() << endl;
    cout << "Buscar 40: " << (arbol.buscar(40) ? "SI" : "NO") << endl;

    arbol.borrar(50);
    cout << endl << "Despues de borrar 50:" << endl;
    arbol.mostrar();

    return 0;   // aqui se llama solo el destructor
}
