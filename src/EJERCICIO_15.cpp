/**
 * Un programa que lea un entero positivo y diga si es perfecto o no.
 */
#include <iostream>
#include "headers/ejercicios.h"
using namespace std;

bool esPerfecto(int n)
{
    int sumaDivisores = 0;
    int i = 1;
    while (i <= n / 2)
    {
        if (n % i == 0)
        {
            sumaDivisores += i;
        }
        i++;
    }
    return sumaDivisores == n;
}

int main()
{
    ejercicio("Número Perfecto");

    int n;
    // Entrada: leer un entero positivo
    do
    {
        cout << "Ingrese un entero positivo: ";
        cin >> n;
    } while (n <= 0);

    // Proceso y Salida
    if (esPerfecto(n))
    {
        cout << n << " es un número perfecto." << endl;
    }
    else
    {
        cout << n << " no es un número perfecto." << endl;
    }

    return 0;
}