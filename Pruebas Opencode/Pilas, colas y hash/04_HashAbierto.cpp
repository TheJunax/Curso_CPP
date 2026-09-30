/*
  04 - TABLA DISPERSA, DIRECCIONAMIENTO ABIERTO (Cap. 14, Joyanes)

  Todo en un vector plano, sin punteros. La colision se resuelve rollingando
  a la siguiente casilla. Por eso los datos ESTAN en el arreglo: si se borra
  de verdad, se rompe la cadena. De ahi el tercer estado (LAPIDA).

  Compilar: g++ -Wall -Wextra -g 04_HashAbierto.cpp -o ha
*/

#include <iostream>
#include <iomanip>     // setw, no viene en <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename K, typename V>
class HashAbierto {
private:
    enum class Estado { Vacia, Lapida, Ocupada };

    struct Slot {
        K clave{};
        V valor{};
        Estado estado = Estado::Vacia;
    };

    vector<Slot> tabla;
    int cantidad = 0;
    int lapidas  = 0;

    // std::hash<K> y no hash: asi el nombre no busca la clase plantilla std::hash
    int indice(const K& clave) const { return (int)(std::hash<K>{}(clave) % tabla.size()); }
    int usados() const               { return cantidad + lapidas; }
    double carga() const             { return (double)usados() / (double)tabla.size(); }

    // Recorre la cadena de la clave. Si la encuentra, devuelve su indice; si
    // no, deja en 'libre' el primer hueco donde se puede meter sin romper
    // el invariante (una lapida, o la primera vacia).
    int recorrer(const K& clave, int& libre) const {
        libre = -1;
        int i = indice(clave);
        for (int k = 0; k < (int)tabla.size(); k++) {
            int j = (i + k) % (int)tabla.size();

            if (tabla[j].estado == Estado::Ocupada && tabla[j].clave == clave) return j;
            if (tabla[j].estado == Estado::Lapida && libre == -1) libre = j;
            if (tabla[j].estado == Estado::Vacia) {
                if (libre == -1) libre = j;
                return -1;                    // el invariante: aqui termina la cadena
            }
        }
        return -1;
    }

    // Sin chequeo de carga: asi 'crecer' no se llama a si misma.
    void colocar(const K& clave, const V& valor) {
        int libre;
        int j = recorrer(clave, libre);
        if (j != -1) { tabla[j].valor = valor; return; }

        if (libre == -1) return;
        if (tabla[libre].estado == Estado::Lapida) lapidas--;
        tabla[libre] = Slot{ clave, valor, Estado::Ocupada };
        cantidad++;
    }

    // Al rehashear se redibuja todo desde cero, asi que las lapidas se
    // pierden. Hay que contarlas en la carga porque ocupan casilla para la
    // busqueda, aunque no sean datos.
    void crecer() {
        vector<Slot> viejo = std::move(tabla);
        tabla.assign(viejo.size() * 2, Slot{});
        cantidad = 0; lapidas = 0;
        for (const Slot& s : viejo)
            if (s.estado == Estado::Ocupada) colocar(s.clave, s.valor);
    }

public:
    explicit HashAbierto(int cubetas = 8) { tabla.resize(cubetas); }

    // El chequeo va DESPUES de colocar: si fuera antes, mediria la carga
    // previa y el rehash quedaria pendiente para la proxima insercion.
    void insertar(const K& clave, const V& valor) {
        colocar(clave, valor);
        if (carga() >= 0.7) crecer();
    }

    bool buscar(const K& clave, V& valor) const {
        int libre;
        int j = recorrer(clave, libre);
        if (j == -1) return false;
        valor = tabla[j].valor;
        return true;
    }

    void eliminar(const K& clave) {
        int libre;
        int j = recorrer(clave, libre);
        if (j == -1) return;
        tabla[j].clave.clear();
        tabla[j].valor = V{};
        tabla[j].estado = Estado::Lapida;    // NO se vacia: la cadena debe seguir
        cantidad--; lapidas++;
    }

    void mostrar() const {
        for (int i = 0; i < (int)tabla.size(); i++) {
            cout << "  " << setw(3) << i << " | ";
            if (tabla[i].estado == Estado::Vacia)        cout << "VACIA  " << endl;
            else if (tabla[i].estado == Estado::Lapida) cout << "LAPIDA " << endl;
            else cout << "OCUPADA| " << tabla[i].clave << ":" << tabla[i].valor << endl;
        }
        cout << "  datos=" << cantidad << "  lapidas=" << lapidas
             << "  cubetas=" << tabla.size() << "  carga=" << carga() << endl;
    }
};

// ===========================================================================

int main() {
    HashAbierto<string, int> h(8);
    int v;

    cout << "1) Ana, Luis y Mia colisionan en la cubeta 7\n";
    h.insertar("Ana", 1); h.insertar("Luis", 2); h.insertar("Mia", 3);
    h.mostrar();

    cout << "\n2) Se borra Luis, que esta EN MEDIO de la cadena\n";
    h.eliminar("Luis");
    h.mostrar();
    cout << "  buscar Mia -> " << (h.buscar("Mia", v) ? v : -1)
         << "   (sigue: la 0 es LAPIDA, no VACIA)\n";
    cout << "  si la 0 se vaciara, la busqueda pararia ahi y Mia seria\n"
         << "  INALCANZABLE: el dato existe pero la tabla no lo encuentra\n";

    cout << "\n3) La carga sube por las lapidas, no solo por los datos\n";
    h.insertar("Beto", 4); h.insertar("n", 5);
    h.mostrar();
    h.insertar("p", 6);
    cout << "  al meter p se llego a 0.75 -> crecer():\n";
    h.mostrar();
    cout << "  la lapida de la 0 desaparecio y Ana cambio de cubeta:\n"
         << "  al rehashear el modulo es otro, TODO se recalcula\n";

    cout << "\n4) La misma plantilla con int\n";
    HashAbierto<int, string> h2(5);
    for (int i = 1; i <= 8; i++) h2.insertar(i * 3, "v" + to_string(i));
    string s;
    h2.mostrar();
    cout << "  buscar 9 -> "  << (h2.buscar(9, s)  ? s : "NO")
         << "     buscar 10 -> " << (h2.buscar(10, s) ? s : "NO") << endl;

    return 0;
}
