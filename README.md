# Password Security Mechanism
### CS101 - Discrete Mathematics Project
**Group 3:** Shahram Ali Butt (2025-CS-20)

---

## Project Overview
This project implements various cryptographic algorithms using discrete mathematics concepts to secure passwords and usernames. Instead of storing passwords in plain text, the system encrypts them using classical and modern cryptographic techniques.

---

## Mathematical Foundations

### 1. **Caesar Cipher**
- **Encryption:** `E(x) = (x + shift) mod 26`
- **Decryption:** `D(x) = (x - shift) mod 26`

### 2. **Vigenère Cipher**
- **Encryption:** `E(x) = (x + k[i]) mod 26` where k[i] is the i-th key character
- **Decryption:** `D(x) = (x - k[i]) mod 26`

### 3. **Affine Cipher**
- **Concept:** Uses modular arithmetic with two keys (a, b)
- **Encryption:** `E(x) = (a*x + b) mod 26`
- **Decryption:** `D(x) = a^(-1) * (x - b) mod 26`
- **Requirement:** `a` must be coprime with 26 (gcd(a, 26) = 1)

### 4. **Hash Function**
- **Concept:** One-way function using modular arithmetic
- **Formula:** `hash = Σ(char[i] * prime^i) mod large_prime`

---

## Files Description

### crypto_functions.h
Header file containing all function declarations for:
- Caesar cipher encryption/decryption
- Vigenère cipher encryption/decryption
- Affine cipher encryption/decryption
- Hash function
- Utility functions (GCD, modular inverse etc.)

### crypto_functions.cpp
Implementation file containing all the cryptographic algorithms and helper functions.

### main.cpp
Main program with:
- Interactive menu system
- Demonstration functions for each algorithm
- Explanation of all cryptography techniques 
- Ability to join enciption techniques
- User-friendly interface

### passwordManagement.cpp
Business application integration with:
- **storeUserDataEnc()**: Encrypts usernames (Affine cipher: a=5, b=8) and passwords (hashed) before storing in users.txt
- **verifyUser()**: Decrypts stored usernames and compares hashed passwords for authentication
- **verifyAdmin()**: Double-hashes admin password for additional security layer
- **storeSignUpDataEnc()**: Encrypts signup requests using different Affine keys (a=9, b=15) to segregate from regular users
- **loadSignUpDataDec()**: Decrypts signup data for admin review and approval
- **checkUserExists()**: Verifies if username already exists without storing or exposing plain text
- **loadUserDataDec()**: Loads and decrypts user data for system operations and management

**Note**: Username encryption includes space handling - spaces are replaced with 'X' before encryption and restored after decryption to maintain username integrity.

---

## How to Compile and Run

### Option 1: Manual Compilation & Execution
```bash
g++ -o main main.cpp crypto_functions.cpp
```

```bash
./main
```

### Option 2: Running Bash Script
```bash
./build.sh
```

---

## Usage Examples

### Example 1: Caesar Cipher
```
Original: HelloWorld
Shift: 3
Encrypted: KhoorZruog
Decrypted: HelloWorld
```

### Example 2: Vigenère Cipher
```
Original: HelloWorld
Key: KEY
Encrypted: RijvsAipvh
Decrypted: HelloWorld
```

### Example 3: Affine Cipher
```
Original: HelloWorld
Keys: a=5, b=8
Encrypted: RczzcKcfzn
Decrypted: HelloWorld
```

#### Example 4: Hash Password
```
Example:
Enter password: MyPassword123
Output: 972352
```

---

## Key Features

1. **Multiple Encryption Methods:** Support for Caesar, Vigenère, Affine, and Hash
2. **Password Storage:** Securely store passwords in encrypted form
3. **Interactive Menu:** Easy-to-use interface for testing all features
4. **Demonstrations:** Built-in demos for each cryptographic method
5. **Explanations:** Built-in explanations about each cryptographic method
6. **Business Application Integration:** Real-world implementation in inventory management system

---

## Business Application Integration

The passwordManagement.cpp file provides a complete security layer for a business inventory management system:

### User Management
- **Users File (users.txt)**: Stores encrypted usernames and hashed passwords
- **Signup File (signUpData.txt)**: Stores pending signup requests with encryption
- **Admin File (admin.txt)**: Stores double-hashed admin password for extra security

### Security Features
1. **Dual Encryption Keys**: Different Affine cipher keys for users (a=5, b=8) and signup requests (a=9, b=15)
2. **Double Hashing**: Admin passwords are hashed twice for additional protection
3. **Space Handling**: Usernames with spaces are encrypted properly (spaces → 'X' → encrypted → restored)
4. **No Plain Text**: All credentials are encrypted before storage; never stored in readable format

### Function Overview

```cpp
// Store current users with encryption
storeUserDataEnc(currentUsers, userNames[], userPasswords[]);

// Verify user login
string currentUser;
if (verifyUser(currentUser, "username", "password")) {
    cout << "Login successful for: " << currentUser << endl;
}

// Verify admin login with double-hash
if (verifyAdmin("adminPassword")) {
    cout << "Admin access granted" << endl;
}

// Store signup request
storeSignUpDataEnc(signUpRequests, signUpRequestData[][2]);

// Load signup requests for admin review
loadSignUpDataDec(signUpRequests, signUpRequestData[][2]);

// Check if username exists
if (checkUserExists("username")) {
    cout << "Username already taken" << endl;
}

// Load all user data
loadUserDataDec(currentUsers, userNames[], userPasswords[]);
```

### File Format Examples

**users.txt:**
```
3
RcllaOaplx,972352
Pcala,876543
Pcalancrclqh,765432
```

**signUpData.txt:**
```
2
Jhgcrlmrmlq,972352
Bhdrqlm,876543
```

---

## Security Considerations

### Strengths:
- Passwords are not stored in plain text
- Multiple encryption methods available
- Hash function provides one-way encryption

### Limitations:
- Caesar cipher is easily breakable (frequency analysis)
- Vigenère can be broken with known key length
- Affine cipher has limited key space
- Simple hash function (not cryptographically secure)

**Note:** This is an educational project demonstrating discrete mathematics concepts.

---

## Discrete Mathematics Concepts Used

1. **Modular Arithmetic:** Foundation for all cipher operations
2. **Number Theory:** Prime numbers, GCD, modular inverse
3. **Cryptography:** Classical and public-key encryption
4. **Functions:** Hash functions, one-to-one mappings
5. **Algorithms:** Euclidean algorithm, modular exponentiation

---

## References

- Rosen, K. H. "Discrete Mathematics and Its Applications" - Chapter 4 (Number Theory)
- Rosen, K. H. "Discrete Mathematics and Its Applications" - Chapter 5 (Cryptography)

---

## Conclusion

This project demonstrates the application of discrete mathematics in computer security, specifically in password encryption and authentication systems. It shows how mathematical concepts like modular arithmetic, prime numbers, and cryptographic algorithms can be used to protect sensitive data.
