#include <iostream>
using namespace std;

/**
 * Declara dos variables con valores x=30 e y=100.
 * Intercambia los valores de las variables.
 */
int x = 30;
int y = 100;
int temp;

void printValues(string header, int x, int y)
{
    cout << header << endl;
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
}

int main()
{
    printValues("Valores iniciales:", x, y);
    temp = x;
    x = y;
    y = temp;
    printValues("Valores intercambiados:", x, y);
}