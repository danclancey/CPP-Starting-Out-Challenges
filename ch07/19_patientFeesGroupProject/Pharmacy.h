#ifndef PHARMACY_H
#define PHARMACY_H 

#include "PatientAccount.h"

class Pharmacy {
    private:
        double medA;
        double medB;
        double medC;
        double medD;
        double medE;

    public:
        Pharmacy();
        void addMedication(PatientAccount &account, int medType);
};

#endif 
