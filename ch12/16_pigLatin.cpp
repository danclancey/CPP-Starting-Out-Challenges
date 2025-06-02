/*
Write a program that reads a sentence as input and converts each word to “Pig Latin.” In one version, to convert a word to Pig Latin you 
remove the first letter and place that letter at the end of the word. Then you append the string “ay” to the word. Here is an example:

English: I SLEPT MOST OF THE NIGHT
Pig Latin: IAY LEPTSAY OSTMAY FOAY HETAY IGHTNAY
*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string convertTopigLatin(const string& word) {
    if (word.empty()) {
        return "";
    }

    if (word.length() == 1) {
        return word + "AY";
    }

    char firstLetter = word[0];
    string restOfWord = word.substr(1);

    return restOfWord + firstLetter + "AY";
}

int main() {
    string sentence;
    string pigLatinSentence;

    cout << "Enter a sentence: ";
    getline(cin, sentence);

    stringstream ss(sentence);
    string word;
    bool firstWordProcessed = false;

    while (ss >> word) {
        if (firstWordProcessed) {
            pigLatinSentence += " ";
        }

        pigLatinSentence += convertTopigLatin(word);
        firstWordProcessed = true;
    }

    cout << "PIg Latin: " << pigLatinSentence << endl;

    return 0;

}
