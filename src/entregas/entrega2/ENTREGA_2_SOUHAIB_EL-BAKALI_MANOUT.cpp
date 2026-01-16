/**
 * @file ENTREGA_2_SOUHAIB_EL-BAKALI_MANOUT.cpp
 *
 * @brief Implementación de la práctica evaluable del curso 2025/2026 - Estructura 20
 *
 * @author Souhaib El Bakali Manout
 * Email: souhaibem@correo.ugr.es
 *
 * @date 2026-01-04
 */

#include <iostream>
#include <string>
#include "GeneradorAleatorioEnteros.h"

using namespace std;

/**
 * @class Pieza
 * @brief Representa una pieza geométrica con tamaño, carácter y tipo de figura.
 *
 * Cada pieza puede ser de tres tipos:
 * 
 * - Tipo 1: Paralelogramo inclinado
 * 
 * - Tipo 2: Rectángulo hueco con triángulo inferior
 * 
 * - Tipo 3: Reloj de arena (dos triángulos unidos por el vértice)
 */
class Pieza
{
private:
    int tamanio;   ///< Tamaño de la pieza (debe ser par y positivo)
    char caracter; ///< Carácter que dibuja la pieza (*, &, @, #, $)
    int tipo;      ///< Tipo de figura (1, 2 o 3)

public:
    /**
     * @brief Constructor por defecto.
     * Inicializa la pieza con tamaño 2, carácter '*' y tipo 1.
     */
    Pieza() : tamanio(2), caracter('*'), tipo(1) {}

    /**
     * @brief Constructor con parámetros.
     * @param tam Tamaño de la pieza (debe ser par y positivo)
     * @param car Carácter de la pieza (*, &, @, #, $)
     * @param t Tipo de figura (1, 2 o 3)
     * @note Si los parámetros no son válidos, se usan valores por defecto.
     */
    Pieza(int tam, char car, int t)
    {
        tamanio = (tam > 0 && tam % 2 == 0) ? tam : 2;
        caracter = (car == '*' || car == '&' || car == '@' || car == '#' || car == '$') ? car : '*';
        tipo = (t >= 1 && t <= 3) ? t : 1;
    }

    /**
     * @brief Obtiene el tamaño de la pieza.
     * @return Tamaño actual de la pieza.
     */
    int GetTamanio() { return tamanio; }

    /**
     * @brief Obtiene el carácter de la pieza.
     * @return Carácter que forma la pieza.
     */
    char GetCaracter() { return caracter; }

    /**
     * @brief Obtiene el tipo de figura.
     * @return Tipo de la pieza (1, 2 o 3).
     */
    int GetTipo() { return tipo; }

    /**
     * @brief Establece el tamaño de la pieza.
     * @param tam Nuevo tamaño (debe ser par y positivo).
     */
    void SetTamanio(int tam)
    {
        if (tam > 0 && tam % 2 == 0)
            tamanio = tam;
    }

    /**
     * @brief Establece el carácter de la pieza.
     * @param car Nuevo carácter (*, &, @, #, $).
     */
    void SetCaracter(char car)
    {
        if (car == '*' || car == '&' || car == '@' || car == '#' || car == '$')
            caracter = car;
    }

    /**
     * @brief Establece el tipo de figura.
     * @param t Nuevo tipo (1, 2 o 3).
     */
    void SetTipo(int t)
    {
        if (t >= 1 && t <= 3)
            tipo = t;
    }

    /**
     * @brief Genera la representación en texto de la pieza.
     * @return String con el dibujo de la pieza según su tipo.
     */
    string ToString()
    {
        string res = "";
        int mitad = tamanio / 2;
        int ancho = tamanio - 1;

        if (tipo == 1)
        {
            // Paralelogramo: parte superior crece en espacios, inferior decrece
            for (int f = 0; f < mitad; f++)
            {
                res += string(f, ' ') + string(mitad, caracter) + '\n';
            }
            for (int f = mitad - 1; f >= 0; f--)
            {
                res += string(f, ' ') + string(mitad, caracter) + '\n';
            }
        }
        else if (tipo == 2)
        {
            // Rectángulo hueco superior
            for (int f = 0; f < mitad; f++)
            {
                if (f == 0 || f == mitad - 1)
                    res += string(ancho, caracter) + '\n';
                else
                    res += caracter + string(ancho - 2, ' ') + caracter + '\n';
            }
            // Triángulo inferior (vértice arriba, base abajo)
            for (int f = 0; f < mitad - 1; f++)
            {
                res += string(mitad - 1 - f, ' ');
                if (f == 0)
                    res += caracter;
                else
                    res += caracter + string(2 * f - 1, ' ') + caracter;
                res += '\n';
            }
            res += string(ancho, caracter) + '\n';
        }
        else
        {
            // Reloj de arena: triángulo superior invertido + triángulo inferior
            res += string(ancho, caracter) + '\n';
            for (int f = 1; f < mitad; f++)
            {
                int esp_int = ancho - 2 - 2 * f;
                res += string(f, ' ') + caracter;
                if (esp_int > 0)
                    res += string(esp_int, ' ') + caracter;
                res += '\n';
            }
            for (int f = mitad - 1; f >= 1; f--)
            {
                int esp_int = ancho - 2 - 2 * f;
                res += string(f, ' ') + caracter;
                if (esp_int > 0)
                    res += string(esp_int, ' ') + caracter;
                res += '\n';
            }
            res += string(ancho, caracter) + '\n';
        }
        return res;
    }
};

/**
 * @class Estructura
 * @brief Representa una estructura compuesta por tres piezas.
 */
class Estructura
{
private:
    Pieza pieza1, pieza2, pieza3; ///< Las tres piezas de la estructura

public:
    /**
     * @brief Constructor por defecto.
     * Crea una estructura con tres piezas por defecto.
     */
    Estructura() {}

    /**
     * @brief Constructor con parámetros para las tres piezas.
     * @param t1 Tamaño de la pieza 1
     * @param c1 Carácter de la pieza 1
     * @param tipo1 Tipo de la pieza 1
     * @param t2 Tamaño de la pieza 2
     * @param c2 Carácter de la pieza 2
     * @param tipo2 Tipo de la pieza 2
     * @param t3 Tamaño de la pieza 3
     * @param c3 Carácter de la pieza 3
     * @param tipo3 Tipo de la pieza 3
     */
    Estructura(int t1, char c1, int tipo1, int t2, char c2, int tipo2, int t3, char c3, int tipo3)
        : pieza1(t1, c1, tipo1), pieza2(t2, c2, tipo2), pieza3(t3, c3, tipo3) {}

    /** @brief Obtiene la pieza 1. @return Copia de la pieza 1. */
    Pieza GetPieza1() { return pieza1; }

    /** @brief Obtiene la pieza 2. @return Copia de la pieza 2. */
    Pieza GetPieza2() { return pieza2; }

    /** @brief Obtiene la pieza 3. @return Copia de la pieza 3. */
    Pieza GetPieza3() { return pieza3; }

    /** @brief Establece la pieza 1. @param p Nueva pieza 1. */
    void SetPieza1(Pieza p) { pieza1 = p; }

    /** @brief Establece la pieza 2. @param p Nueva pieza 2. */
    void SetPieza2(Pieza p) { pieza2 = p; }

    /** @brief Establece la pieza 3. @param p Nueva pieza 3. */
    void SetPieza3(Pieza p) { pieza3 = p; }

    /**
     * @brief Obtiene el tamaño mínimo entre las tres piezas.
     * @return El menor tamaño de las tres piezas.
     */
    int GetTamanioMinimo()
    {
        int min = pieza1.GetTamanio();
        if (pieza2.GetTamanio() < min)
            min = pieza2.GetTamanio();
        if (pieza3.GetTamanio() < min)
            min = pieza3.GetTamanio();
        return min;
    }

    /**
     * @brief Comprueba si las tres piezas tienen caracteres distintos.
     * @return true si los tres caracteres son diferentes, false en caso contrario.
     */
    bool TieneCaracteresDiferentes()
    {
        char c1 = pieza1.GetCaracter(), c2 = pieza2.GetCaracter(), c3 = pieza3.GetCaracter();
        return (c1 != c2 && c1 != c3 && c2 != c3);
    }

    /**
     * @brief Genera la representación en texto de la estructura completa.
     * @return String con las tres piezas dibujadas y etiquetadas.
     */
    string ToString()
    {
        return "- Pieza 1 -\n" + pieza1.ToString() +
               "\n- Pieza 2 -\n" + pieza2.ToString() +
               "\n- Pieza 3 -\n" + pieza3.ToString();
    }
};

/**
 * @brief Programa principal.
 *
 * Ejecuta tres tareas:
 * 
 * 1. Muestra la estructura asignada al alumno (Estructura 20)
 * 
 * 2. Genera y muestra 50 estructuras aleatorias
 * 
 * 3. Localiza la estructura con caracteres diferentes y pieza más pequeña
 *
 * @return 0 si la ejecución es correcta.
 */
int main()
{
    const char CARACTERES[] = {'*', '&', '@', '#', '$'};

    // PARTE 1: Genera la estructura asignada (Estructura 20)
    cout << "=== 1: Estructura asignada ===" << endl;
    cout << "Estructura 20:\n" << endl;

    Estructura mi_estructura(10, '*', 1, 10, '*', 2, 10, '*', 3);
    cout << mi_estructura.ToString() << endl;

    // PARTE 2: Genera 50 estructuras aleatorias
    cout << "=== 2: 50 Estructuras aleatorias ===" << endl;

    GeneradorAleatorioEnteros gen_tam(5, 15);
    GeneradorAleatorioEnteros gen_car(0, 4);
    GeneradorAleatorioEnteros gen_tipo(1, 3);

    bool encontrada = false;
    int tam_min_global = 31, indice_encontrada = -1;
    Estructura estructura_buscada;

    for (int i = 1; i <= 50; i++)
    {
        // Generar tamaños pares entre 5 y 15 (Línea 288) y multiplicando por 2.
        // Cualquier número entero multiplicado por 2 es par.
        // Al multiplicar por 2, los tamaños siempre estarán entre 10 y 30.
        int t1 = gen_tam.Siguiente() * 2;
        int t2 = gen_tam.Siguiente() * 2;
        int t3 = gen_tam.Siguiente() * 2;

        char c1 = CARACTERES[gen_car.Siguiente()];
        char c2 = CARACTERES[gen_car.Siguiente()];
        char c3 = CARACTERES[gen_car.Siguiente()];

        int tipo1 = gen_tipo.Siguiente();
        int tipo2 = gen_tipo.Siguiente();
        int tipo3 = gen_tipo.Siguiente();

        Estructura est(t1, c1, tipo1, t2, c2, tipo2, t3, c3, tipo3);

        cout << "\n--- Estructura " << i << " ---" << endl;
        cout << est.ToString() << endl;

        // Actualizar la estructura buscada si cumple las condiciones
        if (est.TieneCaracteresDiferentes() && est.GetTamanioMinimo() < tam_min_global)
        {
            tam_min_global = est.GetTamanioMinimo();
            estructura_buscada = est;
            encontrada = true;
            indice_encontrada = i;
        }
    }

    // PARTE 3: Estructura con caracteres diferentes y pieza mínima
    cout << "\n=== 3: Estructura con caracteres diferentes y pieza mínima ===" << endl;

    if (encontrada)
    {
        cout << "Estructura " << indice_encontrada << " (tamaño mínimo: " << tam_min_global << ")\n" << endl;
        cout << estructura_buscada.ToString() << endl;
    }
    else
    {
        cout << "AVISO: No se encontró ninguna estructura con tres caracteres diferentes." << endl;
    }

    return 0;
}