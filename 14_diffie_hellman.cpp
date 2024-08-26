#include <iostream>
#include <cmath>
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
  int p,g,a,b;

  cout << "Enter a Prime number(p): ";
  cin >> p;
  cout << "Enter a Base number(g): ";
  cin >> g;

  cout << "Enter Private Key(a): ";
  cin >> a;
  cout << "Enter Private Key(b): ";
  cin >> b;

  int A = modExp(g,a,p);
  int B = modExp(g,b,p);

  cout << "Public Key(A): " << A << endl;
  cout << "Public Key(B): " << B << endl;

  int S_A = modExp(B,a,p);
  int S_B= modExp(A,b,p);

  cout << "Shared Secret Key(S) of A: " << S_A << endl;
  cout << "Shared Secret Key(S) of B: " << S_B << endl;

  if (S_A == S_B) {
    cout << "Key Exchange is Successful."<<endl;
  }else{
    cout << "Key Exchange is failed."<<endl;
  }

  cout<<"---------------------------------------------------\n";
    cout<<"Name: Dipesh Shrestha \nRoll No: 08"<<endl;
    cout<<"---------------------------------------------------\n";
  return 0;
}
