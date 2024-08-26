#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string s;
    cout << "Enter the message: ";
    cin >> s;
    cout << "Enter key (number of rails): ";
    cin >> n;

    char a[n][s.length()];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < s.length(); j++) {
            a[i][j] = ' ';
        }
    }

    int row = 0;
    bool directionDown = false;

    for (int i = 0; i < s.length(); i++) {
        a[row][i] = s[i];

        if (row == 0 || row == n - 1) {
            directionDown = !directionDown;
        }

        row += directionDown ? 1 : -1;
    }

    cout << "Encrypted message: ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < s.length(); j++) {
            if (a[i][j] != ' ') {
                cout << a[i][j];
            }
        }
    }
    cout << endl;
     cout<<"---------------------------------------------------\n";
    cout<<"Name: Dipesh Shrestha \nRoll No: 08"<<endl;
    cout<<"---------------------------------------------------\n";

    return 0;
}
