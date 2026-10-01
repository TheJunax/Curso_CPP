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
    bool leerLinea(std::string& palabra) {
        if (!palabras.is_open()) return false;
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
    HashTable tabla8(8);
    HashTable tabla14(14);
    std::string palabra;

    while (log.leerLinea(palabra)) {
        tabla8.insertarElemento(palabra);
        tabla14.insertarElemento(palabra);
    }

    tabla8.mostrarColisiones();
    //tabla14.mostrarColisiones();

    tabla8.resumen();
    tabla14.resumen();

    return 0;
}
