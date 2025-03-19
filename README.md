# XOR Encryption/Decryption Algorithm

This project implements a simple XOR-based encryption and decryption algorithm. XOR encryption is a fundamental cryptographic technique that uses the XOR (exclusive OR) operation to encrypt and decrypt data. The algorithm is symmetric, meaning the same key is used for both encryption and decryption.

## Features

- **Encryption**: Encrypts plaintext using a user-provided key and outputs the result in hexadecimal format.
- **Decryption**: Decrypts hexadecimal-encoded ciphertext back to plaintext using the same key.
- **Hex Conversion**: Converts binary data to and from hexadecimal representation for easier handling and display.

## How It Works

1. **Encryption**:
   - The user provides a plaintext and a key.
   - The algorithm performs an XOR operation between each character of the plaintext and the corresponding character of the key (repeating the key if necessary).
   - The result is converted to a hexadecimal string for easy storage and transmission.

2. **Decryption**:
   - The user provides a hexadecimal-encoded ciphertext and the same key used for encryption.
   - The algorithm converts the hexadecimal string back to binary data.
   - It then performs the XOR operation again to retrieve the original plaintext.
