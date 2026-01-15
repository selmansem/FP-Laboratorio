#include <iostream>
using namespace std;

int main() {
    int i, j, lon;

    cout << "Introduce la cantidad de filas a generar: ";
    cin >> lon;

    for (i = 0; i <= lon; i++) {
        for (j = 0; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}