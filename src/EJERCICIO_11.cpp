/**
 * un programa que lea un real x y un entero n, y calcule el valor de x^n utilizando un bucle while.
 * Usar el operador *= para la multiplicación.
 */
#include <iostream>
using namespace std;

int main()
{
    double x;
    int n;
    double resultado = 1.0;

    cout << "Ingrese un numero real (x): ";
    cin >> x;
    cout << "Ingrese un entero (n): ";
    cin >> n;

    if (n < 0)
    {
        cout << "Error: El exponente debe ser un entero no negativo." << endl;
        return 1;
    }

    int i = 0;
    while (i < n)
    {
        resultado *= x;
        i++;
    }

    cout << "El resultado de " << x << "^" << n << " es " << resultado << endl;

    return 0;
}