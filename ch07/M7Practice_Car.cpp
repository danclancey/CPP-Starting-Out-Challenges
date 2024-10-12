// Car Class
// This file defines a Car class and includes a client program
// that uses a Car object to simulate accelerating and breaking.
#include <iostream>
#include <string>
using namespace std;

// Car class declaration
class Car
{
    private:
        int year;       // Model year of the Car
        string make;    // Make of the Car
        int speed;      // Current speed of the car (mph)

    public:
        // Constructor with default parameters
        Car(int y=2010, string m = "Unknown")
        {   year = y;  
            make = m;
            speed = 0;  
        }

        // Accessors (i.e. "get" functions)
        int getYear()
        {   return year;    }

        string getMake()
        {   return make;    }

        int getSpeed()
        {   return speed;   }

        // Mutators
        void accelerate()
        {   speed += 5; }

        void brake()
        {   if (speed>= 5)
                speed -=5;
            else
                speed = 0;
        }
};

// ***** main *****
int main()
{
    Car hotRod(2010, "Mazda");   // Create a Car object

    // Describe the car (though this line was not requried by prob specs)
    cout << "I'm in my " << hotRod.getYear() << " "
         << hotRod.getMake() << " hot rod.\n\n";

    // Accelerate
    cout << "I'm accelerating ... \n\n";
    for (int faster = 1; faster <= 5; faster++)
    {
        hotRod.accelerate();
        cout << "Current speed: " << hotRod.getSpeed() << " mph. \n";

    }

    // Now stop
    cout << "\nNow I'm braking ... \n\n";
    for (int slower = 1; slower <= 5; slower++)
    {
        hotRod.brake();
        cout << "Current speed: " << hotRod.getSpeed() << " mph. \n";
    }
    cout << endl;
    return 0;
}