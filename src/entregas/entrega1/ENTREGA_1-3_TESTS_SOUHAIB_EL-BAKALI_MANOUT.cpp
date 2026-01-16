/**
 * @file ENTREGA_1-3_TESTS_SOUHAIB_EL-BAKALI_MANOUT.cpp
 *
 * @brief Tests unitarios para el cálculo de tableros de importancia relativa.
 *
 * @author Souhaib El Bakali Manout
 * Email: souhaibem@correo.ugr.es
 *
 * @date 2026-01-06
 */

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// Variable global para modo verbose
bool verbose = false;

// ============== CLASE A TESTEAR ==============

class TableroCuadrado
{
private:
    static const int MAX = 15;
    int celdas[MAX][MAX];
    int dimension;

    int ContarMayorQueVecinos(int fil, int col) const
    {
        int valor = celdas[fil][col];
        int contador = 0;

        for (int i = fil - 1; i <= fil + 1; i++)
        {
            for (int j = col - 1; j <= col + 1; j++)
            {
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

    void SetElemento(int fil, int col, int valor)
    {
        celdas[fil][col] = valor;
    }

    TableroCuadrado TableroImportanciaRelativa() const
    {
        TableroCuadrado resultado(dimension);

        for (int i = 1; i < dimension - 1; i++)
        {
            for (int j = 1; j < dimension - 1; j++)
            {
                resultado.celdas[i][j] = ContarMayorQueVecinos(i, j);
            }
        }

        return resultado;
    }
};

// ============== FUNCIONES AUXILIARES ==============

TableroCuadrado CrearTablero(int dim, int valores[][15])
{
    TableroCuadrado t(dim);
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            t.SetElemento(i, j, valores[i][j]);
        }
    }
    return t;
}

bool TablerosIguales(const TableroCuadrado &t1, const TableroCuadrado &t2)
{
    if (t1.GetDimension() != t2.GetDimension())
    {
        return false;
    }

    for (int i = 0; i < t1.GetDimension(); i++)
    {
        for (int j = 0; j < t1.GetDimension(); j++)
        {
            if (t1.Elemento(i, j) != t2.Elemento(i, j))
            {
                return false;
            }
        }
    }

    return true;
}

// ============== FRAMEWORK DE TESTS ==============

int tests_pasados = 0;
int tests_fallidos = 0;

void test(bool condicion, const string &nombre_test)
{
    if (condicion)
    {
        if (verbose)
        {
            cout << "  ✓ " << nombre_test << endl;
        }
        tests_pasados++;
    }
    else
    {
        // Los tests fallidos siempre se muestran
        cout << "  ✗ " << nombre_test << " [FALLIDO]" << endl;
        tests_fallidos++;
    }
}

// ============== TESTS ==============

void test_Constructor()
{
    if (verbose)
        cout << "\n== Tests Constructor ==" << endl;

    TableroCuadrado t1;
    test(t1.GetDimension() == 0, "Constructor vacio tiene dimension 0");

    TableroCuadrado t2(5);
    test(t2.GetDimension() == 5, "Constructor con dimension 5");

    TableroCuadrado t3(3);
    bool todos_cero = true;
    for (int i = 0; i < 3 && todos_cero; i++)
    {
        for (int j = 0; j < 3 && todos_cero; j++)
        {
            if (t3.Elemento(i, j) != 0)
            {
                todos_cero = false;
            }
        }
    }
    test(todos_cero, "Constructor inicializa celdas a 0");
}

void test_GetDimension_y_Elemento()
{
    if (verbose)
        cout << "\n== Tests GetDimension y Elemento ==" << endl;

    TableroCuadrado t(4);
    test(t.GetDimension() == 4, "GetDimension devuelve 4");

    t.SetElemento(1, 2, 7);
    test(t.Elemento(1, 2) == 7, "Elemento(1,2) devuelve valor seteado");

    t.SetElemento(0, 0, 5);
    t.SetElemento(3, 3, 9);
    test(t.Elemento(0, 0) == 5, "Elemento en esquina superior izquierda");
    test(t.Elemento(3, 3) == 9, "Elemento en esquina inferior derecha");
}

void test_ImportanciaRelativa_ejemplo_enunciado()
{
    if (verbose)
        cout << "\n== Tests TableroImportanciaRelativa (ejemplo del enunciado) ==" << endl;

    int valores[15][15] = {
        {5, 6, 3, 6, 5, 4},
        {4, 1, 2, 2, 6, 3},
        {4, 7, 1, 1, 6, 1},
        {3, 4, 1, 1, 3, 5},
        {4, 6, 4, 4, 6, 4},
        {4, 7, 3, 3, 7, 6}};

    int esperado[15][15] = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 3, 2, 6, 0},
        {0, 8, 0, 0, 7, 0},
        {0, 3, 0, 0, 3, 0},
        {0, 7, 4, 5, 6, 0},
        {0, 0, 0, 0, 0, 0}};

    TableroCuadrado tablero = CrearTablero(6, valores);
    TableroCuadrado resultado = tablero.TableroImportanciaRelativa();
    TableroCuadrado esperadoT = CrearTablero(6, esperado);

    test(TablerosIguales(resultado, esperadoT), "Ejemplo del enunciado 6x6 completo");

    // Verificar algunos valores específicos
    test(resultado.Elemento(2, 1) == 8, "Posicion (2,1) = 8 (7 mayor que todos sus vecinos)");
    test(resultado.Elemento(1, 2) == 3, "Posicion (1,2) = 3 (2 mayor que tres vecinos)");
    test(resultado.Elemento(1, 4) == 6, "Posicion (1,4) = 6 (6 mayor que seis vecinos)");
}

void test_ImportanciaRelativa_bordes_cero()
{
    if (verbose)
        cout << "\n== Tests TableroImportanciaRelativa (bordes en cero) ==" << endl;

    int valores[15][15] = {
        {9, 9, 9, 9},
        {9, 5, 5, 9},
        {9, 5, 5, 9},
        {9, 9, 9, 9}};

    TableroCuadrado tablero = CrearTablero(4, valores);
    TableroCuadrado resultado = tablero.TableroImportanciaRelativa();

    // Verificar que todos los bordes son 0
    bool bordes_cero = true;
    int dim = resultado.GetDimension();

    // Fila superior e inferior
    for (int j = 0; j < dim && bordes_cero; j++)
    {
        if (resultado.Elemento(0, j) != 0 || resultado.Elemento(dim - 1, j) != 0)
        {
            bordes_cero = false;
        }
    }

    // Columna izquierda y derecha
    for (int i = 0; i < dim && bordes_cero; i++)
    {
        if (resultado.Elemento(i, 0) != 0 || resultado.Elemento(i, dim - 1) != 0)
        {
            bordes_cero = false;
        }
    }

    test(bordes_cero, "Todos los bordes tienen valor 0");
}

void test_ImportanciaRelativa_tablero_uniforme()
{
    if (verbose)
        cout << "\n== Tests TableroImportanciaRelativa (tablero uniforme) ==" << endl;

    int valores[15][15] = {
        {5, 5, 5, 5, 5},
        {5, 5, 5, 5, 5},
        {5, 5, 5, 5, 5},
        {5, 5, 5, 5, 5},
        {5, 5, 5, 5, 5}};

    TableroCuadrado tablero = CrearTablero(5, valores);
    TableroCuadrado resultado = tablero.TableroImportanciaRelativa();

    // Todas las celdas interiores deben ser 0 (ningun valor es mayor que sus vecinos iguales)
    bool interiores_cero = true;
    for (int i = 1; i < 4 && interiores_cero; i++)
    {
        for (int j = 1; j < 4 && interiores_cero; j++)
        {
            if (resultado.Elemento(i, j) != 0)
            {
                interiores_cero = false;
            }
        }
    }

    test(interiores_cero, "Tablero uniforme: todas las celdas interiores son 0");
}

void test_ImportanciaRelativa_valor_maximo()
{
    if (verbose)
        cout << "\n== Tests TableroImportanciaRelativa (valor maximo 8) ==" << endl;

    int valores[15][15] = {
        {1, 1, 1},
        {1, 9, 1},
        {1, 1, 1}};

    TableroCuadrado tablero = CrearTablero(3, valores);
    TableroCuadrado resultado = tablero.TableroImportanciaRelativa();

    test(resultado.Elemento(1, 1) == 8, "Centro mayor que todos sus 8 vecinos = 8");
}

void test_ImportanciaRelativa_tablero_minimo()
{
    if (verbose)
        cout << "\n== Tests TableroImportanciaRelativa (tablero 3x3) ==" << endl;

    int valores[15][15] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    TableroCuadrado tablero = CrearTablero(3, valores);
    TableroCuadrado resultado = tablero.TableroImportanciaRelativa();

    test(resultado.GetDimension() == 3, "Dimension del resultado es 3");
    // El 5 central es mayor que 1, 2, 3, 4 = 4 vecinos
    test(resultado.Elemento(1, 1) == 4, "Centro(5) mayor que 4 vecinos");
}

void test_ImportanciaRelativa_dimension_conservada()
{
    if (verbose)
        cout << "\n== Tests TableroImportanciaRelativa (dimension conservada) ==" << endl;

    TableroCuadrado t3(3);
    test(t3.TableroImportanciaRelativa().GetDimension() == 3, "Tablero 3x3 conserva dimension");

    TableroCuadrado t5(5);
    test(t5.TableroImportanciaRelativa().GetDimension() == 5, "Tablero 5x5 conserva dimension");

    TableroCuadrado t10(10);
    test(t10.TableroImportanciaRelativa().GetDimension() == 10, "Tablero 10x10 conserva dimension");
}

int main(int argc, char *argv[])
{
    // Procesar argumentos de línea de comandos
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--verbose") == 0)
        {
            verbose = true;
        }
    }

    if (verbose)
    {
        cout << "========================================" << endl;
        cout << "   TESTS TABLERO IMPORTANCIA RELATIVA" << endl;
        cout << "========================================" << endl;
    }

    test_Constructor();
    test_GetDimension_y_Elemento();
    test_ImportanciaRelativa_ejemplo_enunciado();
    test_ImportanciaRelativa_bordes_cero();
    test_ImportanciaRelativa_tablero_uniforme();
    test_ImportanciaRelativa_valor_maximo();
    test_ImportanciaRelativa_tablero_minimo();
    test_ImportanciaRelativa_dimension_conservada();

    cout << "\n========================================" << endl;
    cout << "   RESUMEN" << endl;
    cout << "========================================" << endl;
    cout << "Tests pasados: " << tests_pasados << endl;
    cout << "Tests fallidos: " << tests_fallidos << endl;

    if (tests_fallidos == 0)
    {
        cout << "\n✓ TODOS LOS TESTS PASARON CORRECTAMENTE\n"
             << endl;
    }
    else
    {
        cout << "\n✗ HAY TESTS QUE FALLARON\n"
             << endl;
    }

    return tests_fallidos;
}