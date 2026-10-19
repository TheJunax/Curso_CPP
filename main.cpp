#include <iostream>
#include <string>
#include <fstream>
#include "HASHTABLE_H.hpp"


class Archivo {
    private: std::ifstream palabras;

    public:
    Archivo(std::string nombreArchivo): palabras(nombreArchivo){
        if(!palabras.is_open()){
            std::cerr << "Error no se puede abrir el archivo: " << nombreArchivo << std::endl;
        }   
    }
    bool leerLinea(std::string& palabra, int& cont) {
        if (!palabras.is_open()) return false;
        cont++;
        return static_cast<bool>(std::getline(palabras, palabra));
    }
    ~Archivo(){
        if(palabras.is_open()){
            palabras.close();
        }
    }
};

int main(){

    Archivo log("words.txt");
    int contador = 0;
    HashTable tabla8(8);
    HashTable tabla14(14);
    
    std::vector<std::string> palabras;
    std::string palabra;

    while (log.leerLinea(palabra, contador)) {
        palabras.push_back(palabra);
    }
    std::cout << "Contador: " << contador << std::endl;
    std::cout << "Funcion hash suma" << std::endl;
    for (const auto& p : palabras) {
        tabla8.insertarElemento(p, tabla8.indice(p,1));
        tabla14.insertarElemento(p, tabla14.indice(p,1));
    }



    //tabla8.mostrarColisiones();
    //tabla14.mostrarColisiones();

    tabla8.resumen();
    tabla14.resumen();

    tabla8.clear();
    tabla14.clear();
    std::cout << "Funcion hash multiplicacion" << std::endl;

   for (const auto& p : palabras) {
        tabla8.insertarElemento(p, tabla8.indice(p,2));
        tabla14.insertarElemento(p, tabla14.indice(p,2));
    }

    //tabla8.mostrarColisiones();
    //tabla14.mostrarColisiones();

    tabla8.resumen();
    tabla14.resumen();
    tabla8.clear();
    tabla14.clear();
    std::cout << "Funcion hash XOR" << std::endl;

    for (const auto& p : palabras) {
        tabla8.insertarElemento(p, tabla8.indice(p,3));
        tabla14.insertarElemento(p, tabla14.indice(p,3));
    }

    //tabla8.mostrarColisiones();
    //tabla14.mostrarColisiones();

    tabla8.resumen();
    tabla14.resumen();
    tabla8.clear();
    tabla14.clear();


    return 0;
}