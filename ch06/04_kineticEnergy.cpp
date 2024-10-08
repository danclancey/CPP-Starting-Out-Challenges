/*
In physics, an object that is in motion is said to have kinetic energy. The following formula can be 
used to determine a moving object’s kinetic energy:

                KE = 1/2 * mv^2

The variables in the formula are as follows:
    KE is the kinetic energy in joules,
    m is the object’s mass in kilograms,
    and v is the object’s velocity in meters per second.

Write a function named kineticEnergy that accepts an object’s mass (in kilograms) and velocity 
(in meters per second) as arguments. The function should return the amount of kinetic energy that the 
object has. Demonstrate the function by calling it in a program that asks the user to enter values 
for mass and velocity.
*/

#include <iostream>
#include <iomanip>

double kineticEnergy (double mass, double velocity);

int main() {
    double mass, velocity;

    do {
        std::cout << "Please enter object mass (in kilograms): ";
        std::cin >> mass;

        if (mass < 0) {
          std::cout << "Mass cannot be negative. Please enter a valid value.\n";
        }
    } while (mass < 0);

    do {
        std::cout << "Please enter object velocity (in meters per second): ";
        std::cin >> velocity;
        if (velocity < 0) {
            std::cout << "Velocity cannot be negative. Please enter a valid value: \n";
        }
    } while (velocity < 0);

    // Output result - fixed to two decimal places
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "The object's kinetic energy is " << kineticEnergy(mass, velocity) << " joules.\n";

    return 0;
}

double kineticEnergy (double mass, double velocity) {
    return (1.0 / 2.0) * (mass * (velocity * velocity));
}
