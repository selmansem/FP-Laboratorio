#include <iostream>
#include <cmath>
#include "headers/ejercicios.h"
using namespace std;

/**
 * Pida la longitud del radio y calcule el área del círculo y la longitud de la circunferencia correspondientes.
 */
int calcularAreaCircunferencia()
{
    const float PI = 3.1416;
    float radio;
    float area;
    float longitud;

    cout << "Ingrese el radio del círculo: ";
    cin >> radio;

    area = PI * pow(radio, 2);
    longitud = 2 * PI * radio;

    cout << "Área del círculo: " << area << endl;
    cout << "Longitud de la circunferencia: " << longitud << endl;

    return 0;
}

int main()
{
    ejercicio("Cálculo del área del círculo y la longitud de la circunferencia");
    return calcularAreaCircunferencia();
}