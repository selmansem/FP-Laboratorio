#include <iostream>
#include <cmath>
#include "headers/ejercicios.h"
using namespace std;

/**
 * Calcular PI a partir del arco seno de 1 (PI = 6 * arcsen(1/2)).
 */
int calcularPI()
{
    double pi = 6 * asin(1.0 / 2);
    cout << "Valor de PI: " << pi << endl;
    return 0;
}

int main()
{
    ejercicio("Cálculo de PI");
    return calcularPI();
}