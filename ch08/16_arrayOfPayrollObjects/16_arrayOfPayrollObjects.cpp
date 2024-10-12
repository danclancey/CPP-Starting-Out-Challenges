/*
Design a PayRoll class that has data members for an employee’s hourly pay 
rate and number of hours worked. Write a program with an array of seven 
PayRoll objects. The program should read the number of hours each employee 
worked and their hourly pay rate from a file and call class functions to 
store this information in the appropriate objects. It should then call a 
class function, once for each object, to return the employee’s gross pay, 
so this information can be displayed. Sample data to test this program can 
be found in the payroll.dat file located in the Chapter 8 programs folder 
on this book’s companion website.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Payroll.h"

using namespace std;

int main() {
    const int NUM_EMPLOYEES = 7;
    Payroll employees[NUM_EMPLOYEES];
    ifstream inputFile("payroll.dat");

    // Check file 
    if (!inputFile) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    // Read file for each employee and store in objects
    double hourlyRate, hoursWorked;
    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        inputFile >> hourlyRate >> hoursWorked;
    

        // Validate input 
        if (hourlyRate < 0 || hoursWorked < 0) {
            cerr << "Invalid data for employee " << (i + 1) << ". Please check input file.\n";
            return 1;
        }

        employees[i].setHourlyRate(hourlyRate);
        employees[i].setHoursWorked(hoursWorked);
    }

    inputFile.close();

    // Display gross pay for each employee 
    cout << fixed << setprecision(2);
    cout << "Employee Gross Pay Report\n";
    cout << "-------------------------\n";

    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        cout << "Employee " << (i + 1) << ": $" << employees[i].getGrossPay() << endl;
    }

    return 0;
}
