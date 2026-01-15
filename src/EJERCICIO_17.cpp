/**
 * Dibuja una x con asteriscos de tamaño n.
 * El tamaño n debe ser un número impar mayor o igual a 3.
 */

#include <iostream>

using namespace std;

int main() {
    int n;

    cout << "Ingrese un número impar mayor o igual a 3: ";
    cin >> n;

    if (n < 3 || n % 2 == 0) {
        cout << "El número ingresado no es válido." << endl;
        return 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == i || j == n - i - 1) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
