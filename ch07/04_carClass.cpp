/*
Write a class named Car that has the following member variables:

    - year: An int that holds the car’s model year.
    - make: A string object that holds the make of the car.
    - speed: An int that holds the car’s current speed.

In addition, the class should have the following member functions.

    - Constructor:  The constructor should accept the car’s year and make as arguments 
                    and assign these values to the object’s year and make member 
                    variables. The constructor should initialize the speed member 
                    variable to 0.
    - Accessors:    Appropriate accessor functions should be created to allow values to 
                    be retrieved from an object’s year, make, and speed member variables.
    - accelerate:   The accelerate function should add 5 to the speed member variable 
                    each time it is called.
    - brake:        The brake function should subtract 5 from the speed member variable 
                    each time it is called.

Demonstrate the class in a program that creates a Car object and then calls the accelerate 
function five times. After each call to the accelerate function, get the current speed of 
the car and display it. Then, call the brake function five times. After each call to the 
brake function, get the current speed of the car and display it.
*/

#include <iostream>
#include <string>

using namespace std;

class Car {
    private:
        int year, speed;
        string make;
        
    public:
        // Constructor 
        Car(int y, string m) { 
            year = y; 
            make = m; 
            speed = 0; 
        }

        // Accessors
        int getYear() { return year; }
        string  getMake() { return make; }
        int getSpeed() { return speed; }

        // Helper functions to accelerate and brake
        void accelerate() { speed += 5; }
        void brake() {
            if (speed >= 5) 
                speed -= 5;
            else 
                speed = 0;
        }
};

int main() {
    Car myCar(2022, "Honda Civic");

    cout << "Make: " << myCar.getMake() << endl;
    cout << "Year: " << myCar.getYear() << endl << endl;

    // Accelerate 5 times and display speed each iteration
    for (int i = 0; i < 5; i++) {
        myCar.accelerate();
        cout << "Speed after acceperating: " << myCar.getSpeed() << " mph\n";
    }

    // line break for readability
    cout << endl;

    // Brake 5 times and display speed each iteration
    for (int i = 0; i < 5; i++) {
        myCar.brake();
        cout << "Speed after braking: " << myCar.getSpeed() << " mph\n";
    }

    return 0;
}
