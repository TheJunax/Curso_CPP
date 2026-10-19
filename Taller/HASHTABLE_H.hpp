#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>

struct Estadisticas {
    int cubetas;
    int vacias;
    int colisionadas;
    double alpha;
    int peor;
};

class HashTable {
    private:
    int bitsAcum;
    int bitsIniciales;
    int cantidad = 0;
    int dinamica;
    std::vector<std::vector<std::string>> tablaHash;

    unsigned long int funcionHashSuma(const char* palabra, int bits){
        unsigned long int suma = 0;
        for(const char* c = palabra; *c != '\0'; c++){
            suma += static_cast<unsigned char>(*c);
        }
        return suma & ((1UL << bits) - 1);
    }
    unsigned long int funcionHashMult(const char* palabra, int bits){
        unsigned long int mult = 1;
        for(const char* c = palabra; *c != '\0'; c++){
            mult *= static_cast<unsigned char>(*c);
        }
        return mult & ((1UL << bits) - 1);
    }
    unsigned long funcionHashXOR(const char* palabra, int bits) {
        const unsigned long mascara = (1UL << bits) - 1;
        unsigned long resultado = 0;
        unsigned long acum = 0;
        int bitsPendientes = 0;

        for (const char* p = palabra; *p != '\0'; p++) {
            unsigned char c = static_cast<unsigned char>(*p);
            acum = (acum << 8) | c;
            bitsPendientes += 8;

            while (bitsPendientes >= bits) {
                resultado ^= (acum >> (bitsPendientes - bits)) & mascara;
                bitsPendientes -= bits;
                acum &= (1UL << bitsPendientes) - 1;
            }
        }

        if (bitsPendientes > 0) {
            resultado ^= (acum << (bits - bitsPendientes)) & mascara;
        }
        return resultado;
    }


public:
    HashTable(bool dinamica = true, int bits=0) : dinamica(dinamica) {
        if (dinamica) {
            bitsAcum = 4;
        } else {
            bitsAcum = bits;
        }
        bitsIniciales = bitsAcum;
        tablaHash.resize(1 << bitsAcum);
    }

    int indice(const std::string& palabra, int opcion){
        if (opcion == 1){
            int ind = funcionHashSuma(palabra.c_str(), bitsAcum);
            return ind;
        }
        else if(opcion == 2){
            int ind = funcionHashMult(palabra.c_str(), bitsAcum);
            return ind;
        }
        else if(opcion == 3) {
            int ind = funcionHashXOR(palabra.c_str(), bitsAcum);
            return ind;
        }
        else if(opcion == 4) {
            int ind = std::rand() & ((1UL << bitsAcum) - 1);
            return ind;
        }
        else{
            std::cout << "Opcion invalida" << std::endl;
        }
        return 0;

    }

    void insertarElemento(const std::string& palabra, int opcion){
        int ind = indice(palabra, opcion );
        tablaHash[ind].push_back(palabra);
        cantidad++;

        if (dinamica) {
            double factorCarga = static_cast<double>(cantidad) / tablaHash.size();

            if (factorCarga > 0.75) {
                crecer(opcion);
            }
        }

    }

    void mostrarColisiones(){
        for (std::size_t i = 0; i < tablaHash.size(); i++){
            if (tablaHash[i].size() >= 2){

                std::cout << "La cantidad de elementos colisionados en el bucket " << i << " es de: " << tablaHash[i].size() <<  std::endl;
            }
        }
    }

    Estadisticas estadisticas() {
        Estadisticas e = {0, 0, 0, 0, 0};
        e.cubetas = tablaHash.size();
        for (std::size_t i = 0; i < tablaHash.size(); i++) {
            int tam = tablaHash[i].size();
            if (tam == 0) e.vacias++;
            if (tam >= 2) e.colisionadas++;
            if (tam > e.peor) e.peor = tam;
        }
        e.alpha = (double)cantidad / tablaHash.size();
        return e;
    }

    int resumen() {
        std::size_t vacias = 0, colisionadas = 0, peor = 0 ;
        for (std::size_t i = 0; i < tablaHash.size(); i++) {
            const auto& cubeta = tablaHash[i];
            if (cubeta.empty()) vacias++;
            if (cubeta.size() >= 2) colisionadas++;
            if (cubeta.size() > peor) {
                peor = cubeta.size();
            }
        }
        std::cout << "cubetas: "      << tablaHash.size() << "\n"
                << " | vacias: "       << vacias  << "\n"
                << " | colisionadas: " << colisionadas << "\n"
                << " | alpha: "        << (double)cantidad / tablaHash.size() << "\n"
                << " | peor cubeta: " << peor << " elementos\n";
        return colisionadas;
    }

    void clear(){
        bitsAcum = bitsIniciales;
        tablaHash.assign(1 << bitsAcum, std::vector<std::string>());
        cantidad = 0;
    }

    void crecer(int opcion){
        bitsAcum += 1;
        std::vector<std::vector<std::string>> nueva(1 << bitsAcum);

        for (auto& cubeta : tablaHash)
            for (auto& p : cubeta)
                nueva[indice(p, opcion)].push_back(p);

        tablaHash = nueva;
    }
};

#endif