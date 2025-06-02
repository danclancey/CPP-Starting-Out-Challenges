/*
Write a program that accepts as input a sentence in which all of the words are run together, but the first character of each word is uppercase. 
Convert the sentence to a string in which the words are separated by spaces and only the first word starts with an uppercase letter. For example 
the string “StopAndSmellTheRoses.” would be converted to “Stop and smell the roses.”
*/

#include <iostream>
using namespace std;

int main() {
    string input;
    string output;

    cout << "Enter a sentence with words run together and uppercase first letter (i.e. StopAndSmellTheRoses): ";
    getline(cin, input);

    if (!input.empty()) {
        output += input[0];

        for (size_t i = 1;  i < input.length(); ++i) {
            char currentChar = input[i];

            if (isupper(currentChar)) {
                output += ' ';
                output += tolower(currentChar);
            } else {
                output += currentChar;
            }
        }
    }

    cout << "Converted sentence: " << output << endl;

    return 0;
}
