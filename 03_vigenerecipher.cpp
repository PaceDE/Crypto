#include <iostream>
#include <string>
using namespace std;

void encrypt(string message , string key) {
    cout << "Enter plaintext: ";
    cin >> message;
    cout << "Enter key: ";
    cin >> key;

    for (int i = 0; key.size() < message.size() ;i++){
        key.push_back(key[i]);
    }

    string ciphertext;
    for (int i=0; i< message.size();i++){
        char x = ((message[i] + key[i]) % 26) + 'a';
        ciphertext.push_back(x);
    }

    cout << endl << "Ciphertext: " << ciphertext << endl << endl;
}

int main() {
    string message;
    string key;
    encrypt(message, key);
     cout<<"---------------------------------------------------\n";
    cout<<"Name: Dipesh Shrestha \nRoll No: 08"<<endl;
    cout<<"---------------------------------------------------\n";
    return 0;
}

