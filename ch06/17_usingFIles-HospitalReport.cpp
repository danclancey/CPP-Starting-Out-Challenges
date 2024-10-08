/*
Modify Programming Challenge 16, Overloaded Hospital, to write the report it creates to a file. Print the 
contents of the file to hand in to your instructor.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

// Function prototypes
double getValidatedInput(const string& prompt);
double calculateCharges(int days, double dailyRate, double serviceCharges, double medicationCharges);
double calculateCharges(double serviceCharges, double medicationCharges);

int main() {
    int numberOfDays;
    double dailyRate, serviceCharges, medicationCharges, totalCharges;
    char patientType;
    string filename;

    // Get the name of the file to write the report
    cout << "Enter the name of the file to save the report (e.g., hospital_report.txt): ";
    cin >> filename;

    // Open the output file
    ofstream outFile(filename);
    if (!outFile) {
        cout << "Error opening file. Please try again." << endl;
        return 1;  // Exit the program if the file cannot be opened
    }

    // Ask if the patient was admitted as an inpatient or an outpatient
    cout << "Was the patient admitted as an inpatient (I) or an outpatient (O)? ";
    cin >> patientType;
    patientType = toupper(patientType);  // Convert to uppercase for consistency

    if (patientType == 'I') {
        // Get input for inpatient data
        numberOfDays = static_cast<int>(getValidatedInput("Enter the number of days spent in the hospital: "));
        dailyRate = getValidatedInput("Enter the daily rate: $");
        serviceCharges = getValidatedInput("Enter the charges for hospital services (lab tests, etc.): $");
        medicationCharges = getValidatedInput("Enter the hospital medication charges: $");

        // Calculate total charges using the overloaded function for inpatients
        totalCharges = calculateCharges(numberOfDays, dailyRate, serviceCharges, medicationCharges);

        // Write the report to the file
        outFile << fixed << setprecision(2);
        outFile << "Patient Type: Inpatient\n";
        outFile << "Number of days: " << numberOfDays << "\n";
        outFile << "Daily rate: $" << dailyRate << "\n";
        outFile << "Service charges: $" << serviceCharges << "\n";
        outFile << "Medication charges: $" << medicationCharges << "\n";
        outFile << "Total charges: $" << totalCharges << "\n";
    } else if (patientType == 'O') {
        // Get input for outpatient data
        serviceCharges = getValidatedInput("Enter the charges for hospital services (lab tests, etc.): $");
        medicationCharges = getValidatedInput("Enter the hospital medication charges: $");

        // Calculate total charges using the overloaded function for outpatients
        totalCharges = calculateCharges(serviceCharges, medicationCharges);

        // Write the report to the file
        outFile << fixed << setprecision(2);
        outFile << "Patient Type: Outpatient\n";
        outFile << "Service charges: $" << serviceCharges << "\n";
        outFile << "Medication charges: $" << medicationCharges << "\n";
        outFile << "Total charges: $" << totalCharges << "\n";
    } else {
        cout << "Invalid input. Please run the program again and enter 'I' for inpatient or 'O' for outpatient." << endl;
        outFile.close();
        return 1;  // Exit the program with an error code
    }

    // Close the output file and confirm that the report has been written
    outFile.close();
    cout << "\nThe report has been saved to " << filename << endl;

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

