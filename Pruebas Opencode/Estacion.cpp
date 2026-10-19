#include <iostream>
#include <string>
using namespace std;

class Estacion {
private:
    std::string NombreEstacion;
    int tiempoLlegada;

public:
    friend ostream& operator<<(ostream& os, const Estacion &e);

};

ostream& operator<<(ostream& os, const Estacion& e){
    os << "El bus " << e.NombreEstacion << "demorara " << e.tiempoLlegada << "minutos"; 
    return os;
}

template <typename T>
class Nodo {
public:
    T estacion_actual;
    Nodo<T>* siguiente;
    Nodo<T>* anterior;

    Nodo(T estacion_actual): estacion_actual(estacion_actual), siguiente(nullptr), anterior(anterior){}

};

template <typename T>
class ListaDoble {
private:  
    Nodo<T>* cabeza;
    Nodo<T>* cola;

public:

    ListaDoble(): cabeza(nullptr), cola(nullptr){}

    ~ListaDoble(){
    while (cabeza != nullptr) {
            NodoDoble* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
        cola = nullptr;
    }

    void insertarFinal(T estacion_actual){
        Nodo<T>* actual = new Nodo<T>(estacion_actual);
        if(cabeza == nullptr){
            cabeza = actual;
            cola = actual;
        }else{
            cola->siguiente = actual;
            actual->anterior = cola;
            cola = actual;
        }
    }

};

