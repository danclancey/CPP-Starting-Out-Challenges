/*
The Fast Freight Shipping Company charges the following rates:

Weight of Package (in kilograms)        Rate per 500 Miles Shipped
        2 kg or less	                        $3.10
Over 2 kg but not more than 6 kg	            $4.20
Over 6 kg but not more than 10 kg	            $5.30
        over 10 kg	                            $6.40

Miles that are not a multiple of 500 are charged at the next higher rate. For example, 520 miles 
would be charged as 1000 miles.

Write a program that asks for the weight of a package and the distance it is to be shipped. These 
two data items should be passed as arguments to a calculateCharge function that computes and returns 
the shipping charge to be displayed. The main function should loop to handle multiple packages until 
a weight of 0 is entered.
*/

#include <iostream>
#include <iomanip>

using namespace std;

// Function prototype
double calculateCharge (double weight, int distance);

int main() {
    double weight;
    int distance;

    // Loop for multiple packages
    do {
        // Get weight of package
        do {
            cout << "Enter the weight of the package in kilograms (or 0 to quit): ";
            cin >> weight;

            // Validate input
            if (weight < 0)
                cout << "Weight cannot be negaitve. Please enter valid weight.\n";
        } while (weight < 0);
        
        // Check for exiting program (0)
        if (weight == 0 ) {
            cout << "Exiting . . .\n";
            break;
        }
        
        // Get distance to ship package 
        do {
            cout << "Enter the distance to be shipped (in miles): ";
            cin >> distance;
            
            // Validate input
            if (distance < 0)
                cout << "Distance cannot be negative, Please enter positive distance.\n";
        } while (distance < 0);

        // Calculate and display charge 
        double charge = calculateCharge(weight, distance);
        cout << fixed << setprecision(2);
        cout << "The shipping charge is: $" << charge << endl;

    } while (weight != 0);

    return 0;
}


double calculateCharge (double weight, int distance) {
    double rate;

    // Determine rate based on weight 
    if (weight <= 2)
        rate = 3.10;
    else if (weight <= 6)
        rate = 4.20;
    else if (weight <= 10) 
        rate = 5.30;
    else 
        rate = 6.40;

    // Calculate 500 mile units
    int distanceUnits = distance / 500;
    if (distance % 500 != 0)
        distanceUnits += 1;

    return rate * distanceUnits;
}
