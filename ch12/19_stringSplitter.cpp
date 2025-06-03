/*
Write a function vector<string> split(string str) that takes a string as parameter and returns a vector of the distinct words in the string. 
A distinct word is any run of characters delimited by the beginning of the string, the end of the string, or whitespace. A consecutive run 
of whitespace characters is to be treated the same as a single whitespace character. Test your program by having the user enter lines of 
input, reading and splitting the line into words, and printing the words in the returned vector with each word on its own line. For example, 
the input

        Every       good boy      does fine.

results in the output
        
        Every
        good
        boy 
        does
        fine.
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(const string& str) {
    vector<string> words;
    stringstream ss(str);
    string word;

    while (ss >> word) {
        words.push_back(word);
    }

    return words;
}

int main() {
    string line;

    cout << "Enter lines of text to split into words.\n";
    cout << "Type 'quit' or an empty line to exist.\n";

    while(true) {
        cout << "\nInput:";
        getline(cin, line);

        if (line.empty() || line == "quit") {
            cout << "Exiting program.\n";
            break;
        }

        vector<string> wordsInLine = split(line);

        cout << "Output words: \n";
        if (wordsInLine.empty() && !line.empty() && line.find_first_not_of(" \t\n\v\f\r") == string::npos) {
            cout << "(Line contained only whitespace)\n";
        } else if (wordsInLine.empty()) {
            cout << "(No words to display)\n";
        } else {
            for (const string& w : wordsInLine) {
                cout << w << endl;
            }
        }
    }

    return 0;
}
