#include <iostream>
#include <string>

using namespace std;

int main() {
    string a = "5.13";
    cout << "String a as double: " << static_cast<double>(stof(a)) << endl;

    return 0;
}