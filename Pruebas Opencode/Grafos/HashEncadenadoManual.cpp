/*
    TABLA DISPERSA ENCADENADA - sin STL.
    Solo punteros: cada cubeta es una lista que uno mismo construye.

    colisiones = 3 claves que caen en la misma cubeta:
        3 % 7 = 3,  10 % 7 = 3,  17 % 7 = 3
*/

#include <iostream>
using namespace std;

struct Nodo {
    int clave;
    int valor;
    Nodo* sig;
};

Nodo** cubetas = nullptr;     // array de PUNTEROS a Nodo
int numCubetas = 0;
int cantidad = 0;

// hash: modular, con proteccion para claves negativas
int indice(int clave) {
    int i = clave % numCubetas;
    return (i < 0) ? i + numCubetas : i;
}

void init(int tam) {
    numCubetas = tam;
    cantidad = 0;
    cubetas = new Nodo*[tam];        // reserva el arreglo de punteros
    for (int i = 0; i < tam; i++) cubetas[i] = nullptr;
}

void init(int tam);

void crecer();          // insertar() la llama, pero esta definida mas abajo

bool insertar(int clave, int valor) {
    int i = indice(clave);
    for (Nodo* p = cubetas[i]; p != nullptr; p = p->sig)
        if (p->clave == clave) { p->valor = valor; return true; }

    Nodo* nuevo = new Nodo{clave, valor, cubetas[i]};   // mete al frente
    cubetas[i] = nuevo;
    cantidad++;

    if ((double)cantidad / numCubetas > 0.75) crecer();
    return true;
}

bool buscar(int clave, int& valor) {
    for (Nodo* p = cubetas[indice(clave)]; p != nullptr; p = p->sig)
        if (p->clave == clave) { valor = p->valor; return true; }
    return false;
}

bool eliminar(int clave) {
    int i = indice(clave);
    Nodo* p = cubetas[i];
    Nodo* anterior = nullptr;

    while (p != nullptr && p->clave != clave) {
        anterior = p;
        p = p->sig;
    }
    if (p == nullptr) return false;               // no existe

    if (anterior == nullptr) cubetas[i] = p->sig; // era el primero
    else anterior->sig = p->sig;
    delete p;
    cantidad--;
    return true;
}

// los nodos son los mismos: solo se cambia a que cubeta apuntan
void crecer() {
    Nodo** viejo = cubetas;
    int viejoTam = numCubetas;

    init(viejoTam * 2);                            // todo en cero otra vez

    for (int i = 0; i < viejoTam; i++) {
        Nodo* p = viejo[i];
        while (p != nullptr) {
            Nodo* siguiente = p->sig;              // salva el enganche
            int nuevo = indice(p->clave);         // reindexa con el tam nuevo
            p->sig = cubetas[nuevo];
            cubetas[nuevo] = p;
            cantidad++;
            p = siguiente;
        }
    }
    delete[] viejo;
}

void imprimir() {
    for (int i = 0; i < numCubetas; i++) {
        cout << "  cubeta " << i << ": ";
        if (cubetas[i] == nullptr) cout << "(vacia)";
        for (Nodo* p = cubetas[i]; p != nullptr; p = p->sig)
            cout << p->clave << "=" << p->valor << " -> ";
        cout << endl;
    }
    cout << "  claves: " << cantidad << " / " << numCubetas
         << "  (alpha " << (double)cantidad / numCubetas << ")" << endl;
}

void liberar() {
    for (int i = 0; i < numCubetas; i++) {
        Nodo* p = cubetas[i];
        while (p != nullptr) {
            Nodo* sig = p->sig;
            delete p;
            p = sig;
        }
    }
    delete[] cubetas;
    cubetas = nullptr;
}

int main() {
    init(7);

    insertar(3, 30);
    insertar(10, 100);
    insertar(17, 170);
    insertar(5, 50);

    cout << "== 4 claves en 7 cubetas ==" << endl;
    imprimir();

    int v;
    cout << "\nbuscar(17) -> " << (buscar(17, v) ? v : -1) << endl;
    cout << "buscar(99) -> " << (buscar(99, v) ? v : -1) << endl;

    cout << "\nactualizo 3 = 999" << endl;
    insertar(3, 999);
    buscar(3, v);
    cout << "buscar(3) -> " << v << "  (claves: " << cantidad << ")" << endl;

    cout << "\nelimino 10 (el del medio de la colision)" << endl;
    eliminar(10);
    imprimir();
    cout << "buscar(17) -> " << (buscar(17, v) ? v : -1) << endl;

    cout << "\n== inserto hasta forzar crecer() ==" << endl;
    for (int k = 100; k < 110; k++) insertar(k, k * 2);
    imprimir();
    cout << "17 quedo en cubeta " << indice(17) << endl;

    liberar();
    return 0;
}