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
    bool abierto() {
        return palabras.is_open();
    }
    bool leerLinea(std::string& palabra, int& cont) {
        if (!palabras.is_open()) return false;
        if (std::getline(palabras, palabra)) {
            if (!palabra.empty() && palabra.back() == '\r') palabra.pop_back();
            cont++;
            return true;
        }
        return false;
    }
    ~Archivo(){
        if(palabras.is_open()){
            palabras.close();
        }
    }
};

int diferencia(int a, int b) {
    if (a > b) return a - b;
    return b - a;
}

int main(){

    Archivo log("words.txt");
    if (!log.abierto()) return 1;
    int contador = 0;
    HashTable tabla8(false,8);
    HashTable tabla14(false,14);
    HashTable tablaF(true);
    std::vector<std::string> palabras;
    std::string palabra;

    while (log.leerLinea(palabra, contador)) {
        palabras.push_back(palabra);
    }
    std::cout << "Contador: " << contador << std::endl;

    std::cout << "Tabla hash pura (cubeta al azar)" << std::endl;
    for (const auto& p : palabras) {
        tabla8.insertarElemento(p, 4);
        tabla14.insertarElemento(p, 4);
    }
    int pura8 = tabla8.resumen();
    int pura14 = tabla14.resumen();
    tabla8.clear();
    tabla14.clear();

    std::cout << "Funcion hash suma" << std::endl;
    for (const auto& p : palabras) {
        tabla8.insertarElemento(p, 1);
        tabla14.insertarElemento(p, 1);
    }
    int dif1 = diferencia(tabla8.resumen(), pura8) + diferencia(tabla14.resumen(), pura14);
    tabla8.clear();
    tabla14.clear();

    std::cout << "Funcion hash multiplicacion" << std::endl;
    for (const auto& p : palabras) {
        tabla8.insertarElemento(p, 2);
        tabla14.insertarElemento(p, 2);
    }
    int dif2 = diferencia(tabla8.resumen(), pura8) + diferencia(tabla14.resumen(), pura14);
    tabla8.clear();
    tabla14.clear();

    std::cout << "Funcion hash XOR" << std::endl;
    for (const auto& p : palabras) {
        tabla8.insertarElemento(p, 3);
        tabla14.insertarElemento(p, 3);
    }
    int dif3 = diferencia(tabla8.resumen(), pura8) + diferencia(tabla14.resumen(), pura14);
    tabla8.clear();
    tabla14.clear();

    std::cout << "\nDiferencia contra la tabla pura (colisionadas)" << std::endl;
    std::cout << "suma: " << dif1 << " | multiplicacion: " << dif2 << " | XOR: " << dif3 << std::endl;

    int mejor = 1;
    int menor = dif1;
    if (dif2 < menor) {
        mejor = 2;
        menor = dif2;
    }
    if (dif3 < menor) {
        mejor = 3;
        menor = dif3;
    }
    std::cout << "Mejor funcion (la mas parecida a la pura): " << mejor << std::endl;

    std::cout << "\nFuncion hash Validado a Factor de Carga" << std::endl;
    for (const auto& p : palabras) {
        tablaF.insertarElemento(p, mejor);
    }

    tablaF.resumen();
    tablaF.clear();

    return 0;
}