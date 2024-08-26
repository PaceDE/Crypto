#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

string encrypt(string text);
void createKeyMatrix(string key);
void findInMatrix(char letter, int &row, int &col);
string createPairs(string input);

char keyMatrix[5][5];

void output() {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j)
            cout << keyMatrix[i][j] << " ";
        cout << "\n";
    }
}

int main() {
    string input, key;
    cout << "Key: ";
    getline(cin, key);
    createKeyMatrix(key);
    output();

    cout << "Enter message to encrypt: ";
    getline(cin, input);
    input = createPairs(input);
    cout << "Prepared input: " << input << endl;
    cout << "Encrypted text: " << encrypt(input) << endl;
     cout<<"---------------------------------------------------\n";
    cout<<"Name: Dipesh Shrestha \nRoll No: 08"<<endl;
    cout<<"---------------------------------------------------\n";
    return 0;
}

int mod(int a, int b) {
    int r = a % b;
    return r < 0 ? r + b : r;
}

void replace(string &text, int pos, char from, char to) {
    if (text[pos] == from)   text[pos] = to;
    if (text[pos+1] == from) text[pos+1] = to;
}

void findInMatrix(char letter, int &row, int &col) {
    for (int r = 0; r < 5; ++r)
        for (int c = 0; c < 5; ++c)
            if (letter == keyMatrix[r][c]) {
                row = r; col = c;
                return;
            }
}

string encrypt(string text) {
    string output = "";
    int row1, col1, row2, col2;
    int size = text.length();
    for (int pos = 0; pos < size; pos += 2) {
        replace(text, pos, 'j', 'i');

        findInMatrix(text[pos], row1, col1);
        findInMatrix(text[pos+1], row2, col2);

        if (row1 == row2) {
            output += keyMatrix[row1][mod(col1+1, 5)];
            output += keyMatrix[row2][mod(col2+1, 5)];
        } else if (col1 == col2) {
            output += keyMatrix[mod(row1+1, 5)][col1];
            output += keyMatrix[mod(row2+1, 5)][col2];
        } else {
            output += keyMatrix[row1][col2];
            output += keyMatrix[row2][col1];
        }
    }
    return output;
}

bool found(char c, vector<char> used) {
    return find(used.begin(), used.end(), c) != used.end();
}

void createKeyMatrix(string key) {
    vector<char> used;
    used.push_back('j');
    int size = key.length();
    int count = 0;
    char fillLetter = 'a';

    for (int row = 0; row < 5; ++row)
        for (int col = 0; col < 5; ++col) {
            if (count < size) {
                char letter = key[count];
                if (!found(letter, used)) {
                    keyMatrix[row][col] = letter;
                    used.push_back(letter);
                } else {
                    --col;
                }
                ++count;
            } else {
                if (!found(fillLetter, used))
                    keyMatrix[row][col] = fillLetter;
                else {
                    --col;
                }
                ++fillLetter;
            }
        }
}

string createPairs(string input) {
    string newString = "";
    int size = input.length();

    for (int i = 0; i < size - 1; ++i) {
        if (!isspace(input[i])) {
            newString += input[i];
            if (input[i] == input[i + 1])
                newString += 'x';
        }
    }

    newString += input[size - 1];
    if ((newString.length() & 1) == 1)
        newString += 'x';
    return newString;
}


