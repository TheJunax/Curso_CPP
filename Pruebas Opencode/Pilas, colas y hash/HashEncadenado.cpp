/*
  HashEncadenado.cpp - Tabla de dispersión con direccionamiento ENCADENADO
  (Cap. 14, Joyanes). Cada cubeta es una lista; la colisión se resuelve
  metiendo el par en la lista de su cubeta.

  Compilar: g++ -Wall -Wextra -g HashEncadenado.cpp -o he
*/

#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <functional>
#include <utility>
using namespace std;

// PLEGAMIENTO: suma los códigos de los caracteres. Es la técnica más fácil
// y la que más colisiones produce: "abc" y "cba" suman EXACTAMENTE lo mismo.
int plegamiento(const string& clave, int tamano) {
    int suma = 0;
    for (char c : clave) suma += static_cast<unsigned char>(c);   // sin el cast, los
    return suma % tamano;                                         // negativos arruinan
}

template <typename K, typename V>
class TablaHash {
private:
    vector<list<pair<K, V>>> cubetas;
    size_t cantidad = 0;

public:
    // El ?: evita la división por cero en indice() si alguien pide 0 cubetas.
    explicit TablaHash(size_t numCubetas)
        : cubetas(numCubetas == 0 ? 1 : numCubetas) {}

    size_t indice(const K& clave) const { return hash<K>{}(clave) % cubetas.size(); }

    double factorCarga() const {
        return (double)cantidad / (double)cubetas.size();
    }

    size_t tamano() const     { return cantidad; }
    size_t numCubetas() const { return cubetas.size(); }

    void insertar(const K& clave, const V& valor) {
        list<pair<K, V>>& cubeta = cubetas[indice(clave)];

        for (pair<K, V>& par : cubeta)          // si ya existe, es ACTUALIZACIÓN
            if (par.first == clave) { par.second = valor; return; }

        // No existía: aquí termina la colisión. El par se apila y listo.
        cubeta.push_back(pair<K, V>(clave, valor));
        ++cantidad;
        if (factorCarga() > 1.0) crecer();
    }

    // Mismo patrón que Pila<T>::sacar: bool + referencia de salida, para no
    // devolver una referencia colgante ni confundir "no está" con un valor.
    bool buscar(const K& clave, V& valor) const {
        const list<pair<K, V>>& cubeta = cubetas[indice(clave)];
        for (const pair<K, V>& par : cubeta)
            if (par.first == clave) { valor = par.second; return true; }
        return false;
    }

    bool eliminar(const K& clave) {
        list<pair<K, V>>& cubeta = cubetas[indice(clave)];
        for (auto it = cubeta.begin(); it != cubeta.end(); ++it)
            if (it->first == clave) {
                cubeta.erase(it);               // la lista se encarga de liberar
                --cantidad;
                return true;
            }
        return false;
    }

    // Los índices cambian porque el módulo es otro, así que TODO se recalcula.
    void crecer() {
        vector<list<pair<K, V>>> nuevas(cubetas.size() * 2);
        for (list<pair<K, V>>& cubeta : cubetas)
            for (pair<K, V>& par : cubeta)
                nuevas[hash<K>{}(par.first) % nuevas.size()].push_back(std::move(par));
        cubetas = std::move(nuevas);
    }

    // Sin esto las colisiones son invisibles.
    void imprimirEstructura() const {
        for (size_t i = 0; i < cubetas.size(); ++i) {
            cout << "  [" << i << "] ";
            if (cubetas[i].empty()) { cout << "(vacia)\n"; continue; }
            cout << "-> ";
            for (const pair<K, V>& par : cubetas[i]) cout << par.first << "(" << par.second << ")  ";
            cout << " [long " << cubetas[i].size() << "]\n";
        }
    }
};

// ===========================================================================

int main() {
    TablaHash<string, int> notas(7);

    cout << "1) 7 claves en 7 cubetas (alpha = 1)\n";
    notas.insertar("Ana", 85);    notas.insertar("Luis", 70);
    notas.insertar("Maria", 95);  notas.insertar("Carlos", 60);
    notas.insertar("Sofia", 88);  notas.insertar("Diego", 73);
    notas.insertar("Juan", 91);
    notas.imprimirEstructura();
    cout << "  carga = " << notas.factorCarga() << "\n";

    cout << "\n2) Metemos 5 mas: alpha pasa de 1 -> crece() y TODO cambia de cubeta\n";
    notas.insertar("Pedro", 55);  notas.insertar("Pablo", 79);
    notas.insertar("Lucia", 84);  notas.insertar("Tomas", 66);
    notas.insertar("Sara", 97);
    notas.imprimirEstructura();
    cout << "  carga = " << notas.factorCarga() << "\n";

    cout << "\n3) Actualizar NO es insertar\n";
    notas.insertar("Ana", 99);
    int valor = 0;
    notas.buscar("Ana", valor);
    cout << "  Ana ahora vale " << valor << "   |   claves = " << notas.tamano()
         << " (no crecio)\n";

    cout << "\n4) Buscar\n";
    // const char* y no string: {"Ana","Sara"} es un initializer_list<const char*>,
    // y con `const string&` se construye un string temporal en cada vuelta
    // (mismo dia que minimo("Ana","Zoe") en la Sesion 25).
    const char* nombres[] = {"Ana", "Sara", "Juan", "Ximena"};
    for (const char* nombre : nombres)
        cout << "  " << nombre << " -> "
             << (notas.buscar(string(nombre), valor) ? to_string(valor) : "NO ESTA") << "\n";

    cout << "\n5) Eliminar\n";
    cout << "  eliminar(Luis) = " << notas.eliminar("Luis") << "\n";
    cout << "  eliminar(Luis) = " << notas.eliminar("Luis") << "  (ya no estaba)\n";
    cout << "  claves = " << notas.tamano()
         << "   <-- NO hizo falta lapida: la lista se encargo\n";

    cout << "\n6) El mismo codigo con una dispersion MALA\n";
    for (const char* p : {"abc", "bca", "cab"}) {
        cout << "  plegamiento(\"" << p << "\") % 10 = " << plegamiento(p, 10)
             << "    std::hash % 10 = " << hash<string>{}(p) % 10 << "\n";
    }
    cout << "  los tres anagramas caen SIEMPRE en la misma cubeta\n";

    const int CUBETAS = 10;
    vector<int> ocupacion(CUBETAS, 0);
    const string palabras[] = {"abc", "bca", "cab", "acb", "bac", "cba"};
    for (const string& p : palabras) ocupacion[plegamiento(p, CUBETAS)]++;
    cout << "  6 anagramas en " << CUBETAS << " cubetas con plegamiento:\n";
    for (int i = 0; i < CUBETAS; ++i)
        cout << "  [" << i << "] " << ocupacion[i]
             << (ocupacion[i] > 1 ? "   <-- todos peleandose por una cubeta\n" : "\n");

    return 0;
}
