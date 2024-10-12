#ifndef TESTGRADER_H
#define TESTGRADER_H 

#include <string>

using namespace std;

class TestGrader {
    private:
        char answers[20];

    public:
        void setKey(const string& key);
        string grade(const char stuAnswers[]);
};

#endif
