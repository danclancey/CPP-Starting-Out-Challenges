#ifndef SURGERY_H
#define SURGERY_H

#include "PatientAccount.h"

class Surgery {
    private:
        double minorSurgery;
        double majorSurgery;
        double emergencySurgery;
        double electiveSurgery;
        double cosmeticSurgery;

    public:
        Surgery();
        void applySurgery(PatientAccount &account, int surgeryType);
};

#endif 
