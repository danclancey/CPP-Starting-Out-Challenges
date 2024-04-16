/*
    One acre of land is equivalent to 43,450 square feet. 

    Write a program that calculates and displays the number of acres in a tract
    of land whose size is number of acres in a tract of land 869 x 360 feet.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Declare variables
    double acreInFeet = 43450;
    double landInFeet, landInAcres;
    
    // Calculate Square Feet
    landInFeet = 869 * 360;

    // Convert square feet to acres
    landInAcres = landInFeet / acreInFeet;

    // Display results
    cout << fixed << setprecision(2);
    cout << landInFeet << " square feet is approximately " << landInAcres << " acres.";

    return 0;
}