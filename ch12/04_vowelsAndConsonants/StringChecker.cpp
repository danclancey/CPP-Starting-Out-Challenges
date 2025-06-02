#include "StringChecker.h"

using namespace std;

int StringChecker::countVowels(const char* str) {
    int count = 0;
    while (*str != '\0') {
        char c = tolower(*str);
        if (isalpha(c) && (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')) {
            count++;
        }
        str++;
    }
    return count;
}

int StringChecker::countConsonants(const char* str) {
    int count = 0;
    while (*str != '\0') {
        char c = std::tolower(*str);
        if (isalpha(c) && !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')) {
            count++;
        }
        str++;
    }
    return count;
}

void StringChecker::setInputString() {
    do {
        cout << "Enter a string: ";
        getline(std::cin, inputString);
        if (inputString.empty()) {
            cout << "No input! Please enter a string.\n";
        }
    } while (inputString.empty());
}

const string& StringChecker::getInputString() const {
    return inputString;
}

