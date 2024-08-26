#include <iostream>
using namespace std;

int gcd(int a, int b) {
    int r;
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    else {
        while (b != 0) {
            r = a % b;
            a = b;
            b = r;
        }
        return a;
    }
}

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    if (gcd(a,b) == 1) {
        cout << a << " and " << b << " are coprime." << endl;
    }else {
        cout << a << " and " << b << " are not coprime." << endl;
    }
    cout<<"---------------------------------------------------\n";
    cout<<"Name: Dipesh Shrestha \nRoll No: 08"<<endl;
    cout<<"---------------------------------------------------\n";
    return 0;
}
