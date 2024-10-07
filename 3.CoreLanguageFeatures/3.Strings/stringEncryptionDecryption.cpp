#include <iostream>
#include <string>

std::string encryptString(const std::string& input, int key) {
    std::string encryptedString = "";

    // Iterate through each character in the input string
    for(char ch : input) {
        // Encrypt alphabetic characters only
        if(std::isalpha(ch)) {
            // Determine the shift considering upper and lower case
            char base = std::isupper(ch) ? 'A' : 'a';

            // Apply Ceasar cipher encryption
            char encryptedChar = ((ch - base + key) % 26 + 26) % 26 + base;

            // Append the encrypted character to make encrypted string
            encryptedString += encryptedChar;
        } 
        else {
            // Non-alphabetic characters are unchanged
            encryptedString += ch;
        }
    }

    return encryptedString;
}

std::string decryptString(const std::string& input, int key) {
    // Decrypting is essentially encrypting with the negative of the key
    key = -key;
    return encryptString(input, key);
}

int main() {
    int choice, key;
    std::string inputString;
    
    std::cout << "\t\t\tString Encryption and Decryption with a simple Ceasar Cipher\t\t\n";
    std::cout << "1. Encrypt a string\n2. Decrypt a string\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cin.ignore(); // Clear the newline characted from buffer
    switch(choice) {
        case 1: {
            std::cout << "Enter the string to be encrypted: ";
            std::getline(std::cin, inputString);

            std::cout << "Enter the encryption key (positive integer): ";
            std::cin >> key;

            std::string encryptedString = encryptString(inputString, key);
            std::cout << "Encrypted string: " << encryptedString << '\n';

            break;
        }

        case 2 : {
            std::cout << "Enter the string to be decrypted: ";
            std::getline(std::cin, inputString);

            std::cout << "Enter the decryption key: ";
            std::cin >> key;

            std::string decryptedString = decryptString(inputString, key);
            std::cout << "Decrypted string: " << decryptedString << '\n';

            break;
        }

        default :
            std::cout << "Invalid option.";
    }

    return 0;
}