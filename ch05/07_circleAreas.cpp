/*
The formula to compute the area of a circle is

        Area = PI * Radius^2

so if a circle’s radius doubles (i.e., is multiplied by 2), the circle’s area 
will be four times as large as before. Write a program that creates a table 
showing the radius and area for a circle whose radius begins with 1 and 
continues doubling until it is 8. Use 3.14 for PI.
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    const double PI = 3.14;
    double area;
    
    // Display column headers
    cout << "Radius     Area\n";
    cout << "---------------\n";
    for (int r = 1; r <= 8; r*=2) {
        // Calculate area
        area = PI * pow(r, 2);
        
        // Display table of radius and area
        cout << setw(4) << r << setw(11) << area << endl;
    }
}
