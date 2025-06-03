/*
Write a program that queries its environment, determines the user’s login name, and then greets the user by name. For example, if the login 
name of the user is gcm, then the program prints

        Hello, gcm

when it is executed.
*/

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    const char* usernameEnv = nullptr;

    if (usernameEnv == nullptr) {
        usernameEnv = getenv("USER");
    }

    if (usernameEnv == nullptr) {
        usernameEnv = getenv("LOGNAME");
    }

    if(usernameEnv ==nullptr) {
        usernameEnv = getenv ("USERNAME");
    }

    if (usernameEnv != nullptr) {
        string username(usernameEnv);
        cout << "Hello, " << username << endl;
    } else {
        cout << "Hello, unknown user! (could not determine specific login name)\n";
    }

    return 0;
}
