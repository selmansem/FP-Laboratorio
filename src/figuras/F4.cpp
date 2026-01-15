#include <iostream>
using namespace std;

int main() {
    int i, j, k, lon;

    cout << "Intruduzca el número de filas a generar: ";
    cin >> lon;

    for (i = 0; i <= lon; i++) {
        for (j = 0; j <= i; j++) {
            cout << " ";
        }
        for (k = 0; k <= lon-j; k++) {
            cout << "*";
        }
        cout << endl;
    }
}