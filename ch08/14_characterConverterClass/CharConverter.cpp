#include "CharConverter.h"
#include <cctype>

// Convert lowercase letters to uppercase 
string CharConverter::uppercase(const string& str) {
    string result = str;
    for (char& ch : result) {
        ch = toupper(ch);           // convert each char to uppercase      
    }

    return result;
}

// Convert first letter of each word to uppercase 
string CharConverter::properWords(const string& str) {
    string result = str;
    bool capNext = true;

    for (char& ch : result) {
        if (isspace(ch)) {
            capNext = true;           // nex char should be capitalized  
        } else if (capNext && isalpha(ch)) {
            ch = toupper(ch);
            capNext = false;   // reset flag 
        }
    }

    return result;
}
