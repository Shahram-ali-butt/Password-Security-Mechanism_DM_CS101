#ifndef CRYPTO_FUNCTIONS_H
#define CRYPTO_FUNCTIONS_H

#include <string>
#include <vector>
using namespace std;

// CAESAR CIPHER
string caesarEncrypt(string text, int shift);
string caesarDecrypt(string text, int shift);

// VIGENERE CIPHER
string vigenereEncrypt(string text, string key);
string vigenereDecrypt(string text, string key);

// AFFINE CIPHER
string affineEncrypt(string text, int a, int shift);
string affineDecrypt(string text, int a, int shift);

int modInverse(int a, int m);

int gcd(int num1, int num2);

//  HASHING
string hashPassword(string password);

// PASSWORD MANAGEMENT
bool storePassword(string username, string password, string filename, string method);

bool verifyPassword(string username, string password, string filename, string method);

#endif 
