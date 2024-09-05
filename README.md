# Rotation Cipher Encryption Program

## Description

This C program implements a rotation cipher encryption algorithm on text files. It's designed to encrypt letters in the input file using a variable rotation based on their position, while leaving non-alphabetic characters unchanged. The program also generates a report with statistics about the encryption process.

## Features

- Encrypts letters using a rotation cipher with a variable key (k) that cycles from 1 to 5
- Preserves whitespace, digits, and punctuation
- Allows user to specify two special characters that increment the rotation key
- Generates a formatted report with encryption statistics

## How it works

1. The program prompts the user for:
    - Input file name
    - Output file name
    - Two special characters (digits or punctuation)

2. It reads the input file character by character, applying the following rules:
    - Letters are encrypted by rotating them 'k' positions (k cycles from 1 to 5)
    - Whitespace resets k to 1
    - The two special characters increment k
    - Non-alphabetic characters are left unchanged

3. The encrypted text is written to the output file

4. A report is generated with the following information:
    - Input and output file names
    - Number of letters processed
    - Percentage of the file that was changed
    - Average distance that the letters were changed

## Usage

1. Compile the program using a C compiler (e.g., gcc)
2. Run the executable
3. Follow the prompts to enter the required information
4. Check the output file for the encrypted text and the console for the report

## Requirements

- C compiler (e.g., GCC)
- Standard C libraries: stdio.h, ctype.h

## Notes

- The program ensures that the rotation wraps around the alphabet (e.g., 'z' + 2 becomes 'b')
- Special care is taken to handle edge cases and ensure proper character casting

## Author

Bhuwan Bhandari
