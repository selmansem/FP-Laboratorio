/**
 * Realizar un modulo que acepte un numero n y devuelva su factorial.
 */
#include <iostream>
#include "headers/ejercicios.h"
using namespace std;

// Función para calcular el factorial de un número
int factorial(int n) {
    if (n < 0) {
        cout << "El factorial no está definido para números negativos." << endl;
        return -1; // Indicador de error
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    int resultado = 1;
    for (int i = 2; i <= n; ++i) {
        resultado *= i;
    }
    return resultado;
}

int main() {
    ejercicio("Calculo del Factorial de un Numero");
    int numero;
    cout << "Ingrese un numero para calcular su factorial: ";
    cin >> numero;
    cout << "El factorial de " << numero << " es: " << factorial(numero) << endl;
    return 0;
}