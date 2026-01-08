#include "crypto_functions.h"
#include <cmath>
#include <fstream>
#include <sstream>

using namespace std;

// CAESAR CIPHER

string caesarEncrypt(string text, int shift){
    char character, shiftedChar;
    int ascii;
    string result = "";
    shift = shift % 26;
    
    for (int i = 0; i < text.length(); i++){
        character = text[i];
        if(isupper(character)){
            ascii = character - int('A');
            ascii = (ascii + shift) % 26;
            shiftedChar = 'A' + ascii;
            result += shiftedChar;
        }else{
            ascii = character - int('a');
            ascii = (ascii + shift) % 26;
            shiftedChar = 'a' + ascii;
            result += shiftedChar;
        } 
    }
    return result;
}

string caesarDecrypt(string text, int shift) {
    char character, shiftedChar;
    int ascii;
    string result = "";
    shift = shift % 26;
    
    for(int i = 0; i < text.length(); i++){
        character = text[i];
        if(isupper(character)){
            ascii = character - int('A');
            ascii = (ascii - shift) % 26;
            shiftedChar = 'A' + ascii;
            result += shiftedChar;
        }else{
            ascii = character - int('a');
            ascii = (ascii - shift) % 26;
            shiftedChar = 'a' + ascii;
            result += shiftedChar;
        } 
    }
    return result;
}

// Resorce: https://youtu.be/0ZxqLybllNQ?si=DYgdY62lqGmirxEB

// VIGENERE CIPHER 

string vigenereEncrypt(string text, string key) {
    char character, shiftedChar;
    string result = "";
    int keyIndex = 0, shift, ascii, idx;
    
    for(int i = 0; i < text.length(); i++){
        character = text[i];
        idx = keyIndex % key.length();
        shift = toupper(key[idx]) - 'A';
        
        if(isupper(character)){
            ascii = character - int('A');
            ascii = (ascii + shift + 26) % 26;
            shiftedChar = 'A' + ascii;
            result += shiftedChar;
        }else{
            ascii = character - int('a');
            ascii = (ascii + shift + 26) % 26;
            shiftedChar = 'a' + ascii;
            result += shiftedChar;
        }

        keyIndex++;
    }

    return result;
}

string vigenereDecrypt(string text, string key) {
    char character, shiftedChar;
    string result = "";
    int keyIndex = 0, shift, ascii, idx;
    
    for(int i = 0; i < text.length(); i++){
        character = text[i];
        idx = keyIndex % key.length();
        shift = toupper(key[idx]) - 'A';
        
        if(isupper(character)){
            ascii = character - int('A');
            ascii = (ascii - shift + 26) % 26;
            shiftedChar = 'A' + ascii;
            result += shiftedChar;
        }else{
            ascii = character - int('a');
            ascii = (ascii - shift + 26) % 26;
            shiftedChar = 'a' + ascii;
            result += shiftedChar;
        }

        keyIndex++;
    }
    return result;
}

// AFFINE CIPHER IMPLEMENTATION

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1; // No inverse exists
}

string affineEncrypt(string text, int a, int shift) {
    string result = "";
    char character, shiftedChar;
    int ascii;
    
    // Check if 'a' and 26 are coprime
    if (gcd(a, 26) != 1) {
        return "'a' must be coprime with 26";
    }
    
    for (int i = 0; i < text.length(); i++){
        character = text[i];
        if(isupper(character)){
            ascii = character - int('A');
            ascii = (a * ascii + shift + 26) % 26;
            shiftedChar = 'A' + ascii;
            result += shiftedChar;
        }else{
            ascii = character - int('a');
            ascii = (a * ascii + shift + 26) % 26;
            shiftedChar = 'a' + ascii;
            result += shiftedChar;
        } 
    }

    return result;
}

string affineDecrypt(string text, int a, int shift) {
    string result = "";
    char character, shiftedChar;
    int ascii;

    int aInv = modInverse(a, 26);
    if (aInv == -1) {
        return "No modular inverse exists for 'a'";
    }

    for (int i = 0; i < text.length(); i++){
        character = text[i];
        if(isupper(character)){
            ascii = character - int('A');
            ascii = (aInv * (ascii - shift + 26)) % 26;
            shiftedChar = 'A' + ascii;
            result += shiftedChar;
        }else{
            ascii = character - int('a');
            ascii = (aInv * (ascii - shift + 26)) % 26;
            shiftedChar = 'a' + ascii;
            result += shiftedChar;
        } 
    }
    
    return result;
}

// HASHING

string hashPassword(string password){
    long long hash = 0;
    long long prime = 31;
    long long mod = 1000007;
    
    for (int i = 0; i < password.length(); i++) {
        hash = (hash * prime + (long long)password[i]) % mod;
    }
    
    return to_string(hash);
}


//  PASSWORD MANAGEMENT 

bool storePassword(string username, string password, 
                string filename, string method) {
    ofstream file(filename, ios::app);
    if (!file.is_open()) {
        return false;
    }
    
    string encryptedPassword;
    
    if (method == "caesar") {
        encryptedPassword = caesarEncrypt(password, 3);
    } else if (method == "vigenere") {
        encryptedPassword = vigenereEncrypt(password, "KEY");
    } else if (method == "affine") {
        encryptedPassword = affineEncrypt(password, 5, 8);
    } else if (method == "hash") {
        encryptedPassword = hashPassword(password);
    } else {
        encryptedPassword = password;
    }
    
    file << username << ":" << encryptedPassword << ":" << method << '\n';
    file.close();
    return true;
}

bool verifyPassword(string username, string password, string filename, string method) {
    ifstream file(filename);
    if (!file.is_open()){
        return false;
    }
    
    string line;
    while (getline(file, line)){
        stringstream ss(line);
        string storedUser, storedEncrypted, storedMethod;
        
        getline(ss, storedUser, ':');
        getline(ss, storedEncrypted, ':');
        getline(ss, storedMethod, ':');
        
        if (storedUser == username) {
            string decryptedPassword;
            
            if (storedMethod == "caesar"){
                decryptedPassword = caesarDecrypt(storedEncrypted, 3);
            } else if (storedMethod == "vigenere"){
                decryptedPassword = vigenereDecrypt(storedEncrypted, "KEY");
            } else if (storedMethod == "affine"){
                decryptedPassword = affineDecrypt(storedEncrypted, 5, 8);
            } else if (storedMethod == "hash"){
                file.close();
                return hashPassword(password) == storedEncrypted;
            } else {
                decryptedPassword = storedEncrypted;
            }
            
            file.close();
            return decryptedPassword == password;
        }
    }
    
    file.close();
    return false;
}


