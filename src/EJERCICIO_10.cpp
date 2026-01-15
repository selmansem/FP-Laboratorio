/**
 * Un programa que lea un entero positivo y mostrar su factorial
 * Usa while.
 */
#include <iostream>
using namespace std;

int main()
{
    int numero;
    unsigned long long factorial = 1;

    cout << "Ingrese un entero positivo: ";
    cin >> numero;

    if (numero < 0)
    {
        cout << "Error! El factorial de un numero negativo no existe." << endl;
    }
    else
    {
        int i = 1;
        while (i <= numero)
        {
            factorial *= i;
            i++;
        }
        cout << "El factorial de " << numero << " es " << factorial << endl;
    }

    return 0;
}