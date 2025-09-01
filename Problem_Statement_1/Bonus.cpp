#include <bits/stdc++.h>
using namespace std;

// ---------------- Base64 ----------------
static const string base64_chars =
             "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
             "abcdefghijklmnopqrstuvwxyz"
             "0123456789+/";

string base64_encode(const string &in) {
    string out;
    int val=0, valb=-6;
    for (unsigned char c : in) {
        val = (val<<8) + c;
        valb += 8;
        while (valb>=0) {
            out.push_back(base64_chars[(val>>valb)&0x3F]);
            valb-=6;
        }
    }
    if (valb>-6) out.push_back(base64_chars[((val<<8)>>(valb+8))&0x3F]);
    while (out.size()%4) out.push_back('=');
    return out;
}

string base64_decode(const string &in) {
    vector<int> T(256,-1);
    for (int i=0; i<64; i++) T[base64_chars[i]] = i;
    string out;
    int val=0, valb=-8;
    for (unsigned char c : in) {
        if (T[c] == -1) break;
        val = (val<<6) + T[c];
        valb += 6;
        if (valb>=0) {
            out.push_back(char((val>>valb)&0xFF));
            valb-=8;
        }
    }
    return out;
}

// ---------------- Keyword Caesar ----------------
int shiftFromChar(char c) {
    return toupper(c) - 'A'; // e.g. A=0, B=1, ... Z=25
}

string keywordEncrypt(const string &plaintext, const string &keyword) {
    string result;
    int n = keyword.size();
    int j = 0;
    for (char c : plaintext) {
        if (isalpha(c)) {
            int shift = shiftFromChar(keyword[j % n]);
            char base = isupper(c) ? 'A' : 'a';
            char enc = ( (c - base + shift) % 26 ) + base;
            result.push_back(enc);
            j++;
        } else {
            result.push_back(c); // keep spaces/punctuations
        }
    }
    return result;
}

string keywordDecrypt(const string &ciphertext, const string &keyword) {
    string result;
    int n = keyword.size();
    int j = 0;
    for (char c : ciphertext) {
        if (isalpha(c)) {
            int shift = shiftFromChar(keyword[j % n]);
            char base = isupper(c) ? 'A' : 'a';
            char dec = ( (c - base - shift + 26) % 26 ) + base;
            result.push_back(dec);
            j++;
        } else {
            result.push_back(c);
        }
    }
    return result;
}

// ---------------- Main ----------------
int main() {
    string keyword = "SECRET";
    string plaintext = "HELLO WORLD";

    cout << "Keyword: " << keyword << "\n";
    cout << "Plaintext: " << plaintext << "\n";

    // Step 1: Encrypt with Keyword Caesar
    string shifted = keywordEncrypt(plaintext, keyword);
    cout << "Keyword Caesar Encrypted: " << shifted << "\n";

    // Step 2: Encode with Base64
    string finalCipher = base64_encode(shifted);
    cout << "Base64 Encoded Ciphertext: " << finalCipher << "\n";

    // ---------------- Decryption ----------------
    // Step 1: Base64 decode
    string decodedShifted = base64_decode(finalCipher);

    // Step 2: Keyword Caesar Decrypt
    string recovered = keywordDecrypt(decodedShifted, keyword);

    cout << "Decoded back from Base64: " << decodedShifted << "\n";
    cout << "Decrypted Plaintext: " << recovered << "\n";

    return 0;
}
