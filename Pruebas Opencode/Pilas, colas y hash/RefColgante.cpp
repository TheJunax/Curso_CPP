// RefColgante.cpp — Por que una referencia NO garantiza que apunte a algo vivo.
//
// Idea central: la referencia garantiza la DIRECCION, no la VIDA.
// "No se cuelga" es cierto; "sigue sirviendo para algo" es otra frase.
//
// Compilar: g++ -Wall -Wextra -g RefColgante.cpp -o RefColgante
// Valgrind:  valgrind -q --error-exitcode=9 ./RefColgante

#include <iostream>
#include <string>
using namespace std;

// Copia de la Pila de la Sesion 26, tal cual (NO se toco Pila.cpp).
// cima() NO tiene guarda de pila vacia a proposito: es una PRECONDICION.
template <typename T>
class Pila {
private:
    T* datos;
    int capacidad;
    int tope;
public:
    Pila(int cap) : datos(new T[cap]), capacidad(cap), tope(-1) {}
    ~Pila() { delete[] datos; }              // el dueno del bloque

    bool meter(const T& valor) {
        if ((tope + 1) == capacidad) return false;
        datos[tope + 1] = valor;
        tope++;
        return true;
    }
    bool sacar(T& valor) {
        if (tope == -1) return false;
        valor = datos[tope];
        tope--;
        return true;
    }
    T& cima() { return datos[tope]; }
    const T& cima() const { return datos[tope]; }
    bool estaVacia() const { return tope == -1; }
    int tamano() const { return tope + 1; }
};

// Funcion "poco elegante" que devuelve la referencia: el patron clasico
// de la referencia colgante. Devuelve T&, no T, y el objeto se muere.
int& cimaDe(Pila<int>& p) { return p.cima(); }

int main() {
    // =====================================================================
    cout << "=== 1. La intucion de Juan: la DIRECCION es real ===\n";
    // =====================================================================
    {
        Pila<int> p(5);
        p.meter(1); p.meter(2); p.meter(3);

        int& r = p.cima();
        cout << "  r apunta a " << (void*)&r << " y vale " << r << "\n";
        cout << "  (datos[2] esta live: la pila sigue viva, el bloque existe)\n";
        cout << "-> Si, la direccion es real. Juan tiene razon en ESTO.\n\n";
    }

    // =====================================================================
    cout << "=== 2. La direccion no cambia. El VALOR si. ===\n";
    cout << "    (mismo objeto, mismo nombre, otro contenido)\n";
    // =====================================================================
    {
        Pila<int> p(5);
        p.meter(1); p.meter(2); p.meter(3);

        int& r = p.cima();
        cout << "  r = " << r << "  (r apunta a datos[2])\n";

        int x;
        p.sacar(x); p.sacar(x); p.sacar(x);   // vaciamos
        cout << "  pila vacia.  r = " << r << " (el 3 sigue en memoria)\n";

        p.meter(10); p.meter(20); p.meter(30);  // rellenamos de nuevo
        cout << "  pila llena de nuevo. r = " << r << "  <-- CAMBIO SOLO\n";
        cout << "  Nadie toco a r. r no cambio de direccion.\n";
        cout << "  La Misma referencia, dos contenidos distintos.\n\n";
    }

    // =====================================================================
    cout << "=== 3. El objeto MUERTO con la memoria viva (el peor caso) ===\n";
    cout << "    con int no se nota. con std::string, si.\n";
    // =====================================================================
    {
        Pila<string> ps(3);
        ps.meter("uno"); ps.meter("dos"); ps.meter("tres");

        // OJO LA DIFERENCIA DE UNA PALABRA:
        //   string& v = ps.cima();   -> COPIA (el temporal se materializa)
        //   auto&&  v = ps.cima();   -> ALIAS PURO (nada se materializa)
        auto&& alias = ps.cima();
        cout << "  auto&& alias = " << alias << " (alias puro a datos[2])\n";

        // Hay que vaciar la pila COMPLETA. Si solo sacamos uno, quedan
        // 2 huecos y 2 de los 3 'meter' de abajo devuelven false
        // (no se meten) -- datos[2] nunca se sobreescribe y la demo miente.
        string texto;
        while (ps.sacar(texto)) {}    // los 3. Ojo al return de meter.
        cout << "  pila vacia (" << ps.tamano() << " elementos)\n";

        ps.meter("X"); ps.meter("Y"); ps.meter("Z");  // datos[2] = "Z"
        cout << "  alias = " << alias << "  <-- el objeto en esa direccion\n";
        cout << "  MURIO en el 'meter' (el string viejo fue destruido) y\n";
        cout << "  NACIO otro. alias no se entero: no se queja, no avisa.\n";
        cout << "  Un cadaver con el mismo DNI.\n\n";
    }

    // =====================================================================
    cout << "=== 4. La pila MUERE: use-after-free de verdad ===\n";
    cout << "    (aca si hay memoria liberada: valgrind lo marca)\n";
    // =====================================================================
    // OJO - ACA ESTA LA LECCION Y EL ERROR QUE YO MISME COMI:
    //
    //   int r = -999;        r = cimaDe(p);   // r es un INT: COPIA el valor
    //   int& r = cimaDe(p);                  // r es una REFERENCIA: alias
    //
    // El TIPO lo decide la DECLARACION, no el uso. Una asignacion que viene
    // de una funcion que devuelve T& NO convierte a r en referencia.
    // Por eso aca la pila se crea con new (para que la referencia sobreviva
    // al delete) y r se declara int& explicito.
    Pila<int>* pp = new Pila<int>(5);
    pp->meter(1); pp->meter(2); pp->meter(3);
    int& r = pp->cima();     // <-- REFERENCIA de verdad, no una copia
    cout << "  con la pila viva: r = " << r << " (todo bien)\n";

    delete pp;                // ~Pila() -> delete[] datos. r queda colgando.
    cout << "  con la pila MUERTA: r = " << r << "  <- LECTURA DE MEMORIA LIBERADA\n";
    // NO hay segundo delete: el unico delete pp ya libero el objeto Y su
    // bloque interno. Un segundo delete seria un doble free.

    // =====================================================================
    cout << "\n=== RESUMEN: tres estados, no dos ===\n";
    cout << "  1. Direccion real, objeto vivo      -> todo bien\n";
    cout << "  2. Direccion real, objeto muerto    -> el PEOR: no avisa\n";
    cout << "  3. Memoria liberada (delete[])      -> UAF, valgrind lo ve\n";
    cout << "\n  La referencia garantiza el 1 en el PUNTO de crearla.\n";
    cout << "  Despues, no puede saber nada. Es un apodo, no un dueno.\n";

    return 0;
}
