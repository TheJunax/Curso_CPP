#include <iostream>

void pedirDatos(int &a,int &b){
    std::cout << "Escriba el primer numero: ";
    std::cin >> a;

    std::cout << "Escriba el segundo numero: ";
    std::cin >> b;
}
void pedirDatos(double &a,double &b){
    std::cout << "Escriba el primer numero: ";
    std::cin >> a;

    std::cout << "Escriba el segundo numero: ";
    std::cin >> b;
}


int multiplicar(int a, int b){
    return a*b;
}
double multiplicar(double a, double b){
    return a*b;
}
int dividir(int a, int b){
    if(b ==0){
        return 0;
    }
    return a/b;
}
int modulo(int a, int b){
    if(b ==0){
        return 0;
    }
    return a%b;
}
int potencia(int a, int b){
    int pot = 1;
    for(int i=0; i <b; i++){
        pot *= a;
    }
    return pot;
}
int main(){
    auto a=0, b=0;
    auto opcion=0;
    do{
        std::cout << "Opciones (Elija que operacion): \n1. Multiplicar \n2. Dividir (entero) \n3. Modulo \n4. Potencia \n5. Salir\n";
        std::cin >> opcion;
        switch(opcion){
            case 1:{
                pedirDatos(a,b);
                int mult = multiplicar(a,b);
                std::cout << "El resultado es: " << mult;
                std::cout << "\n";
                break;
            }
            case 2:{
                pedirDatos(a,b);
                int div = dividir(a,b);
                std::cout << "El resultado es: " << div;
                std::cout << "\n";
                break;
            }
            case 3:{
                pedirDatos(a,b);
                int mod = modulo(a,b);
                std::cout << "El resultado es: " << mod;
                std::cout << "\n";
                break;
            }
            case 4:{
                pedirDatos(a,b);
                int pot = potencia(a,b);
                std::cout << "El resultado es: " << pot;
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
