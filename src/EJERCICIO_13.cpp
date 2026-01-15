// Sucesión de Fibonacci
#include <iostream>
#include "headers/ejercicios.h"
using namespace std;

void fibonacci(int n)
{
    int fib1 = 1, fib2 = 2, fib = 1;

    int i = 2;
    while (i <= n)
    {
        cout << fib1 << " ";
        fib = fib1 + fib2;
        fib1 = fib2;
        fib2 = fib;
        ++i;
    }
}

int main()
{
    ejercicio("Sucesion de Fibonacci");

    int n;
    cout << "Ingrese la cantidad de terminos de la sucesion de Fibonacci que desea ver: ";
    cin >> n;

    cout << "Los primeros " << n << " terminos de la sucesion de Fibonacci son: ";
    fibonacci(n);
    cout << endl;

    return 0;
}