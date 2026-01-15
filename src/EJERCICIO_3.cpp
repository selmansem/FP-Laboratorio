#include <iostream>
#include "headers/ejercicios.h"
using namespace std;

/**
 * Algoritmo babilónico para calcular la raíz cuadrada de un número.
 * El usuario ingresa un número positivo y el programa calcula su raíz cuadrada.
 */
int calcularRaizCuadrada()
{
    double numero, estimacion, mejorEstimacion;
    cout << "Introduce un número positivo: ";
    cin >> numero;

    if (numero < 0)
    {
        cout << "El número debe ser positivo." << endl;
        return 1;
    }

    estimacion = numero / 2.0;         // Estimación inicial
    const double tolerancia = 0.00001; // Tolerancia para la precisión

    do
    {
        mejorEstimacion = (estimacion + numero / estimacion) / 2.0;
        if (abs(mejorEstimacion - estimacion) < tolerancia)
            break;
        estimacion = mejorEstimacion;
    } while (true);

    cout << "La raíz cuadrada de " << numero << " es aproximadamente " << mejorEstimacion << endl;
    return 0;
}

int main()
{
    ejercicio("Algoritmo babilónico para calcular la raíz cuadrada de un número");
    return calcularRaizCuadrada();
}
