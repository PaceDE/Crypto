#include <iostream>
using namespace std;

int multi(int x, int y, int m) {
  x = x % m;
  y = y % m;
  return ((x * y) % m == 1);
}

int main() {
  int a, b, m;
  cout << "Enter two numbers: ";
  cin >> a >> b;
  cout << "Enter the modulus: ";
  cin >> m;

  if (multi(a,b,m)){
    cout << b << " is the multiplicative inverse of " << a << " mod " << m << endl;
  }else {
    cout << b << " is not the multiplicative inverse of " << a << " mod " << m << endl;
  }
   cout<<"---------------------------------------------------\n";
    cout<<"Name: Dipesh Shrestha \nRoll No: 08"<<endl;
    cout<<"---------------------------------------------------\n";
  return 0;
}
