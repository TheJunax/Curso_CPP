/*
Menu con opciones y convertir minimo 4
vuelve a mostrrar el menu
salir
vamos a hacer:
Opciones (Elija que convertir): 
1. Celsius a Farenheit
2. Kilomentros en tiempo aprox
3. USD a COP
4. Kilogramos a Libras
5. Salir*/

#include <iostream>
constexpr int LIBRAS = 2;
constexpr int MINUTOS = 60;
constexpr int PESOS = 3000;

void pedirDatos(double &a);
double temperatura(double cel);
void tiempo(double time);
double moneda(double dol);
double peso(double kil);

int main(){
    auto a = 0.0;
    auto opcion =0;
    do{
        std::cout << "Opciones (Elija que convertir): \n1. Celsius a Farenheit \n2. Tiempo en Horas y minutos \n3. USD a COP \n4. Kilogramos a Libras \n5. Salir\n";
        std::cin >> opcion;
        switch(opcion){
            case 1:{
                pedirDatos(a);
                double far = temperatura(a);
                std::cout << "El resultado es: " << far;
                std::cout << "\n";
                break;
            }
            case 2:{
                pedirDatos(a);
                tiempo(a);
                break;
            }
            case 3:{
                pedirDatos(a);
                double cop = moneda(a);
                std::cout << "El resultado es: " << cop;
                std::cout << "\n";
                break;
            }
            case 4:{
                pedirDatos(a);
                double lib = peso(a);
                std::cout << "El resultado es: " << lib;
                std::cout << "\n";
                break;
            }
            case 5:
                std::cout << "Chao\n";
                break;
        }
    }while(opcion != 5);

    return 0;
}

void pedirDatos(double &a){
    std::cout << "Escriba el dato a convertir: ";
    std::cin >> a;
}

double temperatura(double cel){
    double far = (cel *1.8) + 32;
    return far;
}

void tiempo(double time){
    int minutos, horas;
    if(time <0){
        std::cout << "Tiempo Invalido\n";
        return;
    }
    
    minutos = static_cast<int>(time) % MINUTOS;
    horas = static_cast<int>(time) / MINUTOS;

    std::cout << "Tiempo: " << time << " Convertido: ";
    std::cout << horas <<" horas " << minutos << " minutos\n";

}

double moneda(double dol){
    double cop = dol * PESOS;
    return cop;
}

double peso(double kil){
    double lib = kil *LIBRAS;
    return lib;
}

