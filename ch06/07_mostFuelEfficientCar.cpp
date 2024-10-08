/*
Three cars drive a 500 mile route. Write a program that inputs the car make and the number of gallons 
of fuel used by each car. After calling a calcMPG() function once for each car, have main determine 
and display which car was the most fuel efficient and how many miles per gallon it got. The calcMPG() 
function should be passed the distance driven and the gallons of gas used as arguments, and should 
return the miles per gallon obtained.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Function prototype
double calcMPG(double distance, double gallons);

int main() {
    const double DISTANCE = 500.0;  // Distance for each car
    string carMake1, carMake2, carMake3;
    double gallons1, gallons2, gallons3;

    // Input car make and gallons used for car 1
    cout << "Enter the make of the first car: ";
    getline(cin, carMake1);
    do {
        cout << "Enter the gallons of fuel used by " << carMake1 << ": ";
        cin >> gallons1;
        if (gallons1 <= 0) {
            cout << "Gallons must be a positive number. Please try again.\n";
        }
    } while (gallons1 <= 0);

    // Input car make and gallons used for car 2
    cout << "Enter the make of the second car: ";
    cin.ignore();  // Clear the newline character from the input buffer
    getline(cin, carMake2);
    do {
        cout << "Enter the gallons of fuel used by " << carMake2 << ": ";
        cin >> gallons2;
        if (gallons2 <= 0) {
            cout << "Gallons must be a positive number. Please try again.\n";
        }
    } while (gallons2 <= 0);

    // Input car make and gallons used for car 3
    cout << "Enter the make of the third car: ";
    cin.ignore();  // Clear the newline character from the input buffer
    getline(cin, carMake3);
    do {
        cout << "Enter the gallons of fuel used by " << carMake3 << ": ";
        cin >> gallons3;
        if (gallons3 <= 0) {
            cout << "Gallons must be a positive number. Please try again.\n";
        }
    } while (gallons3 <= 0);

    // Calculate MPG for each car
    double mpg1 = calcMPG(DISTANCE, gallons1);
    double mpg2 = calcMPG(DISTANCE, gallons2);
    double mpg3 = calcMPG(DISTANCE, gallons3);

    // Determine which car is most fuel efficient
    string mostEfficientCar;
    double highestMPG;

    if (mpg1 > mpg2 && mpg1 > mpg3) {
        mostEfficientCar = carMake1;
        highestMPG = mpg1;
    } else if (mpg2 > mpg1 && mpg2 > mpg3) {
        mostEfficientCar = carMake2;
        highestMPG = mpg2;
    } else {
        mostEfficientCar = carMake3;
        highestMPG = mpg3;
    }

    // Display result
    cout << fixed << setprecision(2);
    cout << "\nThe most fuel efficient car is the " << mostEfficientCar 
         << " with " << highestMPG << " MPG.\n";

    return 0;
}

// Function to calculate MPG
double calcMPG(double distance, double gallons) {
    return distance / gallons;
}

