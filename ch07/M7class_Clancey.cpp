/*
Dan Clancey
CIS 211
M7class_Clancey.cpp

    In this module you learned about Object-Oriented programming in C++ and how to combine this approach with the concepts covered in previous modules
        * Create an application named as M7class_YourLastname
        * NOTE: All variables should be correctly named, using the naming standards indicated in the book.
        * For this assignment you will write a class called Dog that has the following member variables:
            * birthyear. An int that holds the dog’s birth year.
            * breed. A string that holds the breed of dog.
            * vaccines. A Boolean holding a yes/no value indicating whether the dog is currently on vaccinations.
        * In addition, the class should have the following member functions:
            * Constructor. The constructor should accept the dog’s birthyear, breed and vaccines as arguments and assign these values to the object’s birthyear, breed and vaccines member variables.
            * Mutator. Appropriate mutator functions should be created to allow the values to be set from an object's birthyear, breed and vaccine member variables.
            * Accessors. Appropriate accessor functions should be created to allow values to be retrieved from an object’s birthyear, breed and vaccines member variables.
        * Demonstrate the class in a program that creates a Dog object including the accessors and mutators. The user should enter all input. Be sure to include comments throughout your code where appropriate.
    Complete the C++ code using a developers environment, upload the main or source.cpp file to the submission area by the listed due date.
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Dog
{
    private:
        int birthyear;  // Dogs birth year
        string breed;   // Name of Dog Breed
        bool vaccines;  // Yes/No value indiciating vaccination status

    public:
    //Constructor with default values
    Dog (int y = 2018, string b = "Amstaff", bool v = true)
    {
        birthyear = y;
        breed = b;
        vaccines = v;
    }

    // Accessors
    int getYOB()
    {   return birthyear;   }

    string getBreed()
    {   return breed;   }

    bool getVaccines()
    {   return vaccines;    }

    // Mutators

    void setYOB( int y)
    {
        birthyear = y;
    }

    void setBreed(string b)
    {
        breed = b;
    }

    void setVaccines(bool v)
    {
        vaccines = v;
    }
};

// ***** main program *****

int main()
{
    int birthyear;
    string breed;
    bool vaccines;
    Dog newDog; // Create Dog object
    
    // Prompt user for Dog birth year
    cout << "Please enter Dog birth year: ";
    cin >> birthyear;
    newDog.setYOB(birthyear);

    // Prompt user for Dog breed
    cout << "Please enter the Dog breed: ";
    cin.ignore();           // Ignore newline character left in the input buffer
    getline(cin, breed);    // Handles breeds with spaces in name
    newDog.setBreed(breed);

    // Prompt user for vaccination status for Dog
    cout << "Is the Dog vaccinated? (1 for Yes, 0 for No): ";
    cin >> vaccines;
    newDog.setVaccines(vaccines);

    // Print dog information
    cout << "\nDog Information:" << endl;
    cout << left << setw(24) << "  Birth Year: " << newDog.getYOB() << endl;
    cout << left << setw(24) << "  Breed: " << newDog.getBreed() << endl;
    cout << left << setw(24) <<  "  Vaccination Status: " << (newDog.getVaccines() ? "Yes" : "No") << endl; // Assigns 1 to "Yes" and 0 to "No"

    return 0;
}