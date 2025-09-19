# C-Project-Encryption-Decryption
A basic C project for encrypting and decrypting text using custom or standard algorithms.

# Caesar Cipher - Encryption & Decryption in C

This is a basic C language project that implements **encryption and decryption using the Caesar Cipher** technique. It allows you to **generate alphabetic keys** and perform secure message transformations by shifting characters based on a given key.

## Features

- Encrypt plain text using Caesar Cipher  
- Decrypt cipher text using Caesar Cipher  
- Alphabetic key generation and usage  
- Supports both uppercase and lowercase characters  
- Ignores non-alphabetic characters (e.g., numbers, punctuation)  
- Simple, beginner-friendly code in C  

## What is Caesar Cipher?

The Caesar Cipher is a basic encryption technique where each letter in the plain text is shifted by a fixed number of positions in the alphabet.  
Example with key = 3:  
Plain Text: `HELLO` → Cipher Text: `KHOOR`

## How to Run

1. **Compile the code** (using GCC or any C compiler):  
   `gcc main.c -o caesar`

2. **Run the program**:  
   `./caesar`

3. **Follow the prompts** to enter:  
   - The message to encrypt/decrypt  
   - The shift key  (in my file key is given by user itself and same key use for decryption)

## Learn More

This project is ideal for:  
- Beginners learning C programming  
- Understanding classical cryptography  
- Exploring string manipulation and ASCII operations 
