/**
 * @file ENTREGA_1-1_TESTS_SOUHAIB_EL-BAKALI_MANOUT.cpp
 *
 * @brief Tests para las funciones del proceso de Kaprekar.
 *
 * @author Souhaib El Bakali Manout
 * Email: souhaibem@correo.ugr.es
 *
 * @date 2026-01-03
 */

#include <iostream>
#include <string>
#include <cassert>
#include <cstring>

using namespace std;

// Variable global para modo verbose
bool verbose = false;

// ============== FUNCIONES A TESTEAR ==============

string ToStringInt(int entero, int num_casillas)
{
    string resultado = to_string(entero);
    while (resultado.length() < num_casillas)
    {
        resultado = "0" + resultado;
    }
    return resultado;
}

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

string Invertir(const string &cadena)
{
    // string invertida = "";
    // for (int i = cadena.length() - 1; i >= 0; i--)
    // {
    //     invertida += cadena[i];
    // }
    // return invertida;

    return string(cadena.rbegin(), cadena.rend());
}

string Ordenar(string cadena)
{
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

int IteracionKaprekar(int numero)
{
    string num_str = ToStringInt(numero, 4);
    string menor = Ordenar(num_str);
    string mayor = Invertir(menor);
    return stoi(mayor) - stoi(menor);
}

bool SePuedeAplicarKaprekar(int numero)
{
    string num_str = ToStringInt(numero, 4);
    char primer_digito = num_str[0];
    for (size_t i = 1; i < num_str.length(); i++)
    {
        if (num_str[i] != primer_digito)
        {
            return true;
        }
    }
    return false;
}

int ContarIteracionesKaprekar(int numero)
{
    const int CONSTANTE_KAPREKAR = 6174;
    int actual = numero;
    int iteraciones = 0;

    while (actual != CONSTANTE_KAPREKAR)
    {
        actual = IteracionKaprekar(actual);
        iteraciones++;
    }
    return iteraciones;
}

// ============== TESTS ==============

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

void test_ToStringInt()
{
    if (verbose) cout << "\n== Tests ToStringInt ==" << endl;

    test(ToStringInt(42, 5) == "00042", "ToStringInt(42, 5) == \"00042\"");
    test(ToStringInt(123, 3) == "123", "ToStringInt(123, 3) == \"123\"");
    test(ToStringInt(7, 4) == "0007", "ToStringInt(7, 4) == \"0007\"");
    test(ToStringInt(0, 4) == "0000", "ToStringInt(0, 4) == \"0000\"");
    test(ToStringInt(9999, 4) == "9999", "ToStringInt(9999, 4) == \"9999\"");
    test(ToStringInt(1, 1) == "1", "ToStringInt(1, 1) == \"1\"");
}

void test_ValoresDistintos()
{
    if (verbose) cout << "\n== Tests ValoresDistintos ==" << endl;

    test(ValoresDistintos("1234") == true, "ValoresDistintos(\"1234\") == true");
    test(ValoresDistintos("1123") == false, "ValoresDistintos(\"1123\") == false");
    test(ValoresDistintos("abcd") == true, "ValoresDistintos(\"abcd\") == true");
    test(ValoresDistintos("abca") == false, "ValoresDistintos(\"abca\") == false");
    test(ValoresDistintos("1111") == false, "ValoresDistintos(\"1111\") == false");
    test(ValoresDistintos("a") == true, "ValoresDistintos(\"a\") == true");
}

void test_Invertir()
{
    if (verbose) cout << "\n== Tests Invertir ==" << endl;

    test(Invertir("abcd") == "dcba", "Invertir(\"abcd\") == \"dcba\"");
    test(Invertir("1234") == "4321", "Invertir(\"1234\") == \"4321\"");
    test(Invertir("a") == "a", "Invertir(\"a\") == \"a\"");
    test(Invertir("") == "", "Invertir(\"\") == \"\"");
    test(Invertir("ab") == "ba", "Invertir(\"ab\") == \"ba\"");
}

void test_Ordenar()
{
    if (verbose) cout << "\n== Tests Ordenar ==" << endl;

    test(Ordenar("dcba") == "abcd", "Ordenar(\"dcba\") == \"abcd\"");
    test(Ordenar("3214") == "1234", "Ordenar(\"3214\") == \"1234\"");
    test(Ordenar("5432") == "2345", "Ordenar(\"5432\") == \"2345\"");
    test(Ordenar("1111") == "1111", "Ordenar(\"1111\") == \"1111\"");
    test(Ordenar("a") == "a", "Ordenar(\"a\") == \"a\"");
}

void test_IteracionKaprekar()
{
    if (verbose) cout << "\n== Tests IteracionKaprekar ==" << endl;

    // Ejemplos del enunciado
    test(IteracionKaprekar(3524) == 3087, "IteracionKaprekar(3524) == 3087 (5432-2345)");
    test(IteracionKaprekar(3087) == 8352, "IteracionKaprekar(3087) == 8352 (8730-0378)");
    test(IteracionKaprekar(8352) == 6174, "IteracionKaprekar(8352) == 6174 (8532-2358)");

    // Para el número 25 (0025)
    test(IteracionKaprekar(25) == 5175, "IteracionKaprekar(25) == 5175 (5200-0025)");

    // Para el número 1121
    test(IteracionKaprekar(1121) == 999, "IteracionKaprekar(1121) == 999 (2111-1112)");

    // La constante de Kaprekar es punto fijo
    test(IteracionKaprekar(6174) == 6174, "IteracionKaprekar(6174) == 6174 (punto fijo)");
}

void test_SePuedeAplicarKaprekar()
{
    if (verbose) cout << "\n== Tests SePuedeAplicarKaprekar ==" << endl;

    test(SePuedeAplicarKaprekar(1111) == false, "SePuedeAplicarKaprekar(1111) == false");
    test(SePuedeAplicarKaprekar(2222) == false, "SePuedeAplicarKaprekar(2222) == false");
    test(SePuedeAplicarKaprekar(1234) == true, "SePuedeAplicarKaprekar(1234) == true");
    test(SePuedeAplicarKaprekar(1112) == true, "SePuedeAplicarKaprekar(1112) == true");
    test(SePuedeAplicarKaprekar(25) == true, "SePuedeAplicarKaprekar(25) == true");
    test(SePuedeAplicarKaprekar(0) == false, "SePuedeAplicarKaprekar(0) == false (0000)");
}

void test_ProcesoCompleto()
{
    if (verbose) cout << "\n== Tests Proceso Completo (según tabla del enunciado) ==" << endl;

    test(ContarIteracionesKaprekar(3524) == 3, "3524 alcanza 6174 en 3 iteraciones");
    test(ContarIteracionesKaprekar(25) == 7, "25 alcanza 6174 en 7 iteraciones");
    test(ContarIteracionesKaprekar(1121) == 5, "1121 alcanza 6174 en 5 iteraciones");
    test(ContarIteracionesKaprekar(6174) == 0, "6174 alcanza 6174 en 0 iteraciones");
    test(ContarIteracionesKaprekar(9) == 4, "9 alcanza 6174 en 4 iteraciones");
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
        cout << "   TESTS PROCESO DE KAPREKAR" << endl;
        cout << "========================================" << endl;
    }

    test_ToStringInt();
    test_ValoresDistintos();
    test_Invertir();
    test_Ordenar();
    test_IteracionKaprekar();
    test_SePuedeAplicarKaprekar();
    test_ProcesoCompleto();

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