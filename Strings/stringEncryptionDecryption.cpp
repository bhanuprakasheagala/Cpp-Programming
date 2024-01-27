#include <iostream>
#include <string>

int main() {
    int choice, key;
    std::string inputString;
    
    std::cout << "\t\t\tString Encryption and Decryption with a simple Ceasar Cipher\t\t\n";
    std::cout << "1. Encrypt a string\n2. Decrypt a string\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cin.ignore() // Clear the newline characted from buffer
    std::static_assert((key == 1) || (key == 2))
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

            std::cout << "Enter the negative value of encryption key to decrypt: ";
            std::cin >> key;

            std::string decryptedString = decryptString(inputString, key);
            std::cout << "Decrypted string: " << decryptedString << '\n';

            break;
        }

        default :
            std::cout << "Invalid "
    }

    return 0;
}