/**
 * @file ENTREGA_1-3_SOUHAIB_EL-BAKALI_MANOUT.cpp
 *
 * @brief Comparación de tableros de importancia relativa.
 *
 * @author Souhaib El Bakali Manout
 * Email: souhaibem@correo.ugr.es
 *
 * @date 2026-01-06
 */

#include <iostream>

using namespace std;

class TableroCuadrado
{
private:
    static const int MAX = 15;
    int celdas[MAX][MAX];
    int dimension;

    /**
     * @brief Cuenta cuántas veces el valor en (fil, col) es mayor que sus vecinos.
     *
     * @param fil Fila de la celda.
     * @param col Columna de la celda.
     * @return Número de vecinos que son menores que el valor en (fil, col).
     */
    int ContarMayorQueVecinos(int fil, int col) const
    {
        int valor = celdas[fil][col];
        int contador = 0;

        // Recorrer el entorno 3x3
        for (int i = fil - 1; i <= fil + 1; i++)
        {
            for (int j = col - 1; j <= col + 1; j++)
            {
                // Excluir la celda central (la propia)
                if (i != fil || j != col)
                {
                    if (valor > celdas[i][j])
                    {
                        contador++;
                    }
                }
            }
        }

        return contador;
    }

public:
    TableroCuadrado()
    {
        dimension = 0;
    }

    TableroCuadrado(int dim)
    {
        dimension = dim;
        // Inicializar a 0
        for (int i = 0; i < dimension; i++)
        {
            for (int j = 0; j < dimension; j++)
            {
                celdas[i][j] = 0;
            }
        }
    }

    int GetDimension() const
    {
        return dimension;
    }

    int Elemento(int fil, int col) const
    {
        return celdas[fil][col];
    }

    // Método para establecer un valor (necesario para las pruebas)
    void SetElemento(int fil, int col, int valor)
    {
        celdas[fil][col] = valor;
    }

    /**
     * @brief Devuelve un nuevo tablero con la importancia relativa de cada celda.
     *
     * El valor de cada posición en el nuevo tablero es el número de veces que
     * el valor original es mayor que sus vecinos en un entorno 3x3.
     * Los bordes tienen valor 0.
     *
     * @return TableroCuadrado Nuevo tablero con la importancia relativa.
     */
    TableroCuadrado TableroImportanciaRelativa() const
    {
        TableroCuadrado resultado(dimension);

        // Recorrer solo las celdas interiores (excluir bordes)
        for (int i = 1; i < dimension - 1; i++)
        {
            for (int j = 1; j < dimension - 1; j++)
            {
                resultado.celdas[i][j] = ContarMayorQueVecinos(i, j);
            }
        }

        // Los bordes ya están en 0 por el constructor

        return resultado;
    }

    /**
     * @brief Muestra el tablero en consola.
     */
    void Mostrar() const
    {
        for (int i = 0; i < dimension; i++)
        {
            for (int j = 0; j < dimension; j++)
            {
                cout << celdas[i][j] << "  ";
            }
            cout << endl;
        }
    }
};

int main()
{
    // Crear el tablero del ejemplo (6x6)
    TableroCuadrado tablero(6);

    // Rellenar con los valores del ejemplo
    int valores[6][6] = {
        {5, 6, 3, 6, 5, 4},
        {4, 1, 2, 2, 6, 3},
        {4, 7, 1, 1, 6, 1},
        {3, 4, 1, 1, 3, 5},
        {4, 6, 4, 4, 6, 4},
        {4, 7, 3, 3, 7, 6}};

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            tablero.SetElemento(i, j, valores[i][j]);
        }
    }

    cout << "Tablero original:" << endl;
    tablero.Mostrar();

    cout << endl
         << "Tablero de importancia relativa:" << endl;
    TableroCuadrado resultado = tablero.TableroImportanciaRelativa();
    resultado.Mostrar();

    return 0;
}