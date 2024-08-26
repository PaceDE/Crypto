#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

int modExp(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
          result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
  int n,a;
  cout << "Enter a number: ";
  cin >> n;
  cout << "Enter a random integer(<n-1): ";
  cin >> a;

  int q = n - 1;
  int k = 0;

  while (q % 2 == 0){
    k++;
    q /= 2;
  }

  if (modExp(a,q,n) == 1){
    cout << "Inconclusive";
    exit(0);
  }

  for (int j=0; j<= k-1; j++){
    if (modExp(a,pow(2,j)*q,n) == n-1){
        cout << "Inconclusive"<<endl;
        cout<<"---------------------------------------------------\n";
    cout<<"Name: Dipesh Shrestha \nRoll No: 08"<<endl;
    cout<<"---------------------------------------------------\n";
        exit(0);
    }
  }

  cout << "Composite"<<endl;
  cout<<"---------------------------------------------------\n";
    cout<<"Name: Dipesh Shrestha \nRoll No: 08"<<endl;
    cout<<"---------------------------------------------------\n";
  return 0;
}
