#include <iostream>
#include <map>
#include <string>

void agregarContacto(std::map<std::string, std::string> &contacto, const std::string& nombre, const std::string& telefono){


}

int main(){

    std::map<std::string, std::string> contactos;

    contactos["Aura"] = "3005091057";
    contactos["Juan"] = "3198435364";
    contactos["Deiby"] = "3056448762";
    contactos["Isabella"] = "3202750141";

    auto opcion =0;
    std::cout << "Elija una opcion: \n";

    do{
        std::cout << "1. Agregar contacto \n2. Buscar por nombre \n3. Mostrar todos los contactos ordenados \n4. Eliminar un contacto \n5. Salir";
        std::cin >> opcion;
        
        switch (opcion){
            case 1:
                break;
        }

    }while(opcion !=5);




}