// HashEncadenado.cpp — Tabla de dispersión con DIRECCIONAMIENTO ENCADENADO
// (Cap. 14, Joyanes). Cada cubeta es una lista; las colisiones se resuelven
// metiendo el par en la lista de su cubeta.
//
// Compilar: g++ -Wall -Wextra -g HashEncadenado.cpp -o HashEncadenado

#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <functional>   // std::hash
#include <utility>     // std::pair, std::move

using namespace std;

// ---------------------------------------------------------------------------
// Una función de dispersión "de juguete": el PLEGAMIENTO.
// Suma los códigos de los caracteres y se queda con el resto al dividir.
// Es la técnica más fácil de implementar y la que más colisiones produce:
// "abc" y "cba" suman EXACTAMENTE lo mismo, siempre.
// ---------------------------------------------------------------------------
int plegamiento(const string& clave, int tamano) {
    int suma = 0;
    for (char c : clave) {
        suma += static_cast<unsigned char>(c);   // sin el cast, los negativos
    }                                             // arruinan la suma
    return suma % tamano;
}

// ---------------------------------------------------------------------------
// TablaHash<K,V> — cubetas de tipo list<pair<K,V>>
//
// RAII: no hay destructor, nada que liberar. El vector owns las listas y
// cada lista owns sus pares. Es el MISMO argumento de la Sesión 25
// (unique_ptr en lista enlazada) aplicado a la STL.
// ---------------------------------------------------------------------------
template <typename K, typename V>
class TablaHash {
private:
    vector<list<pair<K, V>>> cubetas;
    size_t cantidad = 0;          // cuántas claves hay guardadas

public:
    // El ?: en la lista de inicialización evita la división por cero en
    // indice() si alguien pide 0 cubetas (indice() hace % cubetas.size()).
    explicit TablaHash(size_t numCubetas)
        : cubetas(numCubetas == 0 ? 1 : numCubetas) {}

    // --- La función de dispersión, aislada en un solo sitio -----------------
    // Cambiar TODO el comportamiento de la tabla es cambiar estas 2 líneas.
    size_t indice(const K& clave) const {
        return hash<K>{}(clave) % cubetas.size();
    }

    // α = claves / cubetas. El número que decide cuándo hay que crecer.
    double factorCarga() const {
        return static_cast<double>(cantidad) / static_cast<double>(cubetas.size());
    }

    size_t tamano() const { return cantidad; }
    size_t numCubetas() const { return cubetas.size(); }

    void insertar(const K& clave, const V& valor) {
        list<pair<K, V>>& cubeta = cubetas[indice(clave)];

        // ¿Ya existe la clave? Entonces es una ACTUALIZACIÓN, no una inserción.
        for (pair<K, V>& par : cubeta) {
            if (par.first == clave) {
                par.second = valor;
                return;
            }
        }

        // No existía: aquí termina la COLISIÓN. El par se apila en la lista
        // de su cubeta y listo. No hay que hacer nada especial.
        cubeta.push_back(pair<K, V>(clave, valor));
        ++cantidad;

        if (factorCarga() > 1.0) {
            crecer();
        }
    }

    // Mismo patrón que Pila<T>::sacar (Sesión 26): bool + referencia de
    // salida. Nunca devolvemos una referencia que se pueda quedar colgando
    // ni confundimos "no está" con un valor válido.
    bool buscar(const K& clave, V& valor) const {
        const list<pair<K, V>>& cubeta = cubetas[indice(clave)];
        for (const pair<K, V>& par : cubeta) {
            if (par.first == clave) {
                valor = par.second;
                return true;
            }
        }
        return false;
    }

    bool eliminar(const K& clave) {
        list<pair<K, V>>& cubeta = cubetas[indice(clave)];
        for (auto it = cubeta.begin(); it != cubeta.end(); ++it) {
            if (it->first == clave) {
                cubeta.erase(it);      // la lista se encarga de liberar
                --cantidad;
                return true;
            }
        }
        return false;
    }

    // Duplica las cubetas y redistribuye. Los índices cambian porque el
    // módulo es otro, así que TODO se recalcula. Solo por eso es válido.
    void crecer() {
        vector<list<pair<K, V>>> nuevas(cubetas.size() * 2);
        for (list<pair<K, V>>& cubeta : cubetas) {
            for (pair<K, V>& par : cubeta) {
                size_t nuevoIndice = hash<K>{}(par.first) % nuevas.size();
                nuevas[nuevoIndice].push_back(std::move(par));
            }
        }
        cubetas = std::move(nuevas);
    }

    // Para ver el interior. En un examen esto no se imprime, pero sin esto
    // las colisiones son invisibles y no hay forma de creerle al código.
    void imprimirEstructura() const {
        cout << "  (" << numCubetas() << " cubetas)\n";
        for (size_t i = 0; i < cubetas.size(); ++i) {
            cout << "    [" << i << "] ";
            if (cubetas[i].empty()) {
                cout << "(vacia)\n";
                continue;
            }
            cout << "-> ";
            for (const pair<K, V>& par : cubetas[i]) {
                cout << par.first << "(" << par.second << ")  ";
            }
            cout << " [longitud " << cubetas[i].size() << "]\n";
        }
    }
};

// ===========================================================================
int main() {
    cout << "==============================================\n";
    cout << "1. Tabla con std::hash (buena dispersion)\n";
    cout << "==============================================\n";

    TablaHash<string, int> notas(7);

    notas.insertar("Ana", 85);
    notas.insertar("Luis", 70);
    notas.insertar("Maria", 95);
    notas.insertar("Carlos", 60);
    notas.insertar("Sofia", 88);
    notas.insertar("Diego", 73);
    notas.insertar("Juan", 91);

    cout << "Despues de insertar 7 claves en 7 cubetas:\n";
    notas.imprimirEstructura();
    cout << "  factor de carga = " << notas.factorCarga() << "\n\n";

    cout << "Ahora metemos 5 mas: 12 claves en 7 cubetas, "
         << "alpha pasa de 1 -> crece()):\n";
    notas.insertar("Pedro", 55);
    notas.insertar("Pablo", 79);
    notas.insertar("Lucia", 84);
    notas.insertar("Tomas", 66);
    notas.insertar("Sara", 97);
    notas.imprimirEstructura();
    cout << "  factor de carga = " << notas.factorCarga() << "\n\n";

    // --- Actualizar no es insertar -----------------------------------------
    cout << "Actualizar a Ana de 85 a 99 (misma clave):\n";
    notas.insertar("Ana", 99);
    int valor = 0;
    notas.buscar("Ana", valor);
    cout << "  Ana ahora vale " << valor
         << "  |  numero de claves = " << notas.tamano() << " (NO CRECIO)\n\n";

    // --- Buscar y fallar ---------------------------------------------------
    // OJO: {"Ana","Sara",...} es un initializer_list<const char*>, NO de
    // string. Si escribes `for (const string& n : {...})` se construye un
    // std::string TEMPORAL en cada vuelta y g++ lo avisa con
    // -Wrange-loop-construct (mismo día que minimo("Ana","Zoe") en la
    // Sesion 25: la lista es de const char*, no de lo que uno cree).
    cout << "Buscar:\n";
    const char* nombres[] = {"Ana", "Sara", "Juan", "Ximena"};
    for (const char* nombre : nombres) {
        if (notas.buscar(string(nombre), valor)) {
            cout << "  " << nombre << " -> " << valor << "\n";
        } else {
            cout << "  " << nombre << " -> NO ESTA\n";
        }
    }

    cout << "\nEliminar a Luis y volver a buscarlo:\n";
    cout << "  eliminar(Luis) = " << notas.eliminar("Luis") << "\n";
    cout << "  eliminar(Luis) = " << notas.eliminar("Luis") << " (ya no estaba)\n";
    notas.buscar("Luis", valor);
    cout << "  claves ahora = " << notas.tamano() << "\n\n";

    // =====================================================================
    cout << "==============================================\n";
    cout << "2. El MISMO codigo con una dispersion MALA\n";
    cout << "==============================================\n";

    // Anagramas: "abc", "bca", "cab" suman 294 las tres.
    cout << "plegamiento(\"abc\") % 10 = " << plegamiento("abc", 10) << "\n";
    cout << "plegamiento(\"bca\") % 10 = " << plegamiento("bca", 10) << "\n";
    cout << "plegamiento(\"cab\") % 10 = " << plegamiento("cab", 10) << "\n";
    cout << "-> misma cubeta SIEMPRE. Con std::hash si se separan:\n";
    cout << "   std::hash(\"abc\") % 10 = " << hash<string>{}("abc") % 10 << "\n";
    cout << "   std::hash(\"bca\") % 10 = " << hash<string>{}("bca") % 10 << "\n";
    cout << "   std::hash(\"cab\") % 10 = " << hash<string>{}("cab") % 10 << "\n\n";

    // Simulacion: misma tabla, misma logica, pero con plegamiento.
    // Se ve como se desploma cuando la funcion es mala.
    const int CUBETAS = 10;
    vector<int> ocupacion(CUBETAS, 0);
    const string palabras[] = {"abc", "bca", "cab", "acb", "bac", "cba"};
    for (const string& p : palabras) {
        ocupacion[plegamiento(p, CUBETAS)]++;
    }
    cout << "6 anagramas en " << CUBETAS << " cubetas con plegamiento:\n";
    for (int i = 0; i < CUBETAS; ++i) {
        cout << "  [" << i << "] " << ocupacion[i]
             << (ocupacion[i] > 1 ? "   <-- 6 claves peleandose por una cubeta" : "")
             << "\n";
    }

    return 0;
}
