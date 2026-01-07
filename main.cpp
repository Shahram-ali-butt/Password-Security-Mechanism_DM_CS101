#include <iostream>
#include <windows.h>
#include "crypto_functions.h"

using namespace std;

const int headercolor = 11;
const int Menucolor = 6;
const int textcolor = 14;

// Menus
void printHeader();
void mainMenu();
void joinMenu();
void explanationMenu();

// Demonstrations
void demonstrateCaesar();
void demonstrateVigenere();
void demonstrateAffine();
void demonstrateHash();

// Explanations
void caesarExplanation();
void vigenereExplanation();
void affineExplanation();
void hashingExplanation();

// Utility Function
void stopExecution();
void generateColors(int color);


int main(){
    char choice;
    string password, username, method;
    
    while(true){
        system("cls");
        printHeader();
        mainMenu();
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();
        
        if(choice == '1'){
            cout << "Enter password to encrypt: ";
            getline(cin, password);
            int shift;
            cout << "Enter shift value (1-25): ";
            cin >> shift;
            string encrypted = caesarEncrypt(password, shift);
            cout << "Encrypted password: " << encrypted << endl;
            stopExecution();
            continue;
        }
        
        else if(choice == '2') {
            cout << "Enter password to encrypt: ";
            getline(cin, password);
            string key;
            cout << "Enter encryption key: ";
            getline(cin, key);
            string encrypted = vigenereEncrypt(password, key);
            cout << "Encrypted password: " << encrypted << endl;
            stopExecution();
            continue;
        }
        
        else if(choice == '3'){
            cout << "Enter password to encrypt: ";
            getline(cin, password);
            int a, b;
            cout << "Enter key 'a' (must be coprime with 26): ";
            cin >> a;
            cout << "Enter key 'b': ";
            cin >> b;
            string encrypted = affineEncrypt(password, a, b);
            cout << "Encrypted password: " << encrypted << endl;
            stopExecution();
            continue;
        }
        
        else if(choice == '4'){
            cout << "Enter password to hash: ";
            getline(cin, password);
            string hashed = hashPassword(password);
            cout << "Hashed password: " << hashed << endl;
            stopExecution();
            continue;
        }

        else if(choice == '5'){
            joinMenu();
            stopExecution();
            continue;
        }
            
        else if(choice == '6'){
            demonstrateCaesar();
            demonstrateVigenere();
            demonstrateAffine();
            demonstrateHash();
            stopExecution();
            continue;
        }

        else if(choice == '7'){
            explanationMenu();
            continue;
        }
        
        else if(choice == '0'){
            cout << "Exiting program. Goodbye!" << endl;
            break;
        }
        
        else{
            cout << "Invalid choice! Please try again." << endl;
        }
    }
    
    stopExecution();
    return 0;
}


//  Menus
void printHeader(){
    generateColors(headercolor);
    SetConsoleOutputCP(CP_UTF8);
    cout << "==================================================" << endl;
    cout << "     ███████████   █████████  ██████   ██████ " << endl;
    cout << "    ░░███░░░░░███ ███░░░░░███░░██████ ██████  " << endl;
    cout << "     ░███    ░███░███    ░░░  ░███░█████░███  " << endl;
    cout << "     ░██████████ ░░█████████  ░███░░███ ░███  " << endl;
    cout << "     ░███░░░░░░   ░░░░░░░░███ ░███ ░░░  ░███  " << endl;
    cout << "     ░███         ███    ░███ ░███      ░███  " << endl;
    cout << "     █████       ░░█████████  █████     █████ " << endl;
    cout << "    ░░░░░         ░░░░░░░░░  ░░░░░     ░░░░░  " << endl << endl;                        
    cout << "   PASSWORD SECURITY MECHANISM - CS101 Project    " << endl;
    cout << "             Group 3: Shahram Ali Butt            " << endl;
    cout << "==================================================" << endl;
}

void mainMenu(){
    generateColors(Menucolor);
    cout << "\n=========== PASSWORD ENCRYPTION SYSTEM ===========" << endl;
    cout << "1. Encrypt password (Caesar)" << endl;
    cout << "2. Encrypt password (Vigenere)" << endl;
    cout << "3. Encrypt password (Affine)" << endl;
    cout << "4. Hash password" << endl;
    cout << "5. Join two ciphers" << endl;
    cout << "6. Run all demonstrations" << endl;
    cout << "7. Get Explanations" << endl;
    cout << "0. Exit" << endl;
    cout << "==================================================" << endl;
    generateColors(textcolor);
}

void joinMenu(){
    string choice, password;
    system("cls");
    printHeader();

    generateColors(Menucolor);
    cout << "\n=============== Joining Two Ciphers ===============" << endl;
    cout << "1. Caesar Cipher" << endl;
    cout << "2. Vigenere Cipher" << endl;
    cout << "3. Affine Cipher" << endl;
    cout << "0. Exit" << endl;

    while(true){
        generateColors(textcolor);
        cout << endl << "Enter your combination (12, 13 or 23): ";
        cin >> choice;
        cin.ignore();
    
        if(choice == "12"){
            cout << "Enter password to encrypt: ";
            getline(cin, password);
            int shift;
            cout << "Enter shift value (1-25): ";
            cin >> shift;
            string encrypted = caesarEncrypt(password, shift);
            cout << "Caesar Encrypted password: " << encrypted << endl;

            string key;
            cout << "Enter encryption key for Vigenere cipher: ";
            getline(cin, key);
            string secondEncrypted = vigenereEncrypt(encrypted, key);
            cout << "Final Encrypted password: " << secondEncrypted << endl;

            stopExecution();
            continue;
            
        }
        else if(choice == "13"){
            cout << "Enter password to encrypt: ";
            getline(cin, password);
            int shift;
            cout << "Enter shift value (1-25): ";
            cin >> shift;
            string encrypted = caesarEncrypt(password, shift);
            cout << "Caesar Encrypted password: " << encrypted << endl;

            int a, b;
            cout << "Enter key 'a' (must be coprime with 26): ";
            cin >> a;
            cout << "Enter key 'b': ";
            cin >> b;
            string secondEncrypted = affineEncrypt(encrypted, a, b);
            cout << "Final Encrypted password: " << secondEncrypted << endl;

            stopExecution();
            continue;
        }
        else if(choice == "23"){
            cout << "Enter password to encrypt: ";
            getline(cin, password);
            string key;
            cout << "Enter encryption key for Vigenere cipher: ";
            getline(cin, key);
            string encrypted = vigenereEncrypt(password, key);
            cout << "Vigenere Encrypted password: " << encrypted << endl;

            int a, b;
            cout << "Enter key 'a' (must be coprime with 26): ";
            cin >> a;
            cout << "Enter key 'b': ";
            cin >> b;
            string secondEncrypted = affineEncrypt(encrypted, a, b);
            cout << "Final Encrypted password: " << secondEncrypted << endl;

            stopExecution();
            continue;
        }
        else if(choice == "0"){
            break;
        }else{
            cout << "Combination not available" << endl;
        }
    }

}

void explanationMenu(){
    char choice;
    
    generateColors(Menucolor);
    cout << "\n================== Explanations ==================" << endl;
    cout << "1. Caesar Cipher" << endl;
    cout << "2. Vigenere Cipher" << endl;
    cout << "3. Affine Cipher" << endl;
    cout << "4. Password Hashing" << endl;
    cout << "0. Exit" << endl;

    while(true){
        generateColors(textcolor);
        cout << endl << "Enter your Choice: ";
        cin >> choice;

        if(choice == '1'){
            caesarExplanation();
            break;
        }
        else if(choice == '2'){
            vigenereExplanation();
            break;
        }
        else if(choice == '3'){
            affineExplanation();
            break;
        }
        else if(choice == '4'){
            hashingExplanation();
            break;
        }
        else if(choice == '0'){
            break;
        }
        else{
            cout << "Invalid choice! Please try again." << endl;
            continue;
        }
        
    }
}


// Demonstrations
void demonstrateCaesar(){
    cout << "\n============ CAESAR CIPHER DEMONSTRATION ============" << endl;
    string text = "HelloWorld";
    int shift = 3;
    
    cout << "Original Text: " << text << endl;
    string encrypted = caesarEncrypt(text, shift);
    cout << "Encrypted (shift=" << shift << "): " << encrypted << endl;
    string decrypted = caesarDecrypt(encrypted, shift);
    cout << "Decrypted: " << decrypted << endl;
}

void demonstrateVigenere(){
    cout << "\n============ VIGENERE CIPHER DEMONSTRATION ============" << endl;
    string text = "HelloWorld";
    string key = "KEY";
    
    cout << "Original Text: " << text << endl;
    cout << "Key: " << key << endl;
    string encrypted = vigenereEncrypt(text, key);
    cout << "Encrypted: " << encrypted << endl;
    string decrypted = vigenereDecrypt(encrypted, key);
    cout << "Decrypted: " << decrypted << endl;
}

void demonstrateAffine(){
    cout << "\n============ AFFINE CIPHER DEMONSTRATION ============" << endl;
    string text = "HelloWorld";
    int a = 5, b = 8;
    
    cout << "Original Text: " << text << endl;
    cout << "Keys: a=" << a << ", b=" << b << endl;
    string encrypted = affineEncrypt(text, a, b);
    cout << "Encrypted: " << encrypted << endl;
    string decrypted = affineDecrypt(encrypted, a, b);
    cout << "Decrypted: " << decrypted << endl;
}

void demonstrateHash(){
    cout << "\n============ HASH FUNCTION DEMONSTRATION ============" << endl;
    
    string password1 = "MyPassword123";
    string password2 = "MyPassword123";
    string password3 = "DifferentPass";
    
    cout << "Password 1: " << password1 << endl;
    cout << "Hash 1: " << hashPassword(password1) << endl;
    
    cout << "\nPassword 2: " << password2 << endl;
    cout << "Hash 2: " << hashPassword(password2) << endl;
    
    cout << "\nPassword 3: " << password3 << endl;
    cout << "Hash 3: " << hashPassword(password3) << endl;
    
    cout << "\nNote: Same passwords produce same hash" << endl;
}

// Explanations
void caesarExplanation(){
    cout << '\n' << "Example: " << '\n'
         << "Enter password: HelloWorld" << '\n'
         << "Enter shift: 3" << '\n'
         << "Output: KhoorZruog" << endl;

    cout << '\n' << "**  How it works:  **" << endl;
    cout << "Each letter is shifted by 3 positions in the alphabet" << '\n'
    << "H → K, e → h, l → o, etc." << '\n' 
    << "Mathematical formula: E(x) = (x + 3) mod 26" << endl;
    
    cout << '\n' << "**  Limitation  **" << endl;
    cout << "Works only for text not numbers" << endl;
    cout << "Vulnerable to attacks based on the analysis of letter frequency" << endl;

    stopExecution();
}

void vigenereExplanation(){
    cout << '\n' << "Example: " << '\n'
         << "Enter password: HelloWorld" << '\n'
         << "Enter key: KEY" << '\n'
         << "Output: RijvsUyvjn" << endl;

    cout << '\n' << "**  How it works:  **" << endl;

    cout << "Each letter is shifted by corresponding key letter" << '\n'
         << "H + K, e + E, l + Y, etc." << '\n' 
         << "More secure than Caesar cipher" << endl;

    
    cout << '\n' << "**  Limitation  **" << endl;
    cout << "Works only for text not numbers" << endl;
    cout << "Vulnerable to attacks based on the analysis of letter frequency" << endl;

    stopExecution();
}

void affineExplanation(){
    cout << '\n' << "Example: " << '\n'
         << "Enter password: HelloWorld" << '\n'
         << "Enter key 'a': 5" << '\n'
         << "Enter key 'b': 8" << '\n'
         << "Output: RcllaOaplx" << endl;

    cout << '\n' << "**  How it works:  **" << endl;

    cout << "Key 'a' must be coprime with 26" << '\n'
         << "Because of this the modular inverse of a also exists" << '\n'
         << "Encyption formula: E(x) = (5 * x + 8) mod 26" << '\n'
         << "Decyption formula: D(x) = (modInverse(5) * (x - 8)) mod 26" << '\n'
         << "Valid values for 'a': 1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25" << endl;

    
    cout << '\n' << "**  Limitation  **" << endl;
    cout << "Works only for text not numbers" << endl;
    cout << "Vulnerable to attacks based on the analysis of letter frequency" << endl;

    stopExecution();
}

void hashingExplanation(){
    cout << '\n' << "Example: " << '\n'
         << "Enter password: MyPassword123" << '\n'
         << "Output: 972352" << endl;

    cout << '\n' << "**  How it works:  **" << endl;

    cout << "One-way function, cannot be reversed" << '\n'
         << "Same password always produces same hash" << '\n'
         << "Used for secure password storage" << endl;

    stopExecution();
}

// Utility Function
void stopExecution(){
    cout << '\n' << "Press Enter to continue...";
    cin.ignore();
    cin.get();
}

void generateColors(int color){
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
