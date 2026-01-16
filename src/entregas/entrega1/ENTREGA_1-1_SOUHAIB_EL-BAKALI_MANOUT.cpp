/**
 * @file ENTREGA_1-1_SOUHAIB_EL-BAKALI_MANOUT.cpp
 *
 * @brief Implementación de funciones para el proceso de Kaprekar.
 *
 * @author Souhaib El Bakali Manout
 * Email: souhaibem@correo.ugr.es
 *
 * @date 2026-01-03
 */

#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Convierte un número entero a una cadena de texto con relleno de ceros.
 *
 * Transforma un número entero en su representación de cadena de caracteres,
 * añadiendo ceros a la izquierda hasta alcanzar el número de dígitos especificado.
 *
 * @param entero El número entero a convertir.
 * @param num_casillas El número mínimo de dígitos que debe tener la cadena resultante.
 *                     Si el número tiene menos dígitos, se rellenará con ceros a la izquierda.
 *
 * @return Una cadena de texto que representa el número entero con el relleno de ceros aplicado.
 *
 * @example
 * ToStringInt(42, 5) retorna "00042"
 * ToStringInt(123, 3) retorna "123"
 * ToStringInt(7, 4) retorna "0007"
 */
string ToStringInt(int entero, int num_casillas)
{
    string resultado = to_string(entero);
    while (resultado.length() < num_casillas)
    {
        resultado = "0" + resultado;
    }
    return resultado;
}

/**
 * @brief Verifica si todos los caracteres de una cadena son distintos entre sí.
 *
 * Recorre la cadena comparando cada carácter con todos los caracteres
 * que le siguen. Si encuentra dos caracteres iguales, retorna false.
 * Si no hay caracteres repetidos, retorna true.
 *
 * @param cadena La cadena de texto a analizar.
 *
 * @return true si todos los caracteres de la cadena son diferentes entre sí,
 *         false si hay al menos dos caracteres iguales.
 *
 * @example
 * ValoresDistintos("1234") retorna true
 * ValoresDistintos("1123") retorna false
 * ValoresDistintos("abcd") retorna true
 * ValoresDistintos("abca") retorna false
 */
bool ValoresDistintos(const string &cadena)
{
    for (size_t i = 0; i < cadena.length(); i++)
    {
        for (size_t j = i + 1; j < cadena.length(); j++)
        {
            if (cadena[i] == cadena[j])
            {
                return false;
            }
        }
    }
    return true;
}

/**
 * @brief Crea un string invirtiendo los caracteres de otro string.
 *
 * Toma una cadena de texto y devuelve una nueva cadena con los caracteres
 * en orden inverso.
 *
 * @param cadena La cadena de texto original.
 *
 * @return Una nueva cadena con los caracteres invertidos.
 *
 * @example
 * Invertir("abcd") retorna "dcba"
 * Invertir("1234") retorna "4321"
 */
string Invertir(const string &cadena)
{
    // Se puede hacer con un bucle:
    // string invertida = "";
    // for (int i = cadena.length() - 1; i >= 0; i--)
    // {
    //     invertida += cadena[i];
    // }
    // return invertida;

    return string(cadena.rbegin(), cadena.rend());
}

/**
 * @brief Ordena los caracteres de una cadena en orden ascendente.
 *
 * Utiliza el algoritmo de ordenamiento burbuja para ordenar los caracteres
 * de la cadena de texto en orden ascendente (de menor a mayor).
 *
 * @param cadena La cadena de texto a ordenar.
 *
 * @return Una nueva cadena con los caracteres ordenados en orden ascendente.
 *
 * @example
 * Ordenar("dcba") retorna "abcd"
 * Ordenar("3214") retorna "1234"
 */
string Ordenar(string cadena)
{
    // Ordenamiento burbuja
    for (size_t i = 0; i < cadena.length() - 1; i++)
    {
        for (size_t j = 0; j < cadena.length() - 1 - i; j++)
        {
            if (cadena[j] > cadena[j + 1])
            {
                char temp = cadena[j];
                cadena[j] = cadena[j + 1];
                cadena[j + 1] = temp;
            }
        }
    }
    return cadena;
}

/**
 * @brief Realiza una iteración del proceso de Kaprekar en un número.
 *
 * Toma un número de hasta 4 dígitos, ordena sus dígitos para formar
 * el número mayor y el menor posibles, y calcula la diferencia entre ambos.
 *
 * @param numero El número entero de hasta 4 dígitos sobre el cual se realizará la iteración.
 *
 * @return El resultado de restar el número mayor menos el número menor.
 *
 * @example
 * IteracionKaprekar(3524) retorna 3087 (5432 - 2345 = 3087)
 * IteracionKaprekar(1000) retorna 999 (1000 - 0001 = 999)
 */
int IteracionKaprekar(int numero)
{
    string num_str = ToStringInt(numero, 4);

    // Ordenar ascendente (menor)
    string menor = Ordenar(num_str);

    // Ordenar descendente (mayor) = invertir el ordenado ascendente
    string mayor = Invertir(menor);

    // Restar mayor - menor
    int resultado = stoi(mayor) - stoi(menor);

    return resultado;
}

/**
 * @brief Verifica si se puede aplicar el proceso de Kaprekar a un número.
 *
 * Un número puede someterse al proceso de Kaprekar si no todos sus dígitos son iguales.
 *
 * @param numero El número entero a verificar.
 *
 * @return true si se puede aplicar el proceso de Kaprekar, false si todos los dígitos son iguales.
 *
 * @example
 * SePuedeAplicarKaprekar(1111) retorna false
 * SePuedeAplicarKaprekar(1234) retorna true
 */
bool SePuedeAplicarKaprekar(int numero)
{
    string num_str = ToStringInt(numero, 4);
    // Si todos los dígitos son iguales, no se puede aplicar
    // Esto es equivalente a que NO todos sean distintos Y el primero sea igual a todos
    char primer_digito = num_str[0];
    for (size_t i = 1; i < num_str.length(); i++)
    {
        if (num_str[i] != primer_digito)
        {
            return true; // Hay al menos dos dígitos diferentes
        }
    }
    return false; // Todos los dígitos son iguales
}

int main()
{
    const int CONSTANTE_KAPREKAR = 6174;
    int numero;

    cout << "Introduce numeros menores de 10000. Para terminar, introduce 0:" << endl;

    cin >> numero;

    while (numero != 0)
    {
        // Validar que el número sea menor de 10000 y positivo
        if (numero < 0 || numero >= 10000)
        {
            cout << "Error: El numero debe ser positivo y menor de 10000." << endl;
        }
        else if (!SePuedeAplicarKaprekar(numero))
        {
            cout << "Al " << numero << " no se le puede aplicar el proceso de Kaprekar "
                 << "(todos los digitos son iguales)." << endl;
        }
        else
        {
            // Aplicar el proceso de Kaprekar
            int actual = numero;
            int iteraciones = 0;

            while (actual != CONSTANTE_KAPREKAR)
            {
                actual = IteracionKaprekar(actual);
                iteraciones++;
            }

            cout << "El " << numero << " alcanza 6174 en " << iteraciones
                 << " iteracion(es)." << endl;
        }

        cin >> numero;
    }

    cout << "Fin del programa." << endl;

    return 0;
}