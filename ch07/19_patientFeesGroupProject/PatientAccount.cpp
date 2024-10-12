#include "PatientAccount.h"

// Init daily rate
const double PatientAccount::dailyRate = 500.0;

// Constructor - Init total charges and days in hospital
PatientAccount::PatientAccount() {
    totalCharges = 0.0;
    daysInHospital = 0;
}

// Add charges to total 
void PatientAccount::addCharges(double amt) {
    totalCharges += amt;
}

// Set num of days in hospital and calc daily charges 
void PatientAccount::setDaysInHospital(int days) {
    daysInHospital = days;
    totalCharges += daysInHospital * dailyRate;
}

// Get total charges for patient 
double PatientAccount::getTotalCharges() {
    return totalCharges;
}
