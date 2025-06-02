/*
Modify the program Pr10-16 so that it uses smart pointers rather than raw pointers.
*/

#include <iostream>
#include <string>
#include <memory>  // For smart pointers

using namespace std;

class Squares {
private:
    int length;     // How long is the sequence
    unique_ptr<int[]> sq;  // Smart pointer to dynamically allocated array

public:
    // Constructor allocates storage for the sequence
    // of squares and creates the sequence
    Squares(int len) : length(len), sq(make_unique<int[]>(length)) {
        for (int k = 0; k < length; k++) {
            sq[k] = (k + 1) * (k + 1);
        }
        // Trace
        cout << "Construct an object of size " << length << endl;
    }

    // Print the sequence
    void print() {
        for (int k = 0; k < length; k++)
            cout << sq[k] << "  ";
        cout << endl;
    }

    // Destructor automatically deallocates the smart pointer memory
    ~Squares() {
        // Trace
        cout << "Destroy object of size " << length << endl;
    }
};

//***********************************************
// Outputs the sequence of squares in a         *
// Squares object                               *
//***********************************************
void outputSquares(const unique_ptr<Squares>& sqPtr) {
    cout << "The list of squares is: ";
    sqPtr->print();
}

int main() {
    // Main allocates a Squares object using a smart pointer
    unique_ptr<Squares> sqPtr = make_unique<Squares>(3);
    outputSquares(sqPtr);

    return 0;
}

