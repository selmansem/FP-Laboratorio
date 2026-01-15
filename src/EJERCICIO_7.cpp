#include <iostream>
#include <cmath>
#include "headers/ejercicios.h"
using namespace std;

/**
 * El porcentaje de incremento de una cantidad. Calcular la variacion porcentual entre dos valores.
 * Formula: ((valor_final - valor_inicial) / valor_inicial) * 100
 */
int variacionPorcentual(double valor_inicial, double valor_final)
{
    if (valor_inicial == 0)
    {
        cout << "El valor inicial no puede ser cero." << endl;
        return -1; // Error: división por cero
    }
    double variacion = ((valor_final - valor_inicial) / valor_inicial) * 100;
    return variacion;
}

int main()
{
    ejercicio("Variación porcentual entre dos valores.");
    double valor_inicial, valor_final;
    cout << "Ingrese el valor inicial: ";
    cin >> valor_inicial;
    cout << "Ingrese el valor final: ";
    cin >> valor_final;

    double resultado = variacionPorcentual(valor_inicial, valor_final);
    if (resultado != -1)
    {
        cout << "La variación porcentual es: " << resultado << "%" << endl;
    }
    return 0;
}