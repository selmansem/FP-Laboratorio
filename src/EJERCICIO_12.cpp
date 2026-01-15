/**
 * Extraer los digitos de un numero sin importar su longitud usando while
 */
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Ingrese un numero: ";
    cin >> n;

    cout << "Los digitos son: ";
    while (n > 0)
    {
        int dig = n % 10;
        cout << dig << " ";
        n /= 10;
    }
    cout << endl;

    return 0;
}