/*
A country club, which currently charges $3,000 per year for membership, has announced 
it will increase its membership fee by 3 percent each year for the next five years. 
Write a program that uses a loop to display the projected rates for each of the next 
five years.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    const double RATE_INCREASE = 0.03;  // 3% increase per year
    double membershipFee = 3000.00;     // Initial membership fee

    // Display column headers
    cout << setw(7) << left << "Year" << setw(15) << right
         << "Membership Fee\n";
    cout << "----------------------\n";

    // Loop through the next 5 years and calculate the new fee each year
    for (int year = 1; year <= 5; year++) {
        // Increase the membership fee by 3%
        membershipFee += membershipFee * RATE_INCREASE;

        // Display the year and the membership fee
        cout << setw(4) << left << year << setw(9) << right
             << "$" << fixed << setprecision(2) << membershipFee << endl;
    }

    return 0;
}

