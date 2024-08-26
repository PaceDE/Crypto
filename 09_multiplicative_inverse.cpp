#include <iostream>
using namespace std;

int multiInv(int a, int m) {
  for (int i = 1; i < m; i++) {
        if ((a * i) % m == 1) {
            return i;
        }
    }
    return 0;
}

int main() {
    int a, m;
    cout << "Enter the number and the modulus: ";
    cin >> a >> m;
    int inverse = multiInv(a,m);
    if (inverse > 0) {
        cout << "The multiplicative inverse is: " << inverse << endl;
    } else {
        cout << "The multiplicative inverse doesn't exist." << endl;
    }
    cout<<"---------------------------------------------------\n";
    cout<<"Name: Dipesh Shrestha \nRoll No: 08"<<endl;
    cout<<"---------------------------------------------------\n";
    return 0;
}

