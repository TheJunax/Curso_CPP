// HashCache.cpp — ¿Por que la direccionamiento abierto suele ganar?
//
// Compara las DOS tablas con la MISMA cantidad de claves, el MISMO factor
// de carga y la MISMA funcion de dispersion. Lo unico que cambia es DONDE
// viven los datos en memoria:
//
//   encadenada -> cada cubeta es una lista en el heap, los datos estan
//                 dispersos (cada nodo en una direccion de memoria distinta)
//   abierta    -> un solo vector<Slot>, los datos van PEGADOS uno tras otro
//
// Compilar: g++ -Wall -Wextra -g HashCache.cpp -o HashCache

#include <chrono>
#include <functional>
#include <iomanip>    // setw, setprecision
#include <iostream>
#include <list>
#include <random>
#include <vector>
using namespace std;

using Reloj = chrono::steady_clock;

class TablaEncadenada {
    vector<list<pair<int, int>>> cubetas;
    size_t indice(int k) const {
        return hash<int>{}(static_cast<unsigned>(k)) % cubetas.size();
    }
public:
    explicit TablaEncadenada(size_t m) : cubetas(m) {}
    void insertar(int k, int v) {
        list<pair<int, int>>& c = cubetas[indice(k)];
        for (pair<int, int>& p : c) {
            if (p.first == k) { p.second = v; return; }
        }
        c.push_back({k, v});
    }
    bool buscar(int k, int& v) const {
        for (const pair<int, int>& p : cubetas[indice(k)]) {
            if (p.first == k) { v = p.second; return true; }
        }
        return false;
    }
};

class TablaAbierta {
    struct Slot { int clave = -1; int valor = 0; bool ocupada = false; };
    vector<Slot> tabla;
    size_t indice(int k) const {
        return hash<int>{}(static_cast<unsigned>(k)) % tabla.size();
    }
public:
    explicit TablaAbierta(size_t m) : tabla(m) {}
    void insertar(int k, int v) {
        size_t i = indice(k);
        while (tabla[i].ocupada) {
            if (tabla[i].clave == k) { tabla[i].valor = v; return; }
            i = (i + 1) % tabla.size();
        }
        tabla[i].clave = k; tabla[i].valor = v; tabla[i].ocupada = true;
    }
    bool buscar(int k, int& v) const {
        size_t i = indice(k);
        while (tabla[i].ocupada) {
            if (tabla[i].clave == k) { v = tabla[i].valor; return true; }
            i = (i + 1) % tabla.size();
        }
        return false;
    }
};

int main() {
    const int N = 200000;               // claves
    const int M = 2 * N;                // cubetas -> factor de carga 0.5
    const int CONSULTAS = 3000000;      // busquedas cronometradas

    TablaEncadenada enc(M);
    TablaAbierta  abi(M);

    // --- Insercion ---------------------------------------------------------
    auto t0 = Reloj::now();
    for (int i = 0; i < N; ++i) { enc.insertar(i, i * 2); }
    auto t1 = Reloj::now();
    for (int i = 0; i < N; ++i) { abi.insertar(i, i * 2); }
    auto t2 = Reloj::now();

    // --- Consultas sobre claves que SI existen (aciertos) ------------------
    // Semilla fija: los mismos numeros en las dos tablas, siempre.
    mt19937 rng(12345);
    uniform_int_distribution<int> dist(0, N - 1);
    vector<int> consultas(CONSULTAS);
    for (int& x : consultas) x = dist(rng);

    long long sumaEnc = 0, sumaAbi = 0;
    int valor = 0;

    auto t3 = Reloj::now();
    for (int k : consultas) { if (enc.buscar(k, valor)) sumaEnc += valor; }
    auto t4 = Reloj::now();
    for (int k : consultas) { if (abi.buscar(k, valor)) sumaAbi += valor; }
    auto t5 = Reloj::now();

    auto ms = [](Reloj::time_point a, Reloj::time_point b) {
        return chrono::duration_cast<chrono::microseconds>(b - a).count();
    };

    cout << N << " claves, " << M << " cubetas (alpha 0.5), "
         << CONSULTAS << " busquedas con acierto\n\n";

    cout << "  -------------------------------------------\n";
    cout << "  encadenada:  " << setw(8) << ms(t0, t1) / 1000.0
         << " ms | " << setw(9) << ms(t3, t4) / 1000.0 << " ms\n";
    cout << "  abierta:     " << setw(8) << ms(t1, t2) / 1000.0
         << " ms | " << setw(9) << ms(t4, t5) / 1000.0 << " ms\n";
    cout << "  -------------------------------------------\n";

    double cIns = ms(t0, t1), cCon = ms(t3, t4);
    double aIns = ms(t1, t2), aCon = ms(t4, t5);
    if (aCon > 0) {
        cout << "  La abierta consulto " << fixed << setprecision(2)
             << (cCon / aCon) << "x mas rapido\n";
    }
    if (aIns > 0) {
        cout << "  La abierta inserto  " << setprecision(2)
             << (cIns / aIns) << "x mas rapido\n";
    }

    cout << "\n  (verificacion: ambas encontraron lo mismo -> "
         << (sumaEnc == sumaAbi ? "OK" : "ERROR") << ")\n";
    cout << "  La diferencia NO es de complejidad: las dos son O(1).\n";
    cout << "  Es la CONSTANTE: en la encadenada cada busqueda salta a un\n";
    cout << "  nodo del heap (fallo de cache). En la abierta, los datos\n";
    cout << "  estan contiguos y el hardware los trae en linea.\n";

    return 0;
}
