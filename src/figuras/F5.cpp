#include <iostream>
using namespace std;

int main() {
    int i, j, lon;

    cout << "Introduzca la altura de la figura: ";
    cin >> lon;

    for (i = 0; i < lon; i++) {
        for (j = 0; j < lon; j++) {
            if (i == 0 || i == lon-1 || j == 0 || j == lon-1) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}