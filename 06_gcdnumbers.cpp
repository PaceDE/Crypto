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
    cout << "Enter the two numbers: ";
    cin >> a >> b;
    cout << "GCD (" << a << ", " << b << ") : " << gcd(a, b) << endl;
     cout<<"---------------------------------------------------\n";
    cout<<"Name: Dipesh Shrestha \nRoll No: 08"<<endl;
    cout<<"---------------------------------------------------\n";
    return 0;
}

