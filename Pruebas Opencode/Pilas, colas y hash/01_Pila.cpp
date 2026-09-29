/*
=====================================================================
  01 - PILA (STACK) — LIFO
=====================================================================
  LIFO = Last In, First Out. "El ultimo que entra, es el primero
  que sale." Como una pila de platos: el de arriba es el unico
  al que podes agarrar.

  Se implementa con UN SOLO indice (el tope) sobre un bloque plano
  de memoria. No hay linked list, no hay punteros a nodos: es
  un arreglo y un numero que dice hasta donde esta lleno.

  Compilar:  g++ -Wall -Wextra -g 01_Pila.cpp -o pila
=====================================================================
*/

#include <iostream>
#include <string>
#include <stack>     // para la comparacion con la STL al final

// ===========================================================================
//  LA PILA
// ===========================================================================
//
//  TRES VARIABLES, y cada una tiene un trabajo distinto:
//
//    datos[]     -> el bloque de memoria donde viven los datos
//    capacidad   -> cuantos elementos caben (se pidio al sistema)
//    tope        -> el indice del ULTIMO elemento vivo
//
//  EL INVARIANTE (la regla que nunca se rompe):
//
//    tope == -1        <=>  la pila esta VACIA
//    tope == capacidad-1 <=> la pila esta LLENA
//    tope == cantidad de elementos - 1
//
//  El invariante es la idea central de la Sesion 20 (Matriz) y 26:
//  un unico numero que se puede leer de dos formas ("cuantos hay")
//  y no hay forma de que se desincronice del contenido real, porque
//  NINGUNA operacion lo cambia sin cambiar tambien los datos.
// ===========================================================================

template <typename T>
class Pila {
private:
    T*  datos;       // new T[capacidad]: un bloque plano, no un arreglo de punteros
    int capacidad;   // cuantos elementos reservamos de una vez
    int tope;        // indice del ultimo elemento vivo. -1 = vacia

public:
    // -----------------------------------------------------------------
    // CONSTRUCTOR: pide la memoria y deja la pila vacia.
    // NOTA: en la lista de inicializacion los miembros nacen YA con valor
    // (tope = -1), antes de que corra el cuerpo del constructor. Por eso
    // no hace falta escribir "tope = -1;" adentro.
    // -----------------------------------------------------------------
    Pila(int cap) : datos(new T[cap]), capacidad(cap), tope(-1) {}

    // -----------------------------------------------------------------
    // DESTRUCTOR: devuelve el bloque al sistema.
    // El [] es OBLIGATORIO: se pidio con new[], se devuelve con delete[].
    // Borrar un new[] con delete (sin corchetes) es undefined behavior.
    // -----------------------------------------------------------------
    ~Pila() { delete[] datos; }

    // -----------------------------------------------------------------
    // 1) meter — mete un elemento arriba (push)
    //
    //    DEVUELVE bool, no void. Por que? Por la leccion de la Sesion 27:
    //    si una operacion puede fallar, TIENE QUE AVISAR. Si devolviera
    //    void, el main no tendria forma de enterarse de que el elemento
    //    NO entro, y seguiria como si todo estuviera bien (el bug real
    //    que gudamos en RefColgante.cpp).
    //
    //    El caso raro sale temprano (Sesion 26): si esta llena, avisa y
    //    sale. El camino recto es el caso normal.
    // -----------------------------------------------------------------
    bool meter(const T& valor) {
        if (tope + 1 == capacidad) {   // el proximo hueco seria tope+1;
            return false;              // si eso es == capacidad, no hay
        }                               // lugar. (Ojo: == y no >=, porque
                                        //  el invariante lo garantiza)
        datos[tope + 1] = valor;        // ocupa el hueco
        tope++;                         // y el nuevo tope es ese
        return true;
    }

    // -----------------------------------------------------------------
    // 2) sacar — saca el elemento de arriba (pop)
    //
    //    Recibe T& (referencia de salida) en vez de devolver T. Por que?
    //    Porque DEVUELVER T por valor haria una COPIA del dato. Con T&
    //    el dato se escribe directo en la variable del llamador.
    //
    //    Mismo patron que buscar() de la tabla hash: bool de return para
    //    el exito, parametro de referencia para el resultado.
    //
    //    Si la pila esta vacia devuelve false y NO toca 'valor'.
    // -----------------------------------------------------------------
    bool sacar(T& valor) {
        if (estaVacia()) {          // tope == -1: no hay nada que sacar.
            return false;           // 'valor' queda intacto a proposito:
        }                           // escribirle seria mentir.
        valor = datos[tope];         // copia el ultimo
        tope--;                      // y el nuevo tope es el anterior
        return true;
    }

    // -----------------------------------------------------------------
    // 3) cima — mira el elemento de arriba SIN sacarlo (top)
    //
    //    DEVUELVE T& (referencia), no T. Devolver T haria una copia;
    //    devolver T& da acceso directo al dato interno.
    //
    //    *** PELIGRO (la pregunta de la Sesion 26) ***
    //    Esta referencia es un PRESTAMO: es valida mientras la pila
    //    este viva Y mientras nadie vuelva a usar ese espacio. Si el
    //    elemento se saca y se mete otro, la referencia apunta al NUEVO
    //    dato, no al viejo. Por eso el uso correcto es:
    //
    //        T& ref = p.cima();   // usar ref
    //        p.sacar();            // y LUEGO sacar
    //
    //    y no al reves. (Ver StackRef.cpp para el caso de std::vector.)
    // -----------------------------------------------------------------
    T& cima()             { return datos[tope]; }
    const T& cima() const { return datos[tope]; }

    // -----------------------------------------------------------------
    // 4) Consultas. Las tres son "solo lectura": no cambian nada.
    //    Por eso son const — el compilador PROHIBE modificarlas si el
    //    objeto es const (misma proteccion de la Sesion 12).
    // -----------------------------------------------------------------
    bool estaVacia() const     { return tope == -1; }
    int  tamano() const        { return tope + 1; }   // "tope+1" LITERALMENTE
    int  capacidadMaxima() const { return capacidad; }

    // -----------------------------------------------------------------
    // 5) imprimir — dibuja la pila de lado, para VER la estructura.
    //    Muestra de abajo hacia arriba: el fondo primero, el tope al
    //    final, que es donde se ve que el ultimo que entro esta arriba.
    // -----------------------------------------------------------------
    void imprimir() const {
        if (estaVacia()) { std::cout << "(pila vacia)"; return; }
        for (int i = 0; i <= tope; i++) {
            std::cout << "| " << datos[i] << " | ";
        }
    }
};

// ===========================================================================
//  RETO 1 — Balanceo de parentesis y llaves
// ===========================================================================
//  Devuelve true si todos los () [] {} abren y cierran en el orden correcto.
//  Pista: recorre la cadena. Si ves un ABRE, metelo a la pila. Si ves un
//  CIERRA, saca uno y compara con el que esperabas. Si al final la pila
//  NO esta vacia, sobraron abre.
//
//  "(()"  -> false  (sobro un abre)
//  "(a+b*c)" -> true
//  "([)]" -> false (se cruzan: abrio parenesis, cerro corchete)
bool balanceado(const std::string& cadena);

// ===========================================================================
//  RETO 2 — Convertir infija a postfija (Shunting Yard)
// ===========================================================================
//  Pila de operadores + regla de precedencia. Se resuelve en el siguiente paso.
//  std::string convertirPostfija(const std::string& infija);

// ===========================================================================
//  main — demostracion
// ===========================================================================
int main() {
    Pila<int> p(5);
    int valor = 0;

    std::cout << "=== PILA de int, capacidad 5 ===\n";
    std::cout << "vacia de arranque : " << (p.estaVacia() ? "true" : "false") << "\n";

    std::cout << "\n-- metiendo 1..5 --\n";
    for (int i = 1; i <= 5; i++) {
        std::cout << "  meter(" << i << "): " << (p.meter(i) ? "true" : "false") << "\n";
    }

    std::cout << "\n  meter(6) con la pila LLENA: " << (p.meter(6) ? "true" : "false")
              << "   <- caso raro, sale temprano\n";

    std::cout << "\n  contenido (fondo -> tope): ";
    p.imprimir();
    std::cout << "\n  tamano: " << p.tamano() << " de " << p.capacidadMaxima();
    std::cout << "\n  cima: " << p.cima() << "\n";

    std::cout << "\n-- sacando todo (orden LIFO: sale el ultimo que entro) --\n    ";
    while (p.sacar(valor)) {
        std::cout << valor << " ";
    }

    std::cout << "\n\n  vacia al final : " << (p.estaVacia() ? "true" : "false");
    std::cout << "\n  sacar de vacia: " << (p.sacar(valor) ? "true" : "false")
              << "   <- y 'valor' NO se toco\n";

    // ------------------------------------------------------------------
    //  La MISMA plantilla con otro tipo. Esta es la gracia de template:
    //  el codigo de arriba no cambio, solo se dedujo T = std::string.
    // ------------------------------------------------------------------
    std::cout << "\n\n=== la MISMA plantilla con std::string ===\n";
    Pila<std::string> ps(3);
    ps.meter(std::string("uno"));
    ps.meter(std::string("dos"));
    ps.meter(std::string("tres"));

    std::cout << "  cima  : " << ps.cima() << "\n";
    std::cout << "  meter(\"cuatro\") con capacidad 3: "
              << (ps.meter(std::string("cuatro")) ? "true" : "false") << "\n";

    std::string texto;
    std::cout << "  sacar : ";
    while (ps.sacar(texto)) std::cout << texto << " ";
    std::cout << "\n";

    // ------------------------------------------------------------------
    //  Comparacion con la STL. std::stack es EXACTAMENTE esto, pero ya
    //  hecho y con las decisiones resueltas (usa deque por una razon que
    //  vimos en la Sesion 27: deque nunca reubica lo que ya esta, asi
    //  que las referencias no se cuelgan).
    // ------------------------------------------------------------------
    std::cout << "\n=== equivalencia con la STL ===\n";
    std::cout << "  nuestra Pila<T>   ==  std::stack<T>\n";
    std::cout << "  nuestra meter()   ==  push()\n";
    std::cout << "  nuestra sacar()   ==  pop()\n";
    std::cout << "  nuestra cima()    ==  top()\n\n";

    std::stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    std::cout << "  std::stack con 10,20,30 -> top() = " << st.top() << "\n";
    st.pop();
    std::cout << "  tras pop()           -> top() = " << st.top() << "\n";
    std::cout << "  empty() = " << (st.empty() ? "true" : "false")
              << ", size() = " << st.size() << "\n";

    // ------------------------------------------------------------------
    std::cout << "\n=== RETO 1: balanceo de parentesis ===\n";
    // std::cout << balanceado("(a+(b*c)") << "  (esperado: false)\n";
    // std::cout << balanceado("(a+b*c)")  << "  (esperado: true)\n";
    // std::cout << balanceado("([)]")     << "  (esperado: false)\n";

    return 0;
}
