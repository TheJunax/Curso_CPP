/*
    ARBOL B - perfil limpio del material del profe (05_arbol_b.cpp).

    Mismo algoritmo y misma salida, sin el "Despues de insertar N:" de cada
    paso. Sirve para comparar linea por linea con ArbolBPropio.cpp y ver
    QUE HIZO CADA UNO.

    Lo que cambia respecto a la version del profe:
      - el main imprime una sola vez al final
      - se agregan las busquedas de 55, 10 y 99
      - se agrega la verificacion de que todas las hojas queden al mismo nivel
*/

#include <iostream>
using namespace std;

const int T = 2;                    // grado minimo
const int MAX_CLAVES = 2 * T - 1;   // 3 claves como maximo
const int MAX_HIJOS  = 2 * T;       // 4 hijos como maximo

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

// En cada nodo se recorren las claves: si esta, listo;
// si no, se baja por el hijo que corresponde.
bool buscar(NodoB* nodo, int clave) {
    if (nodo == nullptr) return false;

    int i = 0;
    while (i < nodo->n && clave > nodo->claves[i]) i++;

    if (i < nodo->n && clave == nodo->claves[i]) return true;   // encontrada
    if (nodo->esHoja) return false;                             // no hay mas donde buscar

    return buscar(nodo->hijos[i], clave);                       // bajar al hijo i
}

// Divide el hijo numero i del padre (ese hijo esta lleno).
//
//   Antes:  padre [ .. | .. ]         hijo lleno [ A | B | C ]
//   Despues: B sube al padre, queda [A] a la izquierda
//            y [C] en un nodo nuevo a la derecha.
void dividirHijo(NodoB* padre, int i) {
    NodoB* lleno = padre->hijos[i];
    NodoB* nuevo = crearNodo(lleno->esHoja);

    // 1) El nodo nuevo se queda con la mitad derecha de las claves
    nuevo->n = T - 1;
    for (int j = 0; j < T - 1; j++)
        nuevo->claves[j] = lleno->claves[j + T];

    // 2) Si no es hoja, tambien se lleva la mitad derecha de los hijos
    if (!lleno->esHoja) {
        for (int j = 0; j < T; j++) {
            nuevo->hijos[j] = lleno->hijos[j + T];
            lleno->hijos[j + T] = nullptr;
        }
    }

    // 3) El nodo lleno se queda con la mitad izquierda
    lleno->n = T - 1;

    // 4) Correr los hijos del padre para hacer espacio al nuevo
    for (int j = padre->n; j >= i + 1; j--)
        padre->hijos[j + 1] = padre->hijos[j];
    padre->hijos[i + 1] = nuevo;

    // 5) Correr las claves del padre y subir la clave del medio
    for (int j = padre->n - 1; j >= i; j--)
        padre->claves[j + 1] = padre->claves[j];
    padre->claves[i] = lleno->claves[T - 1];
    padre->n++;
}

// Inserta en un nodo que sabemos que NO esta lleno
void insertarNoLleno(NodoB* nodo, int clave) {
    int i = nodo->n - 1;

    if (nodo->esHoja) {
        // Correr las claves mayores una posicion y meter la nueva
        while (i >= 0 && clave < nodo->claves[i]) {
            nodo->claves[i + 1] = nodo->claves[i];
            i--;
        }
        nodo->claves[i + 1] = clave;
        nodo->n++;
    }
    else {
        // Buscar por que hijo hay que bajar
        while (i >= 0 && clave < nodo->claves[i]) i--;
        i++;

        // Si ese hijo esta lleno, se parte antes de bajar
        if (nodo->hijos[i]->n == MAX_CLAVES) {
            dividirHijo(nodo, i);
            // Despues de partir, ver si hay que ir al hijo de la derecha
            if (clave > nodo->claves[i]) i++;
        }
        insertarNoLleno(nodo->hijos[i], clave);
    }
}

// Uso:  raiz = insertar(raiz, clave);
// Si la raiz esta llena, se parte y el arbol crece hacia ARRIBA.
NodoB* insertar(NodoB* raiz, int clave) {
    if (buscar(raiz, clave)) return raiz;      // no se permiten repetidos

    // Arbol vacio
    if (raiz == nullptr) {
        raiz = crearNodo(true);
        raiz->claves[0] = clave;
        raiz->n = 1;
        return raiz;
    }

    // Raiz llena: se crea una raiz nueva arriba
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

// Recorrido en orden (imprime las claves ordenadas)
void enOrden(NodoB* nodo) {
    if (nodo == nullptr) return;
    for (int i = 0; i < nodo->n; i++) {
        if (!nodo->esHoja) enOrden(nodo->hijos[i]);
        cout << nodo->claves[i] << " ";
    }
    if (!nodo->esHoja) enOrden(nodo->hijos[nodo->n]);
}

// Muestra el arbol con sangria: cada nivel mas a la derecha
void mostrar(NodoB* nodo, int nivel) {
    if (nodo == nullptr) return;

    for (int i = 0; i < nivel; i++) cout << "      ";
    cout << "[ ";
    for (int i = 0; i < nodo->n; i++) {
        cout << nodo->claves[i];
        if (i < nodo->n - 1) cout << " | ";
    }
    cout << " ]" << endl;

    if (!nodo->esHoja) {
        for (int i = 0; i <= nodo->n; i++)
            mostrar(nodo->hijos[i], nivel + 1);
    }
}

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
    if (!nodo->esHoja) {
        for (int i = 0; i <= nodo->n; i++) destruir(nodo->hijos[i]);
    }
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
