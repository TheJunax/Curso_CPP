#include <iostream>
#include <string>

// Pila (stack) LIFO sobre un bloque plano de memoria, como la Matriz del
// proyecto de la Fase 5. El 'tope' es el indice del ultimo elemento vivo:
// -1 significa pila vacia. Ese numero tiene que coincidir SIEMPRE con la
// cantidad real de elementos (el invariante de la estructura).
template <typename T>
class Pila {
private:
    T* datos;       // bloque plano: new T[capacidad]
    int capacidad;  // cuanto espacio reservamos
    int tope;       // cuantos elementos hay (-1 = vacia)

public:
    Pila(int cap)
        : datos(new T[cap]), capacidad(cap), tope(-1) {}

    ~Pila(){
        delete[] datos;   // [] porque el bloque se pidio con new[]
    }

    // 1) meter: mete un elemento arriba. Si la pila esta llena, no se mete nada
    //    (no hay donde). Devuelve false para que el main se entere.
    //    Pista: si tope + 1 == capacidad, no hay espacio.
    //    Si hay espacio: guardar el valor en datos[tope + 1] y subir el tope.
    bool meter(const T& valor){
        if((tope + 1) == capacidad){
            return false;   // pila llena: no hay donde meterlo
        }
        datos[tope + 1] = valor;
        tope++;
        return true;
    }

    // 2) sacar: saca el elemento de arriba y lo deja en 'valor'.
    //    Si la pila esta vacia devuelve false y NO toca 'valor'.
    //    Pista: si tope == -1 no hay nada. Si no, copiar datos[tope] a valor
    //    y BAJAR el tope.
    bool sacar(T& valor){
        if(estaVacia()){
            return false;   // pila vacia: 'valor' queda intacto
        }
        valor = datos[tope];
        tope--;
        return true;
    }

    // 3) cima: devuelve una REFERENCIA al elemento de arriba, sin sacarlo.
    //    Solo se llama con la pila no vacia.
    //    Pista: la referencia evita una copia (mismo motivo que el operator() de Matriz).
    T& cima(){
        return datos[tope];
    }

    const T& cima() const{
        return datos[tope];
    }

    bool estaVacia() const{
        return tope == -1;
    }

    int tamano() const{
        return tope + 1;
    }

    int capacidadMaxima() const{
        return capacidad;
    }

    // Muestra el contenido de abajo hacia arriba (asi se ve como una pila:
    // el ultimo que se metio queda al final de la impresion).
    void imprimir() const{
        if(estaVacia()){
            std::cout << "pila vacia";
            return;
        }
        for(int i = 0; i <= tope; i++){
            std::cout << datos[i] << " ";
        }
    }
};

// ---------------------------------------------------------------------------
// RETO 1: balanceo de parentesis y llaves.
// Devuelve true si todos los ()[]{} abren y cierran en el orden correcto.
// Pista: recorre la cadena; si ves un abre, metelo en la pila; si ves un
// cierra, saca uno y comparalo con el que esperabas (si no coincide, false).
// Al final la pila debe estar vacia.
bool balanceado(const std::string& cadena);

// ---------------------------------------------------------------------------
// RETO 2: convertir infija a postfija (Shunting Yard).
// Pila de operadores + regla de precedencia. Se resuelve en el siguiente paso.
// std::string convertirPostfija(const std::string& infija);

int main(){
    Pila<int> p(5);
    int valor = 0;

    std::cout << "--- pila de int (capacidad 5) ---\n";
    std::cout << "vacia de arranque: " << (p.estaVacia() ? "true" : "false") << "\n";

    for(int i = 1; i <= 5; i++){
        std::cout << "meter(" << i << "): " << (p.meter(i) ? "true" : "false") << "\n";
    }
    std::cout << "meter(6) (llena): " << (p.meter(6) ? "true" : "false") << "\n";
    std::cout << "contenido (abajo -> arriba): ";
    p.imprimir();
    std::cout << "\ntamano: " << p.tamano() << " de " << p.capacidadMaxima() << "\n";
    std::cout << "cima: " << p.cima() << "\n";

    std::cout << "\nsacar: ";
    while(p.sacar(valor)){
        std::cout << valor << " ";
    }
    std::cout << "\nvacia al final: " << (p.estaVacia() ? "true" : "false") << "\n";
    std::cout << "sacar de vacia: " << (p.sacar(valor) ? "true" : "false") << "\n";

    std::cout << "\n--- la MISMA plantilla con std::string ---\n";
    Pila<std::string> ps(3);
    ps.meter(std::string("uno"));
    ps.meter(std::string("dos"));
    ps.meter(std::string("tres"));
    std::string texto;
    std::cout << "cima: " << ps.cima() << "\n";
    std::cout << "sacar: ";
    while(ps.sacar(texto)){
        std::cout << texto << " ";
    }
    std::cout << "\n";

    std::cout << "\n--- reto 1: balanceo de parentesis ---\n";
    // std::cout << balanceado("(a+(b*c)") << " (debe dar 0/false)\n";
    // std::cout << balanceado("(a+b*c)") << " (debe dar 1/true)\n";

    return 0;
}
