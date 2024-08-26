#include <iostream>

#include <string>
using namespace std;

int main() {
    string msg,encmsg;
    int key;
    cout << "Enter the message: ";
    getline(cin, msg);
    cout << "Enter key: ";
    cin >> key;

    for (int i=0; i<msg.size(); i++){
        if (msg[i] >= 'a' && msg[i] <= 'z'){
            encmsg += (msg[i] - 'a' + key) % 26 + 'a';
        }else if (msg[i] >= 'A' && msg[i] <= 'Z'){
            encmsg += (msg[i] - 'A' + key) % 26 + 'A';
        }
    }
    cout << "Encrypted message: " << encmsg << endl;
    cout<<"\n---------------------------------------------------\n";
    cout<<"Name: Dipesh Shrestha \nRoll No: 08"<<endl;
    cout<<"\n---------------------------------------------------\n";
    return 0;

}
