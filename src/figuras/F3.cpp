#include <iostream>
using namespace std;

int main() {
    int i, j, k, lon;

    cout << "Introduzca el numero de filas a generar: ";
    cin >> lon;

    for (i = 0; i <= lon; i++) {
        for (j = 0; j <= lon-i; j++) {
            cout << " ";
        }
        for (k = 0; k <= i; k++) {
            cout << "*";
        }
        cout << endl;
    }
}