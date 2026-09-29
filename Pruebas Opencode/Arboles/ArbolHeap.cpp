/*
=====================================================================
  04 - ARBOL GUARDADO EN UN ARREGLO  +  MONTICULO (HEAP)
---------------------------------------------------------------------
  Un arbol binario COMPLETO se puede guardar en un arreglo,
  sin punteros. Para el nodo en la posicion i:

      hijo izquierdo -> 2*i + 1
      hijo derecho   -> 2*i + 2
      padre          -> (i - 1) / 2

  El HEAP (monticulo) de maximos es un arbol asi donde
  cada padre es MAYOR que sus hijos. El maximo siempre
  queda en la posicion 0 (la raiz).

  Se usa para colas de prioridad y para ordenar (heapsort).

  Compilar:  g++ 04_arbol_en_arreglo_y_heap.cpp -o heap
=====================================================================
*/
#include <iostream>
using namespace std;

const int MAX = 100;

int heap[MAX];      // el arbol guardado en arreglo
int cantidad = 0;   // cuantos elementos hay

void intercambiar(int i, int j) {
    int temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

// ------------------------------------------------------------
//  INSERTAR: se pone al final y se "sube" mientras sea
//  mayor que su padre.
// ------------------------------------------------------------
void insertar(int valor) {
    if (cantidad == MAX) {
        cout << "Heap lleno" << endl;
        return;
    }

    int i = cantidad;
    heap[i] = valor;
    cantidad++;

    // subir
    while (i > 0) {
        int padre = (i - 1) / 2;
        if (heap[i] > heap[padre]) {
            intercambiar(i, padre);
            i = padre;
        } else {
            break;
        }
    }
}

// ------------------------------------------------------------
//  EXTRAER EL MAXIMO: se saca la raiz, se pone el ultimo
//  elemento arriba y se "baja" cambiandolo por su hijo mayor.
// ------------------------------------------------------------
int extraerMaximo() {
    if (cantidad == 0) {
        cout << "Heap vacio" << endl;
        return -1;
    }

    int maximo = heap[0];
    heap[0] = heap[cantidad - 1];
    cantidad--;

    // bajar
    int i = 0;
    while (true) {
        int izq = 2 * i + 1;
        int der = 2 * i + 2;
        int mayorPos = i;

        if (izq < cantidad && heap[izq] > heap[mayorPos]) mayorPos = izq;
        if (der < cantidad && heap[der] > heap[mayorPos]) mayorPos = der;

        if (mayorPos == i) break;       // ya esta en su lugar

        intercambiar(i, mayorPos);
        i = mayorPos;
    }
    return maximo;
}

void mostrarArreglo() {
    cout << "Arreglo: ";
    for (int i = 0; i < cantidad; i++) cout << "[" << heap[i] << "] ";
    cout << endl;
}

// Muestra el arbol por niveles: nivel 0 tiene 1 nodo, nivel 1 tiene 2, nivel 2 tiene 4...
void mostrarPorNiveles() {
    int enEsteNivel = 1;
    int contador = 0;
    for (int i = 0; i < cantidad; i++) {
        cout << heap[i] << " ";
        contador++;
        if (contador == enEsteNivel) {
            cout << endl;
            enEsteNivel = enEsteNivel * 2;
            contador = 0;
        }
    }
    cout << endl;
}

// ------------------------------------------------------------
int main() {
    // ---- Parte 1: arbol cualquiera guardado en arreglo ----
    /*
            P
           / \
          Q   R
         / \
        S   T
    */
    char arbol[] = {'P', 'Q', 'R', 'S', 'T'};
    int n = 5;

    cout << "=== Arbol en arreglo ===" << endl;
    for (int i = 0; i < n; i++) {
        cout << arbol[i] << ": ";
        if (i > 0)          cout << "padre=" << arbol[(i - 1) / 2] << " ";
        if (2 * i + 1 < n)  cout << "izq=" << arbol[2 * i + 1] << " ";
        if (2 * i + 2 < n)  cout << "der=" << arbol[2 * i + 2] << " ";
        cout << endl;
    }

    // ---- Parte 2: heap ----
    cout << endl << "=== Heap de maximos ===" << endl;
    int datos[] = {40, 10, 30, 50, 20, 60, 5};
    for (int i = 0; i < 7; i++) insertar(datos[i]);

    mostrarArreglo();
    cout << "Como arbol:" << endl;
    mostrarPorNiveles();

    cout << "Extraer maximo: " << extraerMaximo() << endl;
    mostrarArreglo();

    // ---- Parte 3: heapsort (sacar todo en orden) ----
    cout << endl << "Sacando todo (queda de mayor a menor): ";
    while (cantidad > 0) cout << extraerMaximo() << " ";
    cout << endl;

    return 0;
}
