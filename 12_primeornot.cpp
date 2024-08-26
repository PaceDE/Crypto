#include <iostream>
using namespace std;

int main() {
  int number, count=0;
  cout << "Enter a number: ";
  cin >> number;

  for (int i = 2; i <= number ; i++) {
    if (number % i == 0)
      count += 1;
  }

  if (count > 2){
    cout << number << " is not a prime number." << endl;
  }else {
    cout << number << " is a prime number." << endl;
  }
  cout<<"---------------------------------------------------\n";
    cout<<"Name: Dipesh Shrestha \nRoll No: 08"<<endl;
    cout<<"---------------------------------------------------\n";
  return 0;
}
