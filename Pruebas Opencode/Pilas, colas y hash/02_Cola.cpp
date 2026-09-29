/*
=====================================================================
  02 - COLA (QUEUE) — FIFO
=====================================================================
  FIFO = First In, First Out. "El primero que entra, es el primero
  que sale." Como una fila en el banco: el que llego primero se
  atiende primero.

  QUE CAMBIA RESPECTO A LA PILA: la pila mete y saca por el MISMO
  lado (el tope). La cola mete por un lado y saca por el OTRO.

      METER por aqui                          SACAR por aqui
      (final / "cola")                    (frente / "cabeza")
            |                                     |
            v                                     ^
      [ 10 ][ 20 ][ 30 ][ 40 ]  <- el mas viejo sale primero
        ^
    este es el frente

  Compilar:  g++ -Wall -Wextra -g 02_Cola.cpp -o cola
=====================================================================
*/

#include <iostream>
#include <string>
#include <queue>    // para la comparacion con la STL al final

// ===========================================================================
//  Pila minima — copia de 01_Pila.cpp, solo para la comparacion del final.
//  Cada archivo es autonomo: se compila solo, sin depender del otro.
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
//  LA COLA — sobre un bloque plano con ARRAY CIRCULAR
// ===========================================================================
//
//  TRES VARIABLES:
//
//    datos[]   -> el bloque de memoria
//    capacidad -> cuantos elementos caben
//    cantidad  -> cuantos hay ahora (0..capacidad)
//
//  EL INVARIANTE (la diferencia con la pila):
//
//    cantidad == 0  <=>  vacia
//    cantidad == capacidad <=>  llena
//    0 <= frente < capacidad   y   0 <= final < capacidad
//    final == (frente + cantidad - 1) % capacidad
//
//  *** LO IMPORTANTE: LA COLA ES UN ARRAY CIRCULAR ***
//
//  Un array normal no sirve: si meto 5 elementos y saco 2, los 2
//  primeros quedan muertos adelante y no los puedo reutilizar. Tendra
//  que correr todo el contenido para hacer espacio — O(n), cuando
//  deberia ser O(1).
//
//  La solucion: que la "cabeza" y la "cola" se MOUVAN en circulo.
//  Cuando el final llega al ultimo indice, vuelve al principio
//  (el operador % hace ese trabajo). Asi el espacio liberado por
//  el frente se reutiliza automaticamente.
//
//        [ . ][ 30 ][ 40 ][ 50 ]        frente = 1
//         0    1^    2     3
//            |
//        (los indices 0 esta libre: se LIBERO al sacar)
//
//  Ese % capacidad en todas partes es lo unico que cambia respecto a
//  la pila. Todo lo demas es identico.
// ===========================================================================

template <typename T>
class Cola {
private:
    T*  datos;
    int capacidad;
    int frente;    // indice del PRIMERO (el que sale)
    int final;     // indice del ULTIMO (el que entro)
    int cantidad;  // cuantos hay

    // -----------------------------------------------------------------
    //  AYUDA: "pasear" un indice. Si llega al final del bloque, vuelve
    //  al principio. ESTA es la unica diferencia real con la pila.
    //
    //  Sin esto, al meter el 6to elemento con capacidad 5, final seria
    //  5 y datos[5] estaria FUERA del bloque reservado: corrupcion de
    //  memoria silenciosa.
    // -----------------------------------------------------------------
    int siguiente(int i) const { return (i + 1) % capacidad; }

public:
    Cola(int cap)
        : datos(new T[cap]), capacidad(cap), frente(0), final(-1), cantidad(0) {}
    // NOTA: final arranca en -1 (no en 0) porque todavia no hay nada.
    // El primer "meter" lo pondra en 0, que es lo correcto.

    ~Cola() { delete[] datos; }

    // -----------------------------------------------------------------
    //  meter — mete por el FINAL (enqueue / push)
    //
    //  bool de retorno por el mismo motivo que en la pila: si esta
    //  llena, no se puede y hay que avisar.
    // -----------------------------------------------------------------
    bool meter(const T& valor) {
        if (cantidad == capacidad) {   // caso raro: lleno, sale temprano
            return false;
        }
        final = siguiente(final);      // avanza circularmente
        datos[final] = valor;           // escribe en el hueco libre
        cantidad++;
        return true;
    }

    // -----------------------------------------------------------------
    //  sacar — saca por el FRENTE (dequeue / pop)
    //
    //  Mismo patron que la pila: bool de exito + T& de salida.
    //  Si esta vacia, devuelve false y NO toca 'valor'.
    // -----------------------------------------------------------------
    bool sacar(T& valor) {
        if (vacia()) {                 // caso raro: vacia, sale temprano
            return false;
        }
        valor = datos[frente];          // lee el primero
        frente = siguiente(frente);     // avanza circularmente
        cantidad--;                     // el hueco queda libre para reutilizar
        return true;
    }

    // -----------------------------------------------------------------
    //  mirar — el primero, sin sacarlo (front / peek)
    //  OJO con el nombre: se llama "frente" el metodo y "frente" el
    //  miembro, y NO se pueden llamar igual (C++ no distingue uno de
    //  otro como en otros lenguajes). Por eso el metodo se llama "mirar".
    // -----------------------------------------------------------------
    T& mirar()             { return datos[frente]; }
    const T& mirar() const { return datos[frente]; }

    bool vacia() const     { return cantidad == 0; }
    int  tamano() const    { return cantidad; }
    int  capacidadMaxima() const { return capacidad; }

    // -----------------------------------------------------------------
    //  imprimir — dibuja la fila de izquierda a derecha.
    //  Recorre desde el frente (no desde 0) y da la vuelta al bloque.
    //  Asi se ve el ARREGLO CIRCULAR: no empieza en el indice 0.
    // -----------------------------------------------------------------
    void imprimir() const {
        if (vacia()) { std::cout << "(cola vacia)"; return; }
        int i = frente;
        for (int k = 0; k < cantidad; k++) {
            std::cout << "[" << datos[i] << "] ";
            i = siguiente(i);      // recorre en circulo, no lineal
        }
    }

    // -----------------------------------------------------------------
    //  imprimirCrudo — muestra el bloque COMPLETO, se use o no.
    //  Sirve para VER que el array es circular: despues de sacar, se
    //  ven los huecos al principio y los datos dando la vuelta.
    // -----------------------------------------------------------------
    void imprimirCrudo() const {
        std::cout << "bloque: ";
        for (int i = 0; i < capacidad; i++) {
            bool ocupado = false;
            int j = frente;
            for (int k = 0; k < cantidad; k++) {
                if (j == i) { ocupado = true; break; }
                j = siguiente(j);
            }
            if (ocupado) std::cout << "[" << datos[i] << "] ";
            else          std::cout << "(  .  ) ";
        }
    }
};

// ===========================================================================
//  main — demostracion
// ===========================================================================
int main() {
    Cola<int> c(5);
    int valor = 0;

    std::cout << "=== COLA de int, capacidad 5 ===\n";
    std::cout << "vacia de arranque: " << (c.vacia() ? "true" : "false") << "\n";

    std::cout << "\n-- metiendo 10,20,30,40,50 (izquierda = frente) --\n";
    for (int v : {10, 20, 30, 40, 50}) {
        c.meter(v);
        std::cout << "  tras meter(" << v << "): ";
        c.imprimirCrudo();
        std::cout << "\n";
    }
    std::cout << "  meter(60) con la cola LLENA: " << (c.meter(60) ? "true" : "false") << "\n";

    std::cout << "\n  contenido (frente -> final): "; c.imprimir();
    std::cout << "\n  mirar() = " << c.mirar() << "  (el primero, sin sacarlo)\n";

    // ------------------------------------------------------------------
    //  LA PRUEBA IMPORTANTE: sacar 3 y meter 2 mas.
    //  En un array NORMAL, los 3 espacios liberados estarian muertos
    //  adelante. En el circular, se REUTILIZAN dando la vuelta.
    // ------------------------------------------------------------------
    std::cout << "\n-- el array circular en accion --\n";
    std::cout << "  se sacan 10, 20, 30 (se liberan 3 huecos al principio):\n";
    for (int i = 0; i < 3; i++) {
        c.sacar(valor);
        std::cout << "    salio " << valor << " -> ";
        c.imprimirCrudo();
        std::cout << "\n";
    }

    std::cout << "\n  ahora se meten 60, 70 (REAPROVECHAN los huecos):\n";
    for (int v : {60, 70}) {
        c.meter(v);
        std::cout << "    tras meter(" << v << "): ";
        c.imprimirCrudo();
        std::cout << "\n";
    }

    std::cout << "\n  contenido final: "; c.imprimir();
    std::cout << "\n  tamano: " << c.tamano() << " de " << c.capacidadMaxima() << "\n";

    std::cout << "\n-- se saca todo (orden FIFO: 40, 50, 60, 70) --\n    ";
    while (c.sacar(valor)) std::cout << valor << " ";
    std::cout << "\n  vacia al final: " << (c.vacia() ? "true" : "false") << "\n";
    std::cout << "  sacar de vacia: " << (c.sacar(valor) ? "true" : "false") << "\n";

    // ------------------------------------------------------------------
    //  La MISMA plantilla con string.
    // ------------------------------------------------------------------
    std::cout << "\n=== la MISMA plantilla con std::string ===\n";
    Cola<std::string> cs(3);
    cs.meter(std::string("Ana"));
    cs.meter(std::string("Luis"));
    cs.meter(std::string("Zoe"));
    std::cout << "  ";
    cs.imprimir();
    std::cout << "\n  mirar() = " << cs.mirar() << "\n";
    std::string t;
    std::cout << "  sacar   = ";
    while (cs.sacar(t)) std::cout << t << " ";
    std::cout << "\n";

    // ------------------------------------------------------------------
    //  LAS TRES JUNTAS: la diferencia en una linea.
    // ------------------------------------------------------------------
    std::cout << "\n=== PILA vs COLA: la misma pregunta, distinta respuesta ===\n";
    std::cout << "  meto 1,2,3 y miro el primero en ver que pasa:\n\n";

    Pila<int> pila(3);  pila.meter(1);  pila.meter(2);  pila.meter(3);
    std::cout << "  PILA  cima()   = " << pila.cima()   << "  <- el ULTIMO que entro (3)\n";

    Cola<int> cola(3);  cola.meter(1);  cola.meter(2);  cola.meter(3);
    std::cout << "  COLA  mirar()  = " << cola.mirar()  << "  <- el PRIMERO que entro (1)\n";
    std::cout << "\n  Mismo dato, misma operacion, resultado OPUESTO.\n";
    std::cout << "  Por eso se llaman LIFO y FIFO: son la MISMA idea\n";
    std::cout << "  (guardar y sacar) con DOS reglas de orden distintas.\n";

    // ------------------------------------------------------------------
    //  Equivalencia con la STL.
    // ------------------------------------------------------------------
    std::cout << "\n=== equivalencia con la STL ===\n";
    std::cout << "  nuestra Cola<T>   ==  std::queue<T>\n";
    std::cout << "  nuestra meter()   ==  push()\n";
    std::cout << "  nuestra sacar()   ==  pop()\n";
    std::cout << "  nuestra mirar()   ==  front()   (el primero)\n";
    std::cout << "  nuestra vacia()   ==  empty()\n\n";

    std::queue<int> q;
    for (int v : {10, 20, 30}) q.push(v);
    std::cout << "  std::queue con 10,20,30 -> front() = " << q.front() << "\n";
    q.pop();
    std::cout << "  tras pop()              -> front() = " << q.front() << "\n";
    std::cout << "  (back() = " << q.back() << " : el ULTIMO)\n";
    std::cout << "  empty() = " << (q.empty() ? "true" : "false") << ", size() = " << q.size() << "\n";

    return 0;
}
