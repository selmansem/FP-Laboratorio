// -*- C++ -*-
/**
 * @file GeneradorAleatorioEnteros.h
 * @brief Esta es una clase básica para generar números pseudoaleatorios entre un mínimo y un máximo todos ellos con la misma probabilidad.
 * 
 * No se pretende que entienda el código de la implementación de los métodos,
 * pero sí debe saber cómo llamarlos y lo que hacen (saber "qué hace" pero no "cómo lo hace")
 *
 * @author Prof. JC. Cubero
 * Url: https://decsai.ugr.es/jccubero/FP/GeneradorAleatorio.cpp
 */

#ifndef GENERADOR_ALEATORIO_ENTEROS_H
#define GENERADOR_ALEATORIO_ENTEROS_H

#include <random>
#include <chrono>

using namespace std;
using namespace chrono;

class GeneradorAleatorioEnteros
{
private:
    int min, max;
    uniform_int_distribution<int> distribucion_uniforme;

public:
    GeneradorAleatorioEnteros() : GeneradorAleatorioEnteros(0, 1) {}

    GeneradorAleatorioEnteros(int minimo, int maximo)
    {
        min = minimo;
        max = maximo;
        distribucion_uniforme = uniform_int_distribution<int>(min, max);
    }

    int Siguiente()
    {
        static mt19937_64 generador_mersenne;
        static bool primera_vez = true;

        if (primera_vez)
        {
            time_point<steady_clock> ahora = steady_clock::now();
            duration<long long int, nano> intervalo = ahora.time_since_epoch();
            generador_mersenne.seed(intervalo.count());
            primera_vez = false;
        }
        return distribucion_uniforme(generador_mersenne);
    }

    int Min() { return min; }
    int Max() { return max; }
};

#endif