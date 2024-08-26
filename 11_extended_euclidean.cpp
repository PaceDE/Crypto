#include <iostream>
using namespace std;

int extendedEuclidean(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }

    int x1, y1;
    int gcd = extendedEuclidean(b % a, a, x1, y1);

    x = y1 - (b / a) * x1;
    y = x1;

    return gcd;
}

int main() {
    int a, b, x, y;
    cout << "Enter two integers: ";
    cin >> a >> b;

    int gcd = extendedEuclidean(a, b, x, y);

    cout << "GCD(" << a << ", " << b << ") = " << gcd << endl;
    cout << "Coefficients x and y are: " << x << " and " << y << endl;
    cout << a << "*" << "(" << x << ")"<< " + " << b << "*" << "(" << y << ")" << " = " << gcd << endl;
    cout<<"---------------------------------------------------\n";
    cout<<"Name: Dipesh Shrestha \nRoll No: 08"<<endl;
    cout<<"---------------------------------------------------\n";
    return 0;
}
