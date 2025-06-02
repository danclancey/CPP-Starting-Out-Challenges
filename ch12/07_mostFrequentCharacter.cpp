/*
Write a function that accepts either a pointer to a C-string or a string object as its argument. The function should return the 
character that appears most frequently in the string. Demonstrate the function in a complete program.
*/

#include <iostream>
#include <cstring>   
#include <string>    

using namespace std;

// Function prototypes 
char mostFrequentChar(const char *str);
char mostFrequentChar(const string &str);

int main() {
    // C-string test
    char cString[] = "hello world";
    cout << "For C-string '" << cString << "', the most frequent character is: "
         << mostFrequentChar(cString) << endl;

    // C++ string test
    string cppString = "programming";
    cout << "For string object '" << cppString << "', the most frequent character is: "
         << mostFrequentChar(cppString) << endl;

    return 0;
}

// Function to find the most frequent character in a C-string
char mostFrequentChar(const char *str) {
    int freq[256] = {0};  // Array to hold frequency of each ASCII character

    // Calculate frequency of each character in the C-string
    for (int i = 0; i < strlen(str); i++) {
        freq[(unsigned char)str[i]]++;  // Increment frequency count of each character
    }

    // Find the most frequent character
    char mostFrequent = '\0';
    int maxFreq = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            mostFrequent = (char)i;
        }
    }

    return mostFrequent;
}

// Function to find the most frequent character in a C++ string object
char mostFrequentChar(const string &str) {
    int freq[256] = {0};  // Array to hold frequency of each ASCII character

    // Calculate frequency of each character in the string
    for (char ch : str) {
        freq[(unsigned char)ch]++;  // Increment frequency count of each character
    }

    // Find the most frequent character
    char mostFrequent = '\0';
    int maxFreq = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            mostFrequent = (char)i;
        }
    }

    return mostFrequent;
}

