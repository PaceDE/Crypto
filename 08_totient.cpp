#include <iostream>
using namespace std;

int phi(int n)
{
    float result = n;
    for(int p = 2; p * p <= n; ++p)
    {
        if (n % p == 0)
        {
            while (n % p == 0)
                n /= p;
            result *= (1.0 - (1.0 / (float)p));
        }
    }
    if (n > 1)
        result -= result / n;
    return (int)result;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Phi" << "(" << n << ")" << " = " << phi(n) <<endl;
    cout<<"---------------------------------------------------\n";
    cout<<"Name: Dipesh Shrestha \nRoll No: 08"<<endl;
    cout<<"---------------------------------------------------\n";
    return 0;
}

