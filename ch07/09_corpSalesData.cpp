/*
Write a program that uses a structure named CorpData to store the following information 
on a company division: division name (e.g., East, West, North, or South), qtr1 sales, 
qtr2 sales, qtr3 sales, and qtr4 sales

Include a constructor that allows the division name and four quarterly sales amounts to 
be specified at the time a CorpData variable is created.

The program should create four CorpData variables, each representing one of the following 
corporate divisions: East, West, North, and South. These variables should be passed one 
at a time, as constant references, to a function that computes the division’s annual sales 
total and quarterly average, and displays these along with the division name.
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct CorpData {
    string division;
    double q1Sales;
    double q2Sales;
    double q3Sales;
    double q4Sales;

    // Constructor
    CorpData(string d, double q1, double q2, double q3, double q4) {
        division = d;
        q1Sales = q1;
        q2Sales = q2;
        q3Sales = q3;
        q4Sales = q4;
    }
};

// Function protoype
void computeSalesData(const CorpData& data);

int main() {
    // Create CorpData Objects for each division
    CorpData east("East", 1337.44, 1087.00, 1732.32, 1414.14);
    CorpData west("West", 1234.56, 2345.67, 1324.44, 1817.13);
    CorpData north("North", 1111.22, 1222.33, 1333.44, 1223.45);
    CorpData south("South", 2111.33, 1142.56, 5672.13, 3275.14);

    // Display sales data for each division 
    computeSalesData(east);
    computeSalesData(west);
    computeSalesData(north);
    computeSalesData(south);

    return 0;
}

// Function to compute and display sales data
void computeSalesData(const CorpData& data) {
    double annualSales = data.q1Sales + data.q2Sales + data.q3Sales + data.q4Sales;
    double quarterlyAverage = annualSales / 4; 
    
    cout << fixed << setprecision(2);
    cout << "\nDivision:\t\t" << data.division << endl;
    cout << "Annual Sales:\t\t$" << annualSales << endl;
    cout << "Quarterly Average:\t$" << quarterlyAverage << endl;
    cout << "----------------------------------\n";

}
