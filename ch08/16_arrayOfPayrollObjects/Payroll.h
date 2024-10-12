#ifndef PAYROLL_H
#define PAYROLL_H 

class Payroll {
    private:
        double hourlyRate;
        double hoursWorked;

    public:
        // Default constructor
        Payroll() : hourlyRate(0.0), hoursWorked(0.0) {}

        // Mutator functions
        void setHourlyRate(double rate) { hourlyRate = rate; }
        void setHoursWorked(double hours) { hoursWorked = hours; }

        // Accessor
        double getGrossPay() const { return hourlyRate * hoursWorked; }
};

#endif 
