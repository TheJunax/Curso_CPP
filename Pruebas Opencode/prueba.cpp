#include <iostream>

int main() {
    int numero = 91080; // Ocupa 4 bytes (32 bits)
    
    // Forzamos a C++ a leer la memoria del entero como si fuera un arreglo de bytes (char)
    unsigned char* punteroByte = reinterpret_cast<unsigned char*>(&numero);

    std::cout << "Bytes en memoria (Little-Endian): \n";
    for(int i = 0; i < sizeof(int); i++) {
        // Imprimimos el valor numérico de cada bloque de 8 bits
        std::cout << "Dirección +" << i << " : " << static_cast<int>(punteroByte[i]) << "\n";
    }

    return 0;
}