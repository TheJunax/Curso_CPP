#include <iostream>

void intercambiar(double &x, double &y){
    double temp = x;
    x = y;
    y = temp;
}

int main(){
    constexpr int n=4; //Se supone que ya esta en binario cuantas notas se van a promediar
    double notas[n];
    
    std::cin >> notas[0] >> notas[1] >> notas[2] >> notas[3];

    auto prom =0.0; // hay que escribir para que detecte
    for(int i =0; i<n; i++){
        prom += notas[i];
    }
    prom = (prom / n); //static_cast<double> convertir antes de dividir

    std::cout << "Resultado: " << prom << "\n";
    for(int i =0; i<n; i++){
        std::cout << notas[i] << " ";
    }
    std::cout << "\nIntercanmbiar nota 2 y 3 \n";

    intercambiar(notas[1], notas[2]);
    for(int i =0; i<n; i++){
        std::cout << notas[i] << " ";
    }
    return 0;
}