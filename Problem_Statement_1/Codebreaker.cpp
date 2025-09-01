#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>
#include <utility> // for std::pair

using namespace std;

// Expected English letter frequencies (A–Z)
const vector<double> ENGLISH_FREQ = {
    8.167, 1.492, 2.782, 4.253, 12.702,
    2.228, 2.015, 6.094, 6.966, 0.153,
    0.772, 4.025, 2.406, 6.749, 7.507,
    1.929, 0.095, 5.987, 6.327, 9.056,
    2.758, 0.978, 2.360, 0.150, 1.974,
    0.074
};

// Caesar shift decryption
string caesarShift(const string &text, int shift) {
    string result = text;
    for (size_t i = 0; i < result.size(); i++) {
        char c = result[i];
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            result[i] = char((c - base - shift + 26) % 26 + base);
        }
    }
    return result;
}

// Compute score based on letter frequency
double scoreText(const string &text) {
    vector<int> counts(26, 0);
    int total = 0;

    for (char c : text) {
        if (isalpha(c)) {
            counts[toupper(c) - 'A']++;
            total++;
        }
    }

    if (total == 0) return 1e9; // invalid

    double score = 0.0;
    for (int i = 0; i < 26; i++) {
        double freq = (counts[i] * 100.0) / total;
        score += fabs(freq - ENGLISH_FREQ[i]);
    }
    return score;
}

// Smart breaker: tries all shifts and picks the best
pair<int, string> smartBreak(const string &cipher) {
    double bestScore = 1e9;
    int bestShift = -1;
    string bestPlain;

    for (int shift = 1; shift < 26; shift++) {
        string candidate = caesarShift(cipher, shift);
        double sc = scoreText(candidate);
        if (sc < bestScore) {
            bestScore = sc;
            bestShift = shift;
            bestPlain = candidate;
        }
    }
    return make_pair(bestShift, bestPlain);
}

int main() {
    string ct;
    cout << "Enter ciphertext: ";
    getline(cin, ct);

    pair<int, string> result = smartBreak(ct);

    if (result.first == -1) {
        cout << "Could not decode!\n";
    } else {
        cout << "Best Shift: " << result.first << "\n";
        cout << "Plaintext: " << result.second << "\n";
    }
    return 0;
}
