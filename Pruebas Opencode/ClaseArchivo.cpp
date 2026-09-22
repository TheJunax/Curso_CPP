#include <iostream>
#include <fstream>
#include <string>

class Archivo {
private:
    std::ofstream salida;   // el recurso: igual que "FILE* f" en C

public:
    // CONSTRUCTOR: recibe el nombre y abre el archivo
    Archivo(std::string nombre)
        : salida(nombre)    // LISTA DE INICIALIZACION: salida nace ya abriendo el archivo
    {
        if (!salida) {      // si el archivo NO se pudo abrir (igual que f == NULL en C)
            std::cerr << "ERROR: no se pudo abrir " << nombre << '\n';
        }
    }

    // METODO: escribe una linea en el archivo
    void escribir(std::string texto) {
        salida << texto << '\n';   // como cout, pero dirigido al archivo
    }

    // DESTRUCTOR: se llama SOLO cuando el objeto muere
    ~Archivo() {
        salida.close();     // cierra el archivo (fclose de C, pero automatico)
    }
};

int main() {
    {
        Archivo log("bitacora.txt");            // nace AQUI -> constructor abre el archivo
        log.escribir("primer registro");        // escribe linea 1
        log.escribir("segundo registro");       // escribe linea 2
    }   // <-- log muere AQUI -> destructor cierra el archivo SOLO

    std::cout << "bloque terminado, archivo cerrado\n";
    return 0;
}