#ifndef PATIENTACCOUNT_H
#define PATIENTACCOUNT_H 

class PatientAccount {
    private:
        double totalCharges;
        double daysInHospital;
        static const double dailyRate;

    public:
          PatientAccount();
          void addCharges(double amt);
          void setDaysInHospital(int days);
          double getTotalCharges();
};

#endif 
