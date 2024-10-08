/*
The following formula can be used to determine the distance an object falls due to gravity in a specific time period:

                d = 1/2 * gt^2

The variables in the formula are as follows:
    d is the distance in meters,
    g is 9.8,
    and t is the time in seconds that the object has been falling.

Write a function named fallingDistance that accepts an object’s falling time (in seconds) as an argument. 
The function should return the distance, in meters, that the object has fallen during that time interval. 
Write a program that demonstrates the function by calling it in a loop that passes the values 1 through 
10 as arguments and displays the return value.
*/

#include <iostream>
#include <iomanip>

double fallingDistance (int seconds);

int main () {
    
    std::cout << std::fixed << std::setprecision(2);
    for (int i = 1; i <= 10; i++) {
        std::cout << i << " seconds : " << fallingDistance(i) << " meters\n";  
    }

    return 0;
}

double fallingDistance(int seconds) {
    return (1.0 / 2.0) * ( 9.8 * (seconds * seconds));
}
