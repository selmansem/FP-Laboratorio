/**
 * Realiza un programa que lea un entero y
 * determina si es positivo, negativo o cero.
 *
 * Usa el tipo enumerado "Estado" con los valores "POSITIVO", "NEGATIVO" y "CERO".
 */

#include <iostream>
#include "headers/ejercicios.h"
using namespace std;

enum class Estado
{
    POSITIVO,
    NEGATIVO,
    CERO
};

/**
 * @brief Determina si un número entero es positivo, negativo o cero.
 *
 * @param numero Entero a evaluar.
 * @retval Estado::POSITIVO   Si \p numero es mayor que 0.
 * @retval Estado::NEGATIVO   Si \p numero es menor que 0.
 * @retval Estado::CERO       Si \p numero es igual a 0.
 *
 * @remarks No modifica ningún estado global ni lanza excepciones.
 */
Estado determinarEstado(int numero)
{
    if (numero > 0)
    {
        return Estado::POSITIVO;
    }
    else if (numero < 0)
    {
        return Estado::NEGATIVO;
    }
    else
    {
        return Estado::CERO;
    }
}

int main()
{
    ejercicio("Determinar si un numero es positivo, negativo o cero");

    // ENTRADA
    int numero;
    cout << "Introduce un entero: ";
    cin >> numero;

    // PROCESO
    Estado estado = determinarEstado(numero);

    // SALIDA
    switch (estado)
    {
    case Estado::POSITIVO:
        cout << "El numero es positivo." << endl;
        break;
    case Estado::NEGATIVO:
        cout << "El numero es negativo." << endl;
        break;
    case Estado::CERO:
        cout << "El numero es cero." << endl;
        break;
    }

    return 0;
}