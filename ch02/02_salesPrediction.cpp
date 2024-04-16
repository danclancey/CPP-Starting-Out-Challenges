/* 
    The East Coast sales division of a company generates 58% of total sales. 
    Based on that percentage, write a program that will predict how much the 
    east coast division will generate if the company has $8.6 million in 
    sales this year. Display the result on the screen.
*/

#include <iostream>
#include <iomanip>
#include <locale>

using namespace std;

int main() 
{
    // Declare variables
    double companySales = 8600000;
    double divisionPct = 0.58;
    double divisionSales;

    // Calculate division sales
    divisionSales = companySales * divisionPct;

    // Display projected division sales
    cout.imbue(locale(""));
    cout << fixed << setprecision(2);
    cout << "The East Coast Division will generate $" << divisionSales <<
            " in sales if the company generates $" << companySales;

    return 0;
}