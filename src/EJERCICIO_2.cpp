#include <iostream>
#include "headers/ejercicios.h"
using namespace std;

/**
 * Resolver un sistema de ecuaciones con dos incógnitas.
 * ax+by=c
 * dx+ey=f
 */
double a, b, c, d, e, f;
double x, y;

int calcularEcuaciones()
{
    cout << "Introduce los valores a, b, c, d, e, f separados por espacios: ";
    cin >> a >> b >> c >> d >> e >> f;

    double denominator = a * e - b * d;
    if (denominator == 0)
    {
        cout << "El sistema no tiene solución única." << endl;
        return 1;
    }

    x = (c * e - b * f) / denominator;
    y = (a * f - c * d) / denominator;

    cout << "La solución del sistema es:" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    return 0;
}

int main()
{
    ejercicio("Resolver un sistema de ecuaciones con dos incógnitas");
    return calcularEcuaciones();
}