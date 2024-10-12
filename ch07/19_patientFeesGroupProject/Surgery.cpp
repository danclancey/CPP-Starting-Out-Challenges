#include "Surgery.h"

// Constructor to init surgery costs
Surgery::Surgery() {
    minorSurgery = 1500.0;
    majorSurgery = 2500.0;
    emergencySurgery = 3000.0;
    electiveSurgery = 4500.0;
    cosmeticSurgery = 5000.0;
}

// Apply surgery charges to patient acct
void Surgery::applySurgery(PatientAccount &account, int surgeryType) {
    switch (surgeryType) {
        case 0:
            account.addCharges(minorSurgery);
            break;
        case 1:
            account.addCharges(majorSurgery);
            break;
        case 2:
            account.addCharges(emergencySurgery);
            break;
        case 3:
            account.addCharges(electiveSurgery);
            break;
        case 4:
            account.addCharges(cosmeticSurgery);
            break;
        default:
            break; // No charge if invalid input
    }
}
