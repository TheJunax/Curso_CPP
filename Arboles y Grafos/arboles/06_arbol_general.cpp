/*
=====================================================================
  06 - ARBOL GENERAL (cada nodo puede tener MUCHOS hijos)
---------------------------------------------------------------------
  Ejemplo tipico: carpetas de un computador, organigrama
  de una empresa, arbol genealogico.

  VERSION 1 (este archivo): cada nodo guarda sus hijos en un vector.

  VERSION 2: 06b_arbol_general_hijo_hermano.cpp
             (sin vector, solo con punteros: primer hijo y
             siguiente hermano. Es la forma clasica de los libros)

  Compilar:  g++ 06_arbol_general.cpp -o general
=====================================================================
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Nodo {
    string dato;
    vector<Nodo*> hijos;     // lista de hijos (puede estar vacia)
};

Nodo* crearNodo(string dato) {
    Nodo* nuevo = new Nodo;
    nuevo->dato = dato;
    return nuevo;
}

// Crea un hijo, lo engancha al padre y lo devuelve
Nodo* agregarHijo(Nodo* padre, string dato) {
    Nodo* hijo = crearNodo(dato);
    padre->hijos.push_back(hijo);
    return hijo;
}

// Muestra el arbol con sangria (como carpetas)
void mostrar(Nodo* nodo, int nivel) {
    if (nodo == nullptr) return;

    for (int i = 0; i < nivel; i++) cout << "    ";
    cout << "- " << nodo->dato << endl;

    for (int i = 0; i < (int)nodo->hijos.size(); i++)
        mostrar(nodo->hijos[i], nivel + 1);
}

// Preorden: el nodo y despues todos sus hijos
void preorden(Nodo* nodo) {
    if (nodo == nullptr) return;
    cout << nodo->dato << " ";
    for (int i = 0; i < (int)nodo->hijos.size(); i++)
        preorden(nodo->hijos[i]);
}

// Postorden: todos los hijos y despues el nodo
void postorden(Nodo* nodo) {
    if (nodo == nullptr) return;
    for (int i = 0; i < (int)nodo->hijos.size(); i++)
        postorden(nodo->hijos[i]);
    cout << nodo->dato << " ";
}

int altura(Nodo* nodo) {
    if (nodo == nullptr) return 0;
    int mayor = 0;
    for (int i = 0; i < (int)nodo->hijos.size(); i++) {
        int a = altura(nodo->hijos[i]);
        if (a > mayor) mayor = a;
    }
    return mayor + 1;
}

int contarHojas(Nodo* nodo) {
    if (nodo == nullptr) return 0;
    if (nodo->hijos.size() == 0) return 1;
    int total = 0;
    for (int i = 0; i < (int)nodo->hijos.size(); i++)
        total += contarHojas(nodo->hijos[i]);
    return total;
}

// Busca un nodo por su dato. Devuelve nullptr si no esta.
Nodo* buscar(Nodo* nodo, string dato) {
    if (nodo == nullptr) return nullptr;
    if (nodo->dato == dato) return nodo;
    for (int i = 0; i < (int)nodo->hijos.size(); i++) {
        Nodo* encontrado = buscar(nodo->hijos[i], dato);
        if (encontrado != nullptr) return encontrado;
    }
    return nullptr;
}

void destruir(Nodo* nodo) {
    if (nodo == nullptr) return;
    for (int i = 0; i < (int)nodo->hijos.size(); i++)
        destruir(nodo->hijos[i]);
    delete nodo;
}

// ------------------------------------------------------------
int main() {
    Nodo* raiz = crearNodo("C:");

    Nodo* documentos = agregarHijo(raiz, "Documentos");
    agregarHijo(raiz, "Musica");                  // queda vacia (es una hoja)
    Nodo* fotos      = agregarHijo(raiz, "Fotos");

    agregarHijo(documentos, "tarea.cpp");
    agregarHijo(documentos, "notas.txt");
    Nodo* u = agregarHijo(documentos, "Universidad");
    agregarHijo(u, "parcial.pdf");

    agregarHijo(fotos, "viaje.jpg");

    mostrar(raiz, 0);

    cout << endl << "Preorden:  "; preorden(raiz);  cout << endl;
    cout << "Postorden: ";        postorden(raiz); cout << endl;
    cout << "Altura: " << altura(raiz) << endl;
    cout << "Hojas: " << contarHojas(raiz) << endl;

    Nodo* b = buscar(raiz, "Universidad");
    if (b != nullptr)
        cout << "Universidad tiene " << b->hijos.size() << " hijo(s)" << endl;

    destruir(raiz);
    return 0;
}
