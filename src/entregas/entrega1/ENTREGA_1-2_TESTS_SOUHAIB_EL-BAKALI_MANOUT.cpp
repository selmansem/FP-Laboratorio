/**
 * @file ENTREGA_1-2_TESTS_SOUHAIB_EL-BAKALI_MANOUT.cpp
 *
 * @brief Tests unitarios para la clase SecuenciaCaracteres.
 *
 * @author Souhaib El Bakali Manout
 * Email: souhaibem@correo.ugr.es
 *
 * @date 2026-01-03
 */

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// Variable global para modo verbose
bool verbose = false;

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

            ExpandirDesdeCentro(i, i, inicio, longitud);
            if (longitud > mejor_longitud)
            {
                mejor_inicio = inicio;
                mejor_longitud = longitud;
            }

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

// ============== FUNCIONES AUXILIARES PARA TESTS ==============

SecuenciaCaracteres CrearSecuencia(const string &cadena)
{
    SecuenciaCaracteres sec;
    for (size_t i = 0; i < cadena.length(); i++)
    {
        sec.Aniade(cadena[i]);
    }
    return sec;
}

string SecuenciaAString(const SecuenciaCaracteres &sec)
{
    string resultado = "";
    for (int i = 0; i < sec.Utilizados(); i++)
    {
        resultado += sec.Elemento(i);
    }
    return resultado;
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

void test_Aniade_y_Utilizados()
{
    if (verbose) cout << "\n== Tests Aniade y Utilizados ==" << endl;

    SecuenciaCaracteres sec;
    test(sec.Utilizados() == 0, "Secuencia vacia tiene 0 utilizados");

    sec.Aniade('A');
    test(sec.Utilizados() == 1, "Despues de Aniade tiene 1 utilizado");

    sec.Aniade('B');
    sec.Aniade('C');
    test(sec.Utilizados() == 3, "Despues de 3 Aniade tiene 3 utilizados");
}

void test_Elemento()
{
    if (verbose) cout << "\n== Tests Elemento ==" << endl;

    SecuenciaCaracteres sec = CrearSecuencia("ABC");
    test(sec.Elemento(0) == 'A', "Elemento(0) de \"ABC\" es 'A'");
    test(sec.Elemento(1) == 'B', "Elemento(1) de \"ABC\" es 'B'");
    test(sec.Elemento(2) == 'C', "Elemento(2) de \"ABC\" es 'C'");
}

void test_EsPalindromo()
{
    if (verbose) cout << "\n== Tests EsPalindromo ==" << endl;

    SecuenciaCaracteres sec1 = CrearSecuencia("ABA");
    test(sec1.EsPalindromo() == true, "\"ABA\" es palindromo");

    SecuenciaCaracteres sec2 = CrearSecuencia("ABBA");
    test(sec2.EsPalindromo() == true, "\"ABBA\" es palindromo");

    SecuenciaCaracteres sec3 = CrearSecuencia("ABC");
    test(sec3.EsPalindromo() == false, "\"ABC\" no es palindromo");

    SecuenciaCaracteres sec4 = CrearSecuencia("A");
    test(sec4.EsPalindromo() == true, "\"A\" es palindromo");

    SecuenciaCaracteres sec5;
    test(sec5.EsPalindromo() == true, "Secuencia vacia es palindromo");

    SecuenciaCaracteres sec6 = CrearSecuencia("ABCBA");
    test(sec6.EsPalindromo() == true, "\"ABCBA\" es palindromo");
}

void test_MayorPalindromo_ejemplos_enunciado()
{
    if (verbose) cout << "\n== Tests MayorPalindromo (ejemplos del enunciado) ==" << endl;

    // CABBADE -> ABBA
    SecuenciaCaracteres sec1 = CrearSecuencia("CABBADE");
    string resultado1 = SecuenciaAString(sec1.MayorPalindromo());
    test(resultado1 == "ABBA", "Mayor palindromo de \"CABBADE\" es \"ABBA\"");

    // ABCDEF -> cualquier caracter (longitud 1)
    SecuenciaCaracteres sec2 = CrearSecuencia("ABCDEF");
    SecuenciaCaracteres resultado2 = sec2.MayorPalindromo();
    test(resultado2.Utilizados() == 1, "Mayor palindromo de \"ABCDEF\" tiene longitud 1");

    // ABBA -> ABBA
    SecuenciaCaracteres sec3 = CrearSecuencia("ABBA");
    string resultado3 = SecuenciaAString(sec3.MayorPalindromo());
    test(resultado3 == "ABBA", "Mayor palindromo de \"ABBA\" es \"ABBA\"");

    // gAAtySHHSvvABCCBAfh -> ABCCBA
    SecuenciaCaracteres sec4 = CrearSecuencia("gAAtySHHSvvABCCBAfh");
    string resultado4 = SecuenciaAString(sec4.MayorPalindromo());
    test(resultado4 == "ABCCBA", "Mayor palindromo de \"gAAtySHHSvvABCCBAfh\" es \"ABCCBA\"");
}

void test_MayorPalindromo_casos_borde()
{
    if (verbose) cout << "\n== Tests MayorPalindromo (casos borde) ==" << endl;

    // Secuencia vacia
    SecuenciaCaracteres sec1;
    test(sec1.MayorPalindromo().Utilizados() == 0, "Mayor palindromo de secuencia vacia es vacio");

    // Un solo caracter
    SecuenciaCaracteres sec2 = CrearSecuencia("X");
    string resultado2 = SecuenciaAString(sec2.MayorPalindromo());
    test(resultado2 == "X", "Mayor palindromo de \"X\" es \"X\"");

    // Dos caracteres iguales
    SecuenciaCaracteres sec3 = CrearSecuencia("AA");
    string resultado3 = SecuenciaAString(sec3.MayorPalindromo());
    test(resultado3 == "AA", "Mayor palindromo de \"AA\" es \"AA\"");

    // Dos caracteres diferentes
    SecuenciaCaracteres sec4 = CrearSecuencia("AB");
    test(sec4.MayorPalindromo().Utilizados() == 1, "Mayor palindromo de \"AB\" tiene longitud 1");
}

void test_MayorPalindromo_impares()
{
    if (verbose) cout << "\n== Tests MayorPalindromo (longitud impar) ==" << endl;

    SecuenciaCaracteres sec1 = CrearSecuencia("ABA");
    string resultado1 = SecuenciaAString(sec1.MayorPalindromo());
    test(resultado1 == "ABA", "Mayor palindromo de \"ABA\" es \"ABA\"");

    SecuenciaCaracteres sec2 = CrearSecuencia("XABAY");
    string resultado2 = SecuenciaAString(sec2.MayorPalindromo());
    test(resultado2 == "ABA", "Mayor palindromo de \"XABAY\" es \"ABA\"");

    SecuenciaCaracteres sec3 = CrearSecuencia("ABACABA");
    string resultado3 = SecuenciaAString(sec3.MayorPalindromo());
    test(resultado3 == "ABACABA", "Mayor palindromo de \"ABACABA\" es \"ABACABA\"");
}

void test_MayorPalindromo_pares()
{
    if (verbose) cout << "\n== Tests MayorPalindromo (longitud par) ==" << endl;

    SecuenciaCaracteres sec1 = CrearSecuencia("ABBA");
    string resultado1 = SecuenciaAString(sec1.MayorPalindromo());
    test(resultado1 == "ABBA", "Mayor palindromo de \"ABBA\" es \"ABBA\"");

    SecuenciaCaracteres sec2 = CrearSecuencia("XABBAY");
    string resultado2 = SecuenciaAString(sec2.MayorPalindromo());
    test(resultado2 == "ABBA", "Mayor palindromo de \"XABBAY\" es \"ABBA\"");

    SecuenciaCaracteres sec3 = CrearSecuencia("AABBAA");
    string resultado3 = SecuenciaAString(sec3.MayorPalindromo());
    test(resultado3 == "AABBAA", "Mayor palindromo de \"AABBAA\" es \"AABBAA\"");
}

void test_MayorPalindromo_resultado_es_palindromo()
{
    if (verbose) cout << "\n== Tests MayorPalindromo (verificar que resultado es palindromo) ==" << endl;

    string casos[] = {"CABBADE", "ABCDEF", "XYZABCBAIJK", "AABBCCBBAA", "12321"};

    for (int i = 0; i < 5; i++)
    {
        SecuenciaCaracteres sec = CrearSecuencia(casos[i]);
        SecuenciaCaracteres resultado = sec.MayorPalindromo();
        test(resultado.EsPalindromo(), "Resultado de \"" + casos[i] + "\" es palindromo");
    }
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
        cout << "   TESTS MAYOR PALINDROMO" << endl;
        cout << "========================================" << endl;
    }

    test_Aniade_y_Utilizados();
    test_Elemento();
    test_EsPalindromo();
    test_MayorPalindromo_ejemplos_enunciado();
    test_MayorPalindromo_casos_borde();
    test_MayorPalindromo_impares();
    test_MayorPalindromo_pares();
    test_MayorPalindromo_resultado_es_palindromo();

    cout << "\n========================================" << endl;
    cout << "   RESUMEN" << endl;
    cout << "========================================" << endl;
    cout << "Tests pasados: " << tests_pasados << endl;
    cout << "Tests fallidos: " << tests_fallidos << endl;

    if (tests_fallidos == 0)
    {
        cout << "\n✓ TODOS LOS TESTS PASARON CORRECTAMENTE\n" << endl;
    }
    else
    {
        cout << "\n✗ HAY TESTS QUE FALLARON\n" << endl;
    }

    return tests_fallidos;
}