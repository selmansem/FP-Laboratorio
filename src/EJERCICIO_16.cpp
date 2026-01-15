#include <iostream>
#include <string>
#include "headers/ejercicios.h"
using namespace std;

string imprimir = "";

string dibujarArbol(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            imprimir += " ";
        }
        
        for (int j = 1; j <= i; j++)
        {
            imprimir += "*";
        }
        imprimir += "\n";
    }
    return imprimir;
}

int main()
{
    ejercicio("Dibujo de arbol ASCII");

    int altura;
    cout << "Ingrese la altura del arbol: ";
    cin >> altura;
    cout << dibujarArbol(altura) << endl;
    return 0;
}