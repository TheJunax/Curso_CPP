/*
    ARBOL B - version propia, limpia para imprimir.

    Cada nodo guarda VARIAS claves ordenadas y tiene un hijo MAS por cada
    clave que tenga: las claves son los muros que separan un hijo de otro.
    Con 1 clave hay 2 rangos, con 3 claves hay 4 rangos.

    T = 2  ->  maximo 3 claves por nodo, maximo 4 hijos.

    A diferencia del AVL, aqui el balance NO se hace rotando: se hace
    partiendo nodos, y la clave del medio SUBE al padre.
*/

#include <iostream>
using namespace std;

const int T = 2;                    // grado minimo
const int MAX_CLAVES = 2 * T - 1;   // 3 claves
const int MAX_HIJOS  = 2 * T;       // 4 hijos

struct NodoB {
    int claves[MAX_CLAVES];
    NodoB* hijos[MAX_HIJOS];
    int n;          // cuantas claves tiene ahora
    bool esHoja;
};

NodoB* crearNodo(bool esHoja) {
    NodoB* nuevo = new NodoB;
    nuevo->n = 0;
    nuevo->esHoja = esHoja;
    for (int i = 0; i < MAX_HIJOS; i++) nuevo->hijos[i] = nullptr;
    return nuevo;
}

// El mismo indice sirve para dos cosas: comparar contra las claves Y
// elegir el hijo. Si cae en i, todo lo de claves[0..i-1] es menor.
int indiceDe(NodoB* nodo, int clave) {
    int i = 0;
    while (i < nodo->n && clave > nodo->claves[i]) i++;
    return i;
}

bool buscar(NodoB* nodo, int clave) {
    if (nodo == nullptr) return false;

    int i = indiceDe(nodo, clave);
    if (i < nodo->n && clave == nodo->claves[i]) return true;
    if (nodo->esHoja) return false;

    return buscar(nodo->hijos[i], clave);
}

// El hijo i esta LLENO. La clave del medio sube al padre porque es la unica
// que deja claves menores a la izquierda y mayores a la derecha.
void dividirHijo(NodoB* padre, int i) {
    NodoB* lleno = padre->hijos[i];
    NodoB* nuevo = crearNodo(lleno->esHoja);

    // El nodo nuevo se queda con la mitad derecha
    nuevo->n = T - 1;
    for (int j = 0; j < T - 1; j++)
        nuevo->claves[j] = lleno->claves[j + T];

    // Si no es hoja, se lleva tambien la mitad derecha de los hijos
    if (!lleno->esHoja) {
        for (int j = 0; j < T; j++) {
            nuevo->hijos[j] = lleno->hijos[j + T];
            lleno->hijos[j + T] = nullptr;
        }
    }

    // El nodo lleno se queda con la mitad izquierda
    lleno->n = T - 1;

    // Correr de DERCHA a IZQUIERDA: cada escritura pisa la casilla que
    // todavia no se copio. Al revés se pierde el extremo.
    for (int j = padre->n; j >= i + 1; j--)
        padre->hijos[j + 1] = padre->hijos[j];
    padre->hijos[i + 1] = nuevo;

    for (int j = padre->n - 1; j >= i; j--)
        padre->claves[j + 1] = padre->claves[j];
    padre->claves[i] = lleno->claves[T - 1];
    padre->n++;
}

// Inserta en un nodo que YA sabemos que no esta lleno.
void insertarNoLleno(NodoB* nodo, int clave) {
    int i = indiceDe(nodo, clave);

    if (nodo->esHoja) {
        for (int j = nodo->n; j > i; j--)
            nodo->claves[j] = nodo->claves[j - 1];
        nodo->claves[i] = clave;
        nodo->n++;
        return;
    }

    // Division PREVENTIVA: si el hijo de entrada esta lleno, se parte antes
    // de entrar. Asi al llegar a la hoja siempre hay espacio.
    if (nodo->hijos[i]->n == MAX_CLAVES) {
        dividirHijo(nodo, i);
        // La clave del medio ya subio a claves[i]: decide a que lado vamos.
        if (clave > nodo->claves[i]) i++;
    }

    insertarNoLleno(nodo->hijos[i], clave);
}

// Uso:  raiz = insertar(raiz, clave);   siempre reasignar la raiz.
NodoB* insertar(NodoB* raiz, int clave) {
    if (buscar(raiz, clave)) return raiz;      // no se permiten repetidos

    if (raiz == nullptr) {
        raiz = crearNodo(true);
        raiz->claves[0] = clave;
        raiz->n = 1;
        return raiz;
    }
    // La raiz llena no tiene padre adonde enviar la clave del medio, asi que
    // el arbol CRECE HACIA ARRIBA con una raiz nueva.
    if (raiz->n == MAX_CLAVES) {
        NodoB* nuevaRaiz = crearNodo(false);
        nuevaRaiz->hijos[0] = raiz;
        dividirHijo(nuevaRaiz, 0);
        insertarNoLleno(nuevaRaiz, clave);
        return nuevaRaiz;
    }

    insertarNoLleno(raiz, clave);
    return raiz;
}

void enOrden(NodoB* nodo) {
    if (nodo == nullptr) return;
    for (int i = 0; i < nodo->n; i++) {
        if (!nodo->esHoja) enOrden(nodo->hijos[i]);
        cout << nodo->claves[i] << " ";
    }
    if (!nodo->esHoja) enOrden(nodo->hijos[nodo->n]);
}

void mostrar(NodoB* nodo, int nivel) {
    if (nodo == nullptr) return;

    for (int i = 0; i < nivel; i++) cout << "      ";
    cout << "[ ";
    for (int i = 0; i < nodo->n; i++) {
        cout << nodo->claves[i];
        if (i < nodo->n - 1) cout << " | ";
    }
    cout << " ]" << endl;

    if (!nodo->esHoja)
        for (int i = 0; i <= nodo->n; i++)
            mostrar(nodo->hijos[i], nivel + 1);
}

// La propiedad que DEFINE al arbol B: todas las hojas en el mismo nivel.
// Devuelve ese nivel, o -1 si encuentra dos hojas en niveles distintos.
int nivelHojas(NodoB* nodo, int nivel) {
    if (nodo == nullptr) return nivel;
    if (nodo->esHoja) return nivel;

    int comun = -1;
    for (int i = 0; i <= nodo->n; i++) {
        int h = nivelHojas(nodo->hijos[i], nivel + 1);
        if (h == -1) return -1;
        if (comun == -1) comun = h;
        else if (comun != h) return -1;
    }
    return comun;
}

void destruir(NodoB* nodo) {
    if (nodo == nullptr) return;
    if (!nodo->esHoja)
        for (int i = 0; i <= nodo->n; i++)
            destruir(nodo->hijos[i]);
    delete nodo;
}

int main() {
    NodoB* raiz = nullptr;

    int datos[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 25};
    for (int i = 0; i < 10; i++) raiz = insertar(raiz, datos[i]);

    cout << "=== Arbol B (T = " << T << ") ===" << endl;
    mostrar(raiz, 0);

    int nivel = nivelHojas(raiz, 0);
    cout << "\nHojas todas en el nivel: "
         << (nivel == -1 ? "NO -> el arbol no es valido" : to_string(nivel))
         << endl;

    cout << "\nEn orden: ";
    enOrden(raiz);
    cout << endl;

    cout << "\nBusquedas:" << endl;
    for (int c : {10, 25, 50, 55, 90, 99})
        cout << "  " << c << " -> " << (buscar(raiz, c) ? "SI" : "NO") << endl;

    destruir(raiz);
    return 0;
}
