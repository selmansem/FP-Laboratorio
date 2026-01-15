#include <iostream>
#include "headers/ejercicios.h"
using namespace std;

/**
 * Cálculo de salario final con incremento fijo.
 */
int calcularSalarioFinal()
{
    int salario_base;
    int salario_final;
    int incremento;

    salario_base = 1000;
    incremento = 200;

    salario_final = salario_base;
    salario_final = salario_final + incremento;
    salario_base = 3500;

    cout << "Salario base: " << salario_base << endl;
    cout << "Salario final: " << salario_final << endl;
    return salario_final;
}

int main()
{
    ejercicio("Cálculo de salario final con incremento fijo");
    return calcularSalarioFinal();
}