/*
Write a program that computes and displays the charges for a patient’s hospital stay. First, the program 
should ask if the patient was admitted as an inpatient or an outpatient. If the patient was an inpatient, 
the following data should be entered:

    - The number of days spent in the hospital
    - The daily rate
    - Charges for hospital services (lab tests, etc.)
    - Hospital medication charges

If the patient was an outpatient, the following data should be entered:

    - Charges for hospital services (lab tests, etc.)
    - Hospital medication charges

Use a single, separate function to validate that no input is less than zero. If it is, it should be 
reentered before being returned.

Once the required data has been input and validated, the program should use two overloaded functions to 
calculate the total charges. One of the functions should accept arguments for the inpatient data, while the 
other function accepts arguments for outpatient data. Both functions should return the total charges.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Function prototypes
double getValidatedInput(const string& prompt);
double calculateCharges(int days, double dailyRate, double serviceCharges, double medicationCharges);
double calculateCharges(double serviceCharges, double medicationCharges);

int main() {
    char patientType;
    double totalCharges;

    // Ask if the patient was admitted as an inpatient or an outpatient
    cout << "Was the patient admitted as an inpatient (I) or an outpatient (O)? ";
    cin >> patientType;
    patientType = toupper(patientType);  // Convert to uppercase for consistency

    if (patientType == 'I') {
        // Get input for inpatient data
        int days = static_cast<int>(getValidatedInput("Enter the number of days spent in the hospital: "));
        double dailyRate = getValidatedInput("Enter the daily rate: $");
        double serviceCharges = getValidatedInput("Enter the charges for hospital services (lab tests, etc.): $");
        double medicationCharges = getValidatedInput("Enter the hospital medication charges: $");

        // Calculate total charges using the overloaded function for inpatients
        totalCharges = calculateCharges(days, dailyRate, serviceCharges, medicationCharges);
    } else if (patientType == 'O') {
        // Get input for outpatient data
        double serviceCharges = getValidatedInput("Enter the charges for hospital services (lab tests, etc.): $");
        double medicationCharges = getValidatedInput("Enter the hospital medication charges: $");

        // Calculate total charges using the overloaded function for outpatients
        totalCharges = calculateCharges(serviceCharges, medicationCharges);
    } else {
        cout << "Invalid input. Please run the program again and enter 'I' for inpatient or 'O' for outpatient." << endl;
        return 1;  // Exit the program with an error code
    }

    // Display the total charges
    cout << fixed << setprecision(2);
    cout << "\nThe total charges for the patient's stay are: $" << totalCharges << endl;

    return 0;
}

// Function to get and validate input (no value should be less than zero)
double getValidatedInput(const string& prompt) {
    double value;
    do {
        cout << prompt;
        cin >> value;
        if (value < 0) {
            cout << "Invalid input. Value cannot be negative. Please enter a valid amount.\n";
        }
    } while (value < 0);  // Repeat until a valid input is entered
    return value;
}

// Overloaded function to calculate total charges for inpatients
double calculateCharges(int days, double dailyRate, double serviceCharges, double medicationCharges) {
    return (days * dailyRate) + serviceCharges + medicationCharges;
}

// Overloaded function to calculate total charges for outpatients
double calculateCharges(double serviceCharges, double medicationCharges) {
    return serviceCharges + medicationCharges;
}

