#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// 0xSaad

string encryptVigenere(const string& plaintext, const string& key) {
    string ciphertext;
    int keyIndex = 0;


    for (int i = 0; i < plaintext.length(); i++) {
        unsigned char ch = plaintext[i];


        if (isalpha(ch)) {

            char letter = toupper(ch);
            char keyLetter =
                toupper(static_cast<unsigned char>(key[keyIndex % key.length()]));

            int shift = keyLetter - 'A';
            int value = (letter - 'A' + shift) % 26;


            ciphertext += static_cast<char>('A' + value);
            keyIndex++;
        }
        else {
            ciphertext += static_cast<char>(ch);
        }


    }

    return ciphertext;

}

string decryptVigenere(const string& ciphertext, const string& key) {
    string plaintext;
    int keyIndex = 0;

    for (int i = 0; i < ciphertext.length(); i++) {
        unsigned char ch = ciphertext[i];

        if (isalpha(ch)) {
            char letter = toupper(ch);
            char keyLetter =
                toupper(static_cast<unsigned char>(key[keyIndex % key.length()]));

            int shift = keyLetter - 'A';
            int value = (letter - 'A' - shift + 26) % 26;

            plaintext += static_cast<char>('A' + value);
            keyIndex++;
        }
        else {
            plaintext += static_cast<char>(ch);
        }
    }

    return plaintext;
}

int main() {
    string plaintext;
    string keyInput;
    string key;

    cout << "Enter plaintext: ";
    getline(cin, plaintext);

    cout << "Enter key: ";
    getline(cin, keyInput);

    for (int i = 0; i < keyInput.length(); i++) {
        unsigned char ch = keyInput[i];

        if (isalpha(ch)) {
            key += static_cast<char>(toupper(ch));
        }
    }

    if (key.empty()) {
        cout << "The key must contain at least one letter." << endl;
        return 1;


    }

    string ciphertext = encryptVigenere(plaintext, key);
    string decryptedText = decryptVigenere(ciphertext, key);

    cout << "Encrypted text: " << ciphertext << endl;

    cout << "Decrypted text: " << decryptedText << endl;

    return 0;



}