#include <iostream>
#include <string>
#include "modAlphaCipher.h"

void check(string Text, int key) {
    try {
        string cipherText;
        string decryptedText;
        modCipher cipher(key, Text);
        cipherText = cipher.encryption(Text);
        decryptedText = cipher.transcript(cipherText, Text);
        cout << "Ключ = " << key << endl;
        cout << Text << endl;
        cout << cipherText << endl;
        cout << decryptedText << endl;
    } catch(const cipher_error & e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
}

int main() {
    try {
        check("jojieek", 5);
        check("", 5); 
        check("1323123142", 5);
        check("jojieek", 567573);
    } catch (const cipher_error& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
    return 0;
}
