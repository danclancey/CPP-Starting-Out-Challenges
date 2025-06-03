/*
A friend of yours who is an educator is conducting research into the effectiveness of teaching the spelling rule “I before e except after c” 
to students. She wishes to analyze writing samples from two groups of students, only one of which was taught the rule. Write a program that 
will take a file containing a writing sample and print a list of all words in the file that contain at least one of the strings “ie” or “ei”.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

string toLower(string s);
string cleanWord(const string& word);

int main() {
    string filename;
    ifstream inputFile;
    vector<string> foundWords; 

    cout << "Enter the name of the file to analyze: ";
    cin >> filename;

    inputFile.open(filename);

    if (!inputFile.is_open()) {
        cerr << "Error: Could not open file \"" << filename << "\"" << endl;
        return 1; 
    }

    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line); 
        string word;

        while (ss >> word) {
            string cleanedWord = cleanWord(word);
            string lowerWord = toLower(cleanedWord);

            if (lowerWord.empty()) { 
                continue;
            }

            if (lowerWord.find("ie") != string::npos || lowerWord.find("ei") != string::npos) {
                bool alreadyExists = false;
                for (const string& fw : foundWords) {
                    if (toLower(fw) == lowerWord) { 
                        alreadyExists = true;
                        break;
                    }
                }
                if (!alreadyExists) {
                    foundWords.push_back(cleanedWord);
                }
            }
        }
    }

    inputFile.close();

    sort(foundWords.begin(), foundWords.end(), [](const string& a, const string& b) {
        return toLower(a) < toLower(b);
    });

    if (foundWords.empty()) {
        cout << "\nNo words containing \"ie\" or \"ei\" were found in the file." << endl;
    } else {
        cout << "\nWords containing \"ie\" or \"ei\" found in the file:" << endl;
        for (const string& w : foundWords) {
            cout << w << endl;
        }
    }

    return 0; 
}

string toLower(string s) {
    transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c){ return tolower(c); });
    return s;
}

string cleanWord(const string& word) {
    if (word.empty()) {
        return "";
    }

    size_t first = 0;
    while (first < word.length() && ispunct(static_cast<unsigned char>(word[first]))) {
        first++;
    }

    size_t last = word.length();
    while (last > first && ispunct(static_cast<unsigned char>(word[last - 1]))) {
        last--;
    }
    
    if (first >= last) { 
        return "";
    }

    return word.substr(first, last - first);
}
