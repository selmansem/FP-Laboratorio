#include <iostream>
#include "headers/ejercicios.h"
using namespace std;

/**
 * Determina si un numero es par o impar.
 */
void parImpar(int numero)
{
    bool esPar = false;
    (numero % 2 == 0)
        ? esPar = true
        : esPar = false;

    (esPar)
        ? cout << "El numero " << numero << " es par." << endl
        : cout << "El numero " << numero << " es impar." << endl;
}

int main()
{
    int numero;

    cout << "Ingrese un numero entero: ";
    cin >> numero;

    parImpar(numero);

    return 0;
}