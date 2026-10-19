#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <optional>
#include <cmath>
#include <vector>
int arreglo[6];



class HashTable {
    private:
    int bits;
    int cantidad = 0;
    std::vector<std::vector<std::string>> tablaHash;

    unsigned long int funcionHashSuma(const std::string& palabra){
        unsigned long int suma = 0;
        for(char c : palabra){
            suma += static_cast<int>(c);
        }
        return suma & ((1UL << bits) - 1);
    }
    unsigned long int funcionHashMult(const std::string& palabra){
        unsigned long int mult = 1;
        for(char c : palabra){
            mult *= static_cast<int>(c);
        }
        return mult & ((1UL << bits) - 1);
    }
    unsigned long funcionHashXOR(const std::string& palabra) {
        const unsigned long mascara = (1UL << bits) - 1;
        unsigned long resultado = 0;
        unsigned long acum = 0;
        int bitsAcum = 0;

        for (char ch : palabra) {
            unsigned char c = static_cast<unsigned char>(ch);   // evita negativos
            acum = (acum << 8) | c;
            bitsAcum += 8;

            while (bitsAcum >= bits) {
                resultado ^= (acum >> (bitsAcum - bits)) & mascara;  // bloque de n bits
                bitsAcum -= bits;
                acum &= (1UL << bitsAcum) - 1;   // descarta los bits ya usados
            }
        }

        if (bitsAcum > 0) {
            resultado ^= (acum << (bits - bitsAcum)) & mascara;
        }
        return resultado;
    }


public:
    HashTable(int bits = 4) : bits(bits) {
        tablaHash.resize(1 << bits);
    }
    int indice(const std::string& palabra, int opcion){
        if (opcion == 1){
            int ind = funcionHashSuma(palabra);
            return ind;
        }
        else if(opcion == 2){
            int ind = funcionHashMult(palabra);
            return ind;
        }
        else if(opcion == 3) {
            int ind = funcionHashXOR(palabra);
            return ind;
        }
        else{
            std::cout << "Opcion invalida" << std::endl;
        }
        return 0;

    }

    void insertarElemento(const std::string& palabra, int ind){
        tablaHash[ind].push_back(palabra);
        cantidad++;   

    }

    void mostrarColisiones(){
        for (std::size_t i = 0; i < tablaHash.size(); i++){
            if (tablaHash[i].size() >= 2){
                
                std::cout << "La cantidad de elementos colisionados en el bucket " << i << " es de: " << tablaHash[i].size() <<  std::endl;
            }
        }
    }

    void resumen() const {
        std::size_t vacias = 0, colisionadas = 0, peor = 0;
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
                std::cout << tablaHash.size();
    }

    // Remove all key-value pairs from the hash table.
    void clear(){
        for (auto& c : tablaHash) c.clear();
        cantidad = 0;
    }

    void crecer(){

        std::vector<std::vector<std::string>> nueva(tablaHash.size() * 2);

        bits += 1;                             
        for (auto& cubeta : tablaHash)
            for (auto& p : cubeta)
                nueva[indice(p,mejorFuncion())].push_back(p);   // ahora usa b
        tablaHash = nueva;
    }
    
    int mejorFuncion(){
        int mejorBucket = arreglo[0];
        int funcionMejor = 0;
        for (int i = 0; i < 3; i++){
            if( arreglo[i] <= mejorBucket){
                mejorBucket = arreglo[i];
                funcionMejor = i;
            }
        }
        return funcionMejor+1; //opcion
    }
    
};

#endif // HASHTABLE_H