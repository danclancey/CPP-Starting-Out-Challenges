/*
Write a class EncryptableString that is derived from the STL string class. The Encryptable string class adds a member function

        void encrypt( )

that encrypts the string contained in the object by replacing each letter with its successor in the ASCII ordering. For example, the 
string baa would be encrypted to cbb. Assume that all characters that are part of an EncryptableString object are letters a, .., z 
and A, .., Z, and that the successor of z is a and the successor of Z is A. Test your class with a program that asks the user to 
enter strings that are then encrypted and printed.
*/

#include <iostream>

using namespace std;

// Class derivedf rom string class 
class EncryptableString : public string {
    public:
        // Constructor
        EncryptableString(const string str) : string(str) {}

        // Member Function - Encrypt string 
        void encrypt();
};

// Function that "encrypts" string by incrementing each char 
void EncryptableString::encrypt() {
    for (char& ch : *this) {
        if (isalpha(ch)) {
            if (ch == 'z') {
                ch = 'a';           // Wrap around for lowercase z
            } else if (ch == 'Z') { // Wrap around for uppercase Z
                ch = 'A';
            } else {
                ch++;               // Increment the character 
            }
        }
    }
}

// Main program
int main() {
    string input;

    cout << "Enter a string to encrypt: ";
    getline(cin, input);

    // Create object 
    EncryptableString encryptStr(input);

    // Display original string 
    cout << "\nOriginal string: " << encryptStr << endl;

    // Encrypt the string 
    encryptStr.encrypt();

    // Show encrypted string 
    cout << "Encrypted string: " << encryptStr << endl;

    return 0;
}
