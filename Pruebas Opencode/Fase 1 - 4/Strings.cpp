#include <iostream>

int main(){
    std:: string nombre;
    std:: string nombre2;

    std:: cout << "Escribe la primera palabra: \n";
    std:: cin >> nombre;
    
    std:: cout << "Escriba la segunda palabra: \n";
    std:: cin >> nombre2;

    std:: cout << "La primera palabra tiene " << nombre.length() << " letras\n";
    std:: cout << "La segunda palabra tiene " << nombre2.length() << " letras\n";

    if(nombre < nombre2){
        std:: cout << "La primer palabra va primero\n";
    }

    else if(nombre > nombre2){
        std:: cout << "La segunda palabra va primero\n";
    }
    else if(nombre[0] == nombre2[0]){
        std:: cout << "Las palabras empiezan por la misma letra\n";
    }

    std:: cout << "Su palabra completa es: " << nombre + nombre2 << "\n";
    
    if(nombre2.find(nombre) != std:: string::npos && nombre.find(nombre2) != std:: string::npos){
        std:: cout << "Las palabras se contienen entre si al ser iguales\n";
    }
    else if(nombre.find(nombre2) != std:: string::npos){
        std:: cout << "La primera palabra contiene la segunda\n";
    }
    else if(nombre2.find(nombre) != std:: string::npos){
        std:: cout << "La segunda palabra contiene la primera\n";
    }
    else{
        std:: cout << "Las palabras no se contienen\n";
    }
}