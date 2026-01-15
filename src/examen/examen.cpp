/**
 * FIGURA 20:
 *
 * *******************..............*.........
 * .*...............*..............*0*........
 * ..*.............*..............*123*.......
 * ...*...........*..............*45678*......
 * ....*.........*..............*9012345*.....
 * .....*.......*.......*......*678901234*....
 * ......*.....*.......***....*56789012345*...
 * .......*...*.......*****..*6789012345678*..
 * ........*.*.........***..*901234567890123*.
 * .........*...........*..*******************
 *
 */

#include <iostream>
using namespace std;

int main() {
    int i, L;

    // Solicita al usuario un valor para L, asegurándose de que sea mayor o igual a 1.
    do {
        cout << "Introduce una longitud L: ";
        cin >> L;
    } while (!L || L < 1);

    // Calcula el ancho total de la figura, el número de estrellas a la izquierda,
    // la posición de la columna vertical y un contador para los dígitos.
    int ancho = 4 * L + 3;
    int nEstrellasIzq = 2 * L - 1;
    int columnaVertical = ancho - L;
    long long digito = 0;

    // Inicializa una fila con espacios y coloca las estrellas iniciales a la izquierda.
    string fila(ancho, ' ');
    for (i = 0; i < nEstrellasIzq && i < ancho; ++i) {
        fila[i] = '*';
    }

    // Coloca una estrella en la posición de la columna vertical.
    if (columnaVertical >= 0 && columnaVertical < ancho) {
        fila[columnaVertical] = '*';
    }

    // Imprime la primera fila de la figura.
    cout << fila << '\n';

    // Calcula la altura de la pirámide y su posición inicial.
    int altoPiramide = max(1, L / 2);
    int inicioPiramide = L - altoPiramide - 1;
    int centroColumna = nEstrellasIzq + 2;

    // Genera las filas restantes de la figura.
    for (int filaNum = 2; filaNum <= L; ++filaNum) {
        int r = filaNum - 1;
        fila.assign(ancho, ' ');

        // Coloca una estrella en la posición izquierda de la fila.
        int colIzquierda = r;
        if (colIzquierda >= 0 && colIzquierda < ancho) {
            fila[colIzquierda] = '*';
        }

        // Coloca una estrella en la posición interior izquierda.
        int colInterior = nEstrellasIzq - 2 - (r - 1);
        if (colInterior >= 0 && colInterior < ancho) {
            fila[colInterior] = '*';
        }

        if (columnaVertical >= 0 && columnaVertical < ancho) {
            fila[columnaVertical] = '*';
        }

        // Dibuja la pirámide en el centro de la figura.
        if (r >= inicioPiramide && r < inicioPiramide + altoPiramide) {
            int idx = r - inicioPiramide;
            int pico = altoPiramide / 2;
            int indiceAnchura = (idx <= pico) ? idx : (2 * pico - idx);
            int anchura = 2 * indiceAnchura + 1;
            int izquierda = centroColumna - anchura / 2;
            if (izquierda < 0) {
                izquierda = 0;
            }
            if (izquierda + anchura > ancho) {
                izquierda = max(0, ancho - anchura);
            }
            for (int c = 0; c < anchura; ++c) {
                fila[izquierda + c] = '*';
            }
        }

        // Dibuja los bloques de números en las filas intermedias.
        if (filaNum >= 2 && filaNum <= L - 1) {
            int len = 2 * filaNum - 3;
            int inicioBloque = (ancho - L + 1) - filaNum;
            if (inicioBloque < 0) {
                inicioBloque = 0;
            }
            if (inicioBloque + len + 2 > ancho) {
                inicioBloque = max(0, ancho - (len + 2));
            }
            if (inicioBloque >= 0 && inicioBloque < ancho) {
                fila[inicioBloque] = '*';
            }
            for (int k = 0; k < len; ++k) {
                int pos = inicioBloque + 1 + k;
                if (pos >= 0 && pos < ancho) {
                    fila[pos] = char('0' + (digito % 10));
                    digito = (digito + 1) % 10;
                }
            }
            int estrellaDerecha = inicioBloque + 1 + len;
            if (estrellaDerecha >= 0 && estrellaDerecha < ancho) {
                fila[estrellaDerecha] = '*';
            }
        }

        // Dibuja la última fila con estrellas a la derecha.
        if (filaNum == L) {
            int inicioDerecha = ancho - nEstrellasIzq;
            if (inicioDerecha < 0) {
                inicioDerecha = 0;
            }
            fila[inicioDerecha - 3] = '*';
            for (int c = inicioDerecha; c < ancho; ++c) {
                fila[c] = '*';
            }
        }

        // Imprime la fila generada.
        cout << fila << '\n';
    }

    return 0;
}
