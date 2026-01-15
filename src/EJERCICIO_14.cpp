#include <iostream>
#include "headers/ejercicios.h"
using namespace std;

// Función que calcula el factorial de un número entero n
long long factorial(int n)
{
    long long resultado = 1;
    int i = 1;
    while (i <= n)
    {
        resultado = resultado * i;
        i++;
    }
    return resultado;
}

// Función que calcula la potencia x^n (sin usar pow)
double potencia(double x, int n)
{
    double resultado = 1.0;
    int i = 1;
    while (i <= n)
    {
        resultado *= x;
        resultado = resultado * x;
        i++;
    }
    return resultado;
}

int main()
{
    ejercicio("Cálculo de Factorial y Potencia");

    int n;
    double x;

    // ENTRADA
    // Lectura del entero n, validando que esté en [1, 20]
    while (n < 1 || n > 20)
    {
        cout << "Introduce un número entero n (1 ≤ n ≤ 20): ";
        cin >> n;
    }

    // Lectura del número real x
    cout << "Introduce un número real x: ";
    cin >> x;

    // PROCESO
    // Cálculos
    long long fact = factorial(n);
    double pot = potencia(x, n);

    // SALIDA
    // Resultados
    cout << "Resultados: ";
    cout << n << "! = " << fact << endl;
    cout << x << "^" << n << " = " << pot << endl;

    return 0;
}
