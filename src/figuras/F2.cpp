#include <iostream>
using namespace std;

int main() {
    int i, j, lon;

    cout << "Introduzca el numero de filas a generar: ";
    cin >> lon;

    for (i = 0; i <= lon; i++) {
        for (j = 0; j <= lon-i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}