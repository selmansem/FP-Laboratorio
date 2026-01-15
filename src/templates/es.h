// es.hpp — "mini-lenguaje" en español para C++
// Uso: #include "es.hpp"
// Nota: pensado para prácticas/enseñanza. No es recomendable en producción.

#pragma once
#include <iostream>
#include <string>
#include <limits>

//
// === Entrada/Salida en “lenguaje natural” ===
//

struct Leer_t
{
    // Lectura genérica: ints, doubles, etc.
    template <typename T>
    Leer_t &operator>>(T &variable)
    {
        std::cin >> variable;
        return *this;
    }
    // Lectura de líneas completas (strings con espacios)
    Leer_t &operator>>(std::string &s)
    {
        // Consume espacios/nueva línea pendiente y luego lee toda la línea
        std::getline(std::cin >> std::ws, s);
        return *this;
    }
};
inline Leer_t Leer; // permite:  Leer >> nombre;

struct Escribir_t
{
    // Salida genérica
    template <typename T>
    Escribir_t &operator<<(const T &v)
    {
        std::cout << v;
        return *this;
    }
    // Soporta manipuladores (std::endl, std::flush, etc.)
    Escribir_t &operator<<(std::ostream &(*pf)(std::ostream &))
    {
        std::cout << pf;
        return *this;
    }
};
inline Escribir_t Escribir; // permite:  Escribir << "Hola" << endl;

// Alias práctico para std::endl
using std::endl;

//
// === Palabras clave y operadores “en español” (macros) ===
//  Ojo: los macros afectan a todo el archivo de traducción.
//  Úsalos con moderación y preferentemente en ejercicios/demos.
//

// Control de flujo
#define Si if
#define Sino else
#define Mientras while
#define Para for
#define Romper break
#define Continuar continue

// switch/case
#define Segun switch
#define Caso case
#define Defecto default

// do { ... } while(cond);
// Queda así en español:
//   Hacer {
//     ...
//   } Hasta(condicion);
#define Hacer do
#define Hasta(condicion) while (condicion)

// Booleanos y lógicos (opcional, pero útil en demos)
#define Verdadero true
#define Falso false
#define Y &&
#define O ||
#define No !

// Comparadores “literales” (opcionales). Úsalos sólo si no molestan la lectura.
#define EsIgual ==
#define DistintoDe !=
#define MenorQue <
#define MayorQue >
#define MenorOIgual <=
#define MayorOIgual >=

// Retorno
#define Retornar return

//
// === Utilidades ===
//

// Limpia la entrada si hubo error (útil tras lecturas fallidas)
inline void LimpiarEntrada()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}