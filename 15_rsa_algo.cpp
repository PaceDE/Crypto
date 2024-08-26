#include <iostream>
#include <string>
using namespace std;

int gcd(int a, int b) {
    int r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int multi(int a, int m) {
    for (int i = 1; i < m; i++) {
        if ((a * i) % m == 1) {
            return i;
        }
    }
    return 0; // This should never happen if e and phi are coprime
}

int modexp(int base, int exp, int mod) {
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
    int p, q, e;
    cout << "Enter prime numbers p and q: ";
    cin >> p >> q;
    cout << "Enter a random integer: ";
    cin >> e;

    string character = "abcdefghijklmnopqrstuvwxyz";

    int n = p * q;
    int phi = (p - 1) * (q - 1);

    // Ensure e is coprime with phi(n)
    while (e < phi) {
        if (gcd(e, phi) == 1)
            break;
        else
            e++;
    }

    int d = multi(e, phi);
    if (d == 0) {
        cout << "Error: No multiplicative inverse found. Please try a different e." << endl;
        return 1;
    }

    cout << "Public Key: (" << e << ", " << n << ")\n";
    cout << "Private Key: (" << d << ", " << n << ")\n";

    // Encrypting the message
    string message;
    cout << "Enter message to encrypt: ";
    cin >> message;

    int encrypted[message.size()];
    for (int i = 0; i < message.size(); i++) {
        int j = character.find(tolower(message[i]));
        if (j == string::npos) {
            cout << "Error: Message contains invalid characters." << endl;
            return 1;
        }
        encrypted[i] = modexp(j + 1, e, n); // +1 to match 1-based index (a=1, b=2,...)
    }

    cout << "Encrypted message: { ";
    for (int i = 0; i < message.size(); i++) {
        cout << encrypted[i] << " ";
    }
    cout << "}" << endl;

    // Decryption process
    string decrypted = "";
    for (int i = 0; i < message.size(); i++) {
        int decryptedCharIndex = modexp(encrypted[i], d, n) - 1; // -1 to revert to 0-based index
        if (decryptedCharIndex >= 0 && decryptedCharIndex < character.size()) {
            decrypted += character[decryptedCharIndex];
        } else {
            cout << "Error: Decryption failed for character index " << decryptedCharIndex << endl;
            return 1;
        }
    }

    cout << "\nDecrypted message: " << decrypted << endl;

    cout<<"---------------------------------------------------\n";
    cout<<"Name: Dipesh Shrestha \nRoll No: 08"<<endl;
    cout<<"---------------------------------------------------\n";
    return 0;
}
