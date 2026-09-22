/*
 * RETO VC1: Traduccion C -> C++
 *
 * Este programa esta escrito en C. Tu tarea es traducirlo a C++:
 *   - <stdio.h>  ->  <iostream>
 *   - printf     ->  cout <<
 *   - scanf      ->  cin >>
 *
 * Compilar con:  g++ -Wall -Wextra -g suma.cpp -o output/suma
 * Ejecutar con:  ./output/suma
 *
 * Animate: cambia linea por linea y compila al final.
 */

#include <iostream>
using namespace std;

int main() {
    int a, b;

    cout << "Dame el primer numero: ";
    cin >> a;

    cout << "Dame el segundo numero: ";
    cin >> b;

    cout << "La suma es: " << a + b <<"\n";

    return 0;
}