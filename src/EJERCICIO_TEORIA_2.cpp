#include <iostream>
#include "headers/ejercicios.h"

using namespace std;

void tipoTriangulo(int a, int b, int c)
{
    bool esTriangulo = (a + b > c) && (a + c > b) && (b + c > a);
    
    if (esTriangulo)
    {
        if (a == b && b == c)
        {
            cout << "Sí (equilátero)" << endl;
        }
        else if (a == b || a == c || b == c)
        {
            cout << "Sí (isósceles)" << endl;
        }
        else
        {
            cout << "Sí (escaleno)" << endl;
        }
    }
    else
    {
        cout << "Los lados no forman un triángulo." << endl;
    }
}

int main()
{
    ejercicio("Determinar si se puede formar un triángulo y el tipo según la longitud de sus lados.");

    int a, b, c;
    cout << "Ingrese la longitud del lado a: ";
    cin >> a;
    cout << "Ingrese la longitud del lado b: ";
    cin >> b;
    cout << "Ingrese la longitud del lado c: ";
    cin >> c;

    tipoTriangulo(a, b, c);

    return 0;
}