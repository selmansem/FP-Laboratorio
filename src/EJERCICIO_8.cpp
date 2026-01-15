#include <iostream>
#include "headers/ejercicios.h"

using namespace std;

void mostrarCifrasSeparadas(int n)
{
    int centena = n / 100;
    int decena = (n / 10) % 10;
    int unidad = n % 10;

    cout << "Centena: " << centena << endl;
    cout << "Decena: " << decena << endl;
    cout << "Unidad: " << unidad << endl;
}

int main()
{
    ejercicio("Mostrar cifras de un número de tres cifras en líneas separadas.");
    int n;
    cout << "Ingrese un número de tres cifras: ";
    cin >> n;

    if (n < 100 || n > 999)
    {
        cout << "Error: El número debe ser de tres cifras." << endl;
        return 1;
    }

    mostrarCifrasSeparadas(n);
    return 0;
}