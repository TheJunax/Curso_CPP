#include <iostream>
using namespace std;

class Matriz{
public:
    //Constructor
    Matriz(int filas, int col) :
    filas(filas), col(col), datos(new double[filas*col]{}){};
    //Destructor
    ~Matriz(){delete[] datos;};
    //Copia
    Matriz(const Matriz& otro) : filas(otro.filas), col(otro.col), datos(new double[otro.filas*otro.col]{}) {
        for (int i = 0; i < (filas*col); ++i) datos[i] = otro.datos[i];

    };
    //Asigacion de copia
    Matriz& operator=(const Matriz& otro){
        if (this != &otro) {
            delete[] datos;
            filas = otro.filas;
            col = otro.col;
            datos = new double[otro.filas * otro.col]{};
            for (int i = 0; i < (filas*col); ++i) datos[i] = otro.datos[i];

        }
        return *this;
    }
    //Robar o mover
    Matriz(Matriz&& otro)noexcept: filas(otro.filas), col(otro.col), datos(otro.datos){
        otro.filas = 0;
        otro.col = 0;
        otro.datos = nullptr;
    }
    //Asignacion de move
    Matriz& operator=(Matriz&& otro)noexcept{
        if(this == &otro){return *this;}
        delete[] datos;
        datos = otro.datos;
        filas = otro.filas;
        col = otro.col;

        otro.filas = 0;
        otro.col = 0;
        otro.datos = nullptr; 
        return *this;
    }
    //Aceder
    double& operator()(int f, int c){
        return datos[(f*col)+c];
    }
        int tamF() const { return filas; }
        int tamC() const { return col; }   

    //mostrar por friend
    friend ostream& operator<<(ostream& out,const Matriz& m);

private:
    int filas, col;
    double *datos;
};

ostream& operator<<(ostream &os, const Matriz &m){
    os << "Datos: " ;
    for(int i=0; i < m.filas*m.col; i++){
        if(i % m.col == 0){
            os << "\n";
        }
        os << m.datos[i] << " ";
    }
    return os;
}

int main(){

    Matriz m(2,3);
    m(0,0) = 4.1;
    m(0,1) = 3.5;
    m(0,2) = 1.5;
    m(1,0) = 4.8;
    m(1,1) = 2.9;
    m(1,2) = 4.5;
    cout << "Filas de m = " << m.tamF() << " | Columnas de m = " << m.tamC() << "\n";
    cout << m << "\n";

    Matriz z = m;
    cout << "Copia: z a m "<< "Filas = " << z.tamF() << " | Columnas = " << z.tamC() << "\n";
    cout << "Filas de m = " << m.tamF() << " | Columnas de m = " << m.tamC() << "\n";
        cout << "\n";


    z(0,0) = 999;
    cout << "z(0,0) = " << z(0,0) << " | m(0,0) = " << m(0,0) << '\n';
    cout << "\n";



    Matriz x = move(m);
    cout << "Mueve: x a m "<< "Filas = " << x.tamF() << " | Columnas = " << x.tamC() << "\n";
    cout << "Filas de m = " << m.tamF() << " | Columnas de m = " << m.tamC() << "\n";


    return 0;
}