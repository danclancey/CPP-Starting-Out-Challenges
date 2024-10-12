#include <iostream>
#include <limits>
#include "PatientAccount.h"
#include "Surgery.h"
#include "Pharmacy.h"

using namespace std;

int main() {
    PatientAccount patient;
    Surgery surgery;
    Pharmacy pharmacy;

    int days, surgeryType, medicationType;
    char choice;

    // Input validation for the number of days
    while (true) {
        cout << "Enter the number of days the patient spent in the hospital (minimum 1): ";
        cin >> days;
        if (cin.fail() || days < 1) {
            cout << "Invalid input. Please enter a positive number for days.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }
    
    patient.setDaysInHospital(days);

    // Input validation for surgery selection
    while (true) {
        cout << "\nChoose a type of surgery (0-4):\n";
        cout << "0: Minor Surgery ($1500)\n";
        cout << "1: Major Surgery ($2500)\n";
        cout << "2: Critical Surgery ($3000)\n";
        cout << "3: Advanced Surgery ($4500)\n";
        cout << "4: Premium Surgery ($5000)\n";
        cin >> surgeryType;

        if (cin.fail() || surgeryType < 0 || surgeryType > 4) {
            cout << "Invalid input. Please select a valid surgery type (0-4).\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }

    // Apply surgery charge
    surgery.applySurgery(patient, surgeryType);

    // Medication selection with input validation
    do {
        while (true) {
            cout << "\nChoose a type of medication to add (0-4):\n";
            cout << "0: Medication A ($50)\n";
            cout << "1: Medication B ($75)\n";
            cout << "2: Medication C ($100)\n";
            cout << "3: Medication D ($150)\n";
            cout << "4: Medication E ($200)\n";
            cin >> medicationType;

            if (cin.fail() || medicationType < 0 || medicationType > 4) {
                cout << "Invalid input. Please select a valid medication type (0-4).\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
        }

        // Apply medication charge
        pharmacy.addMedication(patient, medicationType);

        // Ask if the user wants to add another medication
        cout << "Do you want to add another medication? (y/n): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N') {
            cout << "Invalid input. Please enter 'y' or 'n': ";
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    } while (choice == 'y' || choice == 'Y');

    // Display total charges when the patient checks out
    cout << "\nPatient's total charges: $" << patient.getTotalCharges() << endl;

    return 0;
}

