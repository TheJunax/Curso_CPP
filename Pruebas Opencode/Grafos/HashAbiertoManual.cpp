/*
    TABLA DISPERSA ABIERTA (direccionamiento abierto) - sin STL.
    Todo en un bloque plano de memoria. Cero punteros dentro del bloque.

    Exploracion lineal: si la cubeta esta ocupada por otro, prueba la
    siguiente: (idx+1) % m, luego (idx+2) % m, ...

    Tres estados: el tercero es el que hace falta por el borrado.
*/

#include <iostream>
using namespace std;

enum class Estado { Vacia, Lapida, Ocupada };

struct Slot {
    int clave;
    int valor;
    Estado estado;
};

Slot* tabla = nullptr;       // new Slot[m] plano
int m = 0;
int cantidad = 0;
int lapidas = 0;

int indice(int clave) {
    int i = clave % m;
    return (i < 0) ? i + m : i;
}

void init(int tam) {
    m = tam;
    cantidad = 0;
    lapidas = 0;
    tabla = new Slot[tam];
    for (int i = 0; i < tam; i++) {
        tabla[i].clave = 0;
        tabla[i].valor = 0;
        tabla[i].estado = Estado::Vacia;
    }
}

// unica funcion que camina la cadena. buscar/insertar/eliminar usan esta.
int recorrer(int clave) {
    int i = indice(clave);
    for (int intento = 0; intento < m; intento++) {
        if (tabla[i].estado == Estado::Vacia) return -1;    // cadena termina
        if (tabla[i].estado == Estado::Ocupada && tabla[i].clave == clave)
            return i;
        i = (i + 1) % m;
    }
    return -1;
}

void colocar(int clave, int valor) {
    int i = indice(clave);
    while (tabla[i].estado == Estado::Ocupada) i = (i + 1) % m;
    tabla[i].clave = clave;
    tabla[i].valor = valor;
    tabla[i].estado = Estado::Ocupada;
}

void crecer() {
    Slot* viejo = tabla;
    int viejoM = m;

    init(viejoM * 2);                        // redibuja desde cero

    for (int i = 0; i < viejoM; i++)         // solo copia las OCUPADAS
        if (viejo[i].estado == Estado::Ocupada) colocar(viejo[i].clave, viejo[i].valor);

    delete[] viejo;                          // las lapidas se pierden aqui
}

void insertar(int clave, int valor) {
    int pos = recorrer(clave);
    if (pos != -1) { tabla[pos].valor = valor; return; }   // ya existe

    colocar(clave, valor);
    cantidad++;

    if ((double)(cantidad + lapidas) / m > 0.75) crecer();  // cuenta lapidas
}

bool buscar(int clave, int& valor) {
    int pos = recorrer(clave);
    if (pos == -1) return false;
    valor = tabla[pos].valor;
    return true;
}

// NO se vacia la casilla: marcarla rompe la cadena y la tabla miente
bool eliminar(int clave) {
    int pos = recorrer(clave);
    if (pos == -1) return false;
    tabla[pos].clave = 0;                    // se limpia el dato...
    tabla[pos].valor = 0;
    tabla[pos].estado = Estado::Lapida;      // ...pero la casilla NO se libera
    cantidad--;
    lapidas++;
    return true;
}

void imprimir() {
    for (int i = 0; i < m; i++) {
        cout << "  [" << i << "] ";
        switch (tabla[i].estado) {
            case Estado::Vacia:   cout << "  ---  ";        break;
            case Estado::Lapida:  cout << "  x   ";         break;
            case Estado::Ocupada: cout << " " << tabla[i].clave
                                       << "=" << tabla[i].valor << " "; break;
        }
        cout << endl;
    }
    cout << "  datos: " << cantidad << "  lapidas: " << lapidas
         << " / " << m << endl;
}

void liberar() { delete[] tabla; tabla = nullptr; }

int main() {
    init(7);

    insertar(3, 30);
    insertar(10, 100);
    insertar(17, 170);

    cout << "== 3 claves que colisionan en la cubeta 3 ==" << endl;
    imprimir();


    int v;
    cout << "\nbuscar(17) -> " << (buscar(17, v) ? v : -1) << endl;

    cout << "\nelimino 10 (el del medio) -> queda LAPIDA" << endl;
    eliminar(10);
    imprimir();


    cout << "buscar(17) -> " << (buscar(17, v) ? v : -1)
         << "   <<< la cadena SIGUE viva" << endl;

    cout << "\n== inyecto hasta forzar crecer() ==" << endl;
    for (int k = 100; k < 106; k++) insertar(k, k);
    imprimir();
    cout << "buscar(17) -> " << (buscar(17, v) ? v : -1)
         << "   <<< y la lapida desaparecio con el rehash" << endl;

    liberar();
    return 0;
}