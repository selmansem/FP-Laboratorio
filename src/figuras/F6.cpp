#include <iostream>
using namespace std;

int main() {
    int i, j, k, l, m, lon;

    do {
        cout << "Introduzca el numero de filas a generar (debe ser impar): ";
        cin >> lon;
    } while (lon%2 == 0); // Preguntar hasta que sea impar

    for (i = 1; i <= lon; i++) {
        if (i%2 != 0) {
            // 1. longitud menos fila partido entre dos
            // 2. pintar el resultado en espacios
            // 3. pintar los asteriscos, tantos como es el número de fila en la que está
            // 4. volver a pintar el resultado del paso 1 en espacios
            
            j = (lon - i) / 2;
            
            for (k = 1; k <= j; k++) {
                cout << " ";
            }
            for (l = 1; l <= i; l++) {
                cout << "*";
            }
            for (m = 1; m <= j; m++) {
                cout << " ";
            }
            cout << endl;
        } 

        cout << endl;
        i++;
    }
}