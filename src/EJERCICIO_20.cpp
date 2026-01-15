/**
 * Dos ejercicios:
 * - Un modulo que acepte dos doubles  devuelva el maximo.
 * - Un main que lea cuatro doubles y devuelva el máximo de los cuatro.
 */


#include <iostream>
using namespace std;
double maximo(double a, double b) {
    return (a > b) ? a : b;
}

int main() {
    double num1, num2, num3, num4;
    cout << "Ingrese cuatro numeros separados por espacios: ";
    cin >> num1 >> num2 >> num3 >> num4;

    double max1 = maximo(num1, num2);
    double max2 = maximo(num3, num4);
    double maxFinal = maximo(max1, max2);

    cout << "El maximo de los cuatro numeros es: " << maxFinal << endl;
    return 0;
}