/*
A palindromic number is a positive integer that reads the same forward as backward. For example, the numbers 1, 11, and 121 are palindromic. 
Moreover, 1 and 11 are very special palindromic numbers: their squares are also palindromic. How many positive integers less than 10,000 
have this property? Write a program to list all such numbers together with their squares.

The beginning part of your output should look like this:

        1 has square 1
        2 has square 4
        3 has square 9
        11 has square 121
        22 has square 484

Hint: If str is a string object, the reverse() function (declared in <algorithm> header) will reverse the string. The code to do that is:

        reverse(str.begin(), str.end());
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool isPalindrome(long long n) {
    string s = to_string(n);

    string reversedS = s;
    reverse(reversedS.begin(), reversedS.end());

    return s == reversedS;
}

int main() {
    cout << "Listing numbers less than 10k whose squares are also palindromic:\n";
    int count = 0;

    for (long long i = 1; i < 10000; ++i) {
        long long iSquared = i * i;

        if (isPalindrome(i) && isPalindrome(iSquared)) {
            cout << i << " has square " << iSquared << endl;
            count++;
        }
    }

    cout << "\nTotal number of such ints found: " << count << endl;

    return 0;
}
