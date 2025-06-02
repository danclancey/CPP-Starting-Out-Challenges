#ifndef STRINGCHECKER_H
#define STRINGCHECKER_H

#include <iostream>
#include <cctype>
#include <string>

using namespace std;

class StringChecker {
    private:
        std::string inputString;

    public:
        static int countVowels(const char* str);
        static int countConsonants(const char* str);

        void setInputString();
        const string& getInputString() const;
};

#endif
