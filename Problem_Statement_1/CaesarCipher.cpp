#include <iostream> 
#include <string> //string is a class in the standard library
using namespace std; 

const int ALPHABET_SIZE = 26; //Prevents accidental modification of values.

// Shift a single character
char shiftChar(char ch, int shift) {
    if (isupper(ch)) {
        return char(( (ch - 'A' + shift) % ALPHABET_SIZE + ALPHABET_SIZE ) % ALPHABET_SIZE + 'A'); //double modulo to handle negative shifts
    }
    else if (islower(ch)) {
        return char(( (ch - 'a' + shift) % ALPHABET_SIZE + ALPHABET_SIZE ) % ALPHABET_SIZE + 'a');
    }
    else {
        return ch; // leave non-letters unchanged
    }
}

// Encode: shift forward
string encode(const string& text, int shift) {
    string result;
    for (char ch : text) {
        result += shiftChar(ch, shift);
    }
    return result;
}

// Decode: shift backward
string decode(const string& text, int shift) {
    return encode(text, -shift);
}

int main() {
    string message;
    int shift;
    char mode;

    cout << "Enter message: ";
    getline(cin, message);

    cout << "Enter shift value: ";
    cin >> shift;

    cout << "Enter mode (e for encode, d for decode): ";
    cin >> mode;

    if (mode == 'e') {
        cout << "Encoded: " << encode(message, shift) << endl;
    }
    else if (mode == 'd') {
        cout << "Decoded: " << decode(message, shift) << endl;
    }
    else {
        cout << "Invalid mode!" << endl;
    }

    return 0;
}
