#include <iostream>
#include <vector>
using namespace std;

// Construye una fila del patrón
vector<int> buildRow(int start, int length)
{
    vector<int> row;
    int num = start;

    // Ascendente
    for (int i = 0; i < length; i++)
    {
        row.push_back(num);
        num = (num + 1) % 10;
    }

    // Descendente espejo
    for (int i = length - 2; i >= 0; i--)
    {
        row.push_back(row[i]);
    }

    return row;
}

// Devuelve una cadena con 'count' espacios
string spaces(int count)
{
    return string(count, ' ');
}

int main()
{
    int n;
    cout << "Introduce n: ";
    cin >> n;

    int maxWidth = 2 * n - 1; // ancho de la última fila

    for (int i = 1; i <= n; i++)
    {
        vector<int> row = buildRow(i, i);
        int rowWidth = row.size();

        int leftSpaces = (maxWidth - rowWidth) / 2;
        cout << spaces(leftSpaces);

        for (int num : row)
        {
            cout << num;
        }
        cout << endl;
    }

    return 0;
}
