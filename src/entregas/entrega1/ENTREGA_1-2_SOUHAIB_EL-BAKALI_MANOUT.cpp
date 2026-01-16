/**
 * @file ENTREGA_1-2_SOUHAIB_EL-BAKALI_MANOUT.cpp
 *
 * @brief Localizar el palíndromo de mayor longitud en una secuencia de caracteres.
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
 * @class SecuenciaCaracteres
 * @brief Clase que representa una secuencia de caracteres con funcionalidad para detectar palíndromos.
 *
 * Implementa métodos para añadir caracteres, verificar si la secuencia es un palíndromo
 * y encontrar el mayor palíndromo dentro de la secuencia.
 */
class SecuenciaCaracteres
{
private:
    static const int TAMANIO = 500;
    char v[TAMANIO];
    int utilizados;

    /**
     * @brief Expande desde el centro para encontrar el palíndromo más largo.
     *
     * @param izq Índice izquierdo inicial.
     * @param der Índice derecho inicial.
     * @param inicio Referencia donde se guardará el índice de inicio del palíndromo.
     * @param longitud Referencia donde se guardará la longitud del palíndromo.
     */
    void ExpandirDesdeCentro(int izq, int der, int &inicio, int &longitud) const
    {
        while (izq >= 0 && der < utilizados && v[izq] == v[der])
        {
            izq--;
            der++;
        }
        inicio = izq + 1;
        longitud = der - izq - 1;
    }

public:
    SecuenciaCaracteres()
    {
        utilizados = 0;
    }

    int Utilizados() const
    {
        return utilizados;
    }

    int Capacidad() const
    {
        return TAMANIO;
    }

    void Aniade(char nuevo)
    {
        if (utilizados < TAMANIO)
        {
            v[utilizados] = nuevo;
            utilizados++;
        }
    }

    char Elemento(int indice) const
    {
        return v[indice];
    }

    bool EsPalindromo() const
    {
        int izq = 0;
        int der = utilizados - 1;

        while (izq < der)
        {
            if (v[izq] != v[der])
            {
                return false;
            }
            izq++;
            der--;
        }
        return true;
    }

    /**
     * @brief Encuentra y devuelve el palíndromo de mayor longitud contenido en la secuencia.
     *
     * Utiliza la técnica de expansión desde el centro con complejidad O(n²),
     * más eficiente que la búsqueda exhaustiva O(n³).
     *
     * @return SecuenciaCaracteres. El palíndromo más largo encontrado.
     */
    SecuenciaCaracteres MayorPalindromo() const
    {
        SecuenciaCaracteres resultado;

        if (utilizados == 0)
        {
            return resultado;
        }

        int mejor_inicio = 0;
        int mejor_longitud = 1;

        for (int i = 0; i < utilizados; i++)
        {
            int inicio, longitud;

            // Palíndromo impar (centro en i)
            ExpandirDesdeCentro(i, i, inicio, longitud);
            if (longitud > mejor_longitud)
            {
                mejor_inicio = inicio;
                mejor_longitud = longitud;
            }

            // Palíndromo par (centro entre i e i+1)
            ExpandirDesdeCentro(i, i + 1, inicio, longitud);
            if (longitud > mejor_longitud)
            {
                mejor_inicio = inicio;
                mejor_longitud = longitud;
            }
        }

        for (int i = mejor_inicio; i < mejor_inicio + mejor_longitud; i++)
        {
            resultado.Aniade(v[i]);
        }

        return resultado;
    }
};

int main()
{
    SecuenciaCaracteres secuencia;
    string cadena;

    cout << "Introduce una cadena de caracteres: ";
    cin >> cadena;

    for (size_t i = 0; i < cadena.length(); i++)
    {
        secuencia.Aniade(cadena[i]);
    }

    SecuenciaCaracteres palindromo = secuencia.MayorPalindromo();

    cout << "Mayor palindromo: ";
    for (int i = 0; i < palindromo.Utilizados(); i++)
    {
        cout << palindromo.Elemento(i);
    }
    cout << endl;

    return 0;
}