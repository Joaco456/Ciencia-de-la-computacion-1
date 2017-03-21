#include <iostream>

using namespace std;

int main()
{
    int x;
    int y;
    int z;
    cout << "Ingrese el valor de x:";
    cin >> x;
    cout << "Ingrese el valor de y:";
    cin >> y;

    z = x + y;
    cout <<"La suma de " << x << "+" << y <<  ": " << z << endl;
    cout << "El valor de la suma:";
    cin >> x;
    cin >> y;
    z = x - y;
    cout <<"La resta de " << x << "-" << y << ": " << z << endl;
    cout << "El valor de la resta:";
    cin >> x;
    cout << "El valor de la resta:";
    cin >> y;
    z = x * y;
    cout <<"La multiplicacion de " << x << "*" << y <<  ": " << z << endl;
    cout << "El valor de la multiplicacion:";
    cin >> x;
    cout << "El valor de la multiplicacion:";
    cin >> y;
    z = x / y;
    cout <<"La division de x/y es: " << x << "/" << y << ": " << z << endl;
    cout << "El valor de la division:";
    cin >> x;
    cout << "El valor de la division:";
    cin >> y;
    return 0;
}
