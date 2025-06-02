/*
Write a function named replaceSubstring. The function should accept three C-string or string object arguments. Let’s call them 
string1, string2, and string3. It should search string1 for all occurrences of string2. When it finds an occurrence of string2, 
it should replace it with string3. For example, suppose the three arguments have the following values:

        string1:          "the dog jumped over the fence"
        string2:          "the"
        string3:          "that"

With these three arguments, the function would return a string object with the value “that dog jumped over that fence”. Demonstrate 
the function in a complete program.
*/

#include <iostream>
#include <string>

using namespace std;

// Function prototype
string replaceSubstring(string string1, const string &string2, const string &string3);

int main() {
    // Input strings for testing
    string str1 = "the dog jumped over the fence";
    string str2 = "the";
    string str3 = "that";

    cout << "Original string: " << str1 << endl;
    cout << "Replacing '" << str2 << "' with '" << str3 << "'..." << endl;

    // Call the replaceSubstring function
    string result = replaceSubstring(str1, str2, str3);

    // Display the result
    cout << "Modified string: " << result << endl;

    return 0;
}

// Function to replace all occurrences of string2 in string1 with string3
string replaceSubstring(string string1, const string &string2, const string &string3) {
    size_t pos = string1.find(string2); // Find the first occurrence of string2

    // Loop through all occurrences and replace them
    while (pos != string::npos) {
        string1.replace(pos, string2.length(), string3); // Replace the found substring with string3
        pos = string1.find(string2, pos + string3.length()); // Find the next occurrence
    }

    return string1; // Return the modified string
}

