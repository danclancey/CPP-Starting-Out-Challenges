/*
  The following table lists the freezing and boiling points of several substances. Write a program that asks 
  the user to enter a temperature, and then shows all the substances that will freeze at that temperature 
  and all that will boil at that temperature. For example, if the user enters –20, the program should report 
  that water will freeze and oxygen will boil at that temperature.

        Substance	      Freezing Point (°F)	      Boiling Point (°F)
        Ethyl alcohol	  –173	                    172
        Mercury	        –38	                      676
        Oxygen	        –362	                    –306
        Water	          32	                      212
*/

#include <iostream>

using namespace std;

int main() {
    double temperature;

    // Ask the user to enter a temperature
    cout << "Enter a temperature in Fahrenheit: ";
    cin >> temperature;

    // Check for substances that will freeze at the given temperature
    cout << "At " << temperature << " degrees Fahrenheit:\n";
    
    if (temperature <= -173) {
        cout << "Ethyl alcohol will freeze.\n";
    }
    if (temperature <= -38) {
        cout << "Mercury will freeze.\n";
    }
    if (temperature <= -362) {
        cout << "Oxygen will freeze.\n";
    }
    if (temperature <= 32) {
        cout << "Water will freeze.\n";
    }

    // Check for substances that will boil at the given temperature
    if (temperature >= 172) {
        cout << "Ethyl alcohol will boil.\n";
    }
    if (temperature >= 676) {
        cout << "Mercury will boil.\n";
    }
    if (temperature >= -306) {
        cout << "Oxygen will boil.\n";
    }
    if (temperature >= 212) {
        cout << "Water will boil.\n";
    }

    return 0;
}

