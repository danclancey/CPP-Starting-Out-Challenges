#include "Pharmacy.h"

// Constructor to init med costs 
Pharmacy::Pharmacy() {
    medA = 50.0;
    medB = 75.0;
    medC = 100.0;
    medD = 125.0;
    medE = 150.0;
}

// Apply med charge to patient acct
void Pharmacy::addMedication(PatientAccount &account, int medType) {
    switch(medType) {
        case 0:
            account.addCharges(medA);
            break;
        case 1:
            account.addCharges(medB);
            break;
        case 2:
            account.addCharges(medC);
            break;
        case 3:
            account.addCharges(medD);
            break;
        case 4:
            account.addCharges(medE);
            break;
        default:
            break; // No charge if invalid input
    }
}
