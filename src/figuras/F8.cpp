#include <iostream>
using namespace std;

int i, j, k, l, m, lon;

int main() {
    do {
        cout << "Indica la altura de la piramide: ";
        cin >> lon;
    } while (lon%2 == 0); // Hasta que lon sea impar

    for (i = 1; i <= lon; i++) {
        // 1. Si la fila es impar, generar caracteres
        if (i%2 != 0) {
            // 2. longitud menos fila partido entre dos
            j = (lon - i) / 2;
            
        } else {
            cout << endl;
        }
        cout << i << endl;
    }
}