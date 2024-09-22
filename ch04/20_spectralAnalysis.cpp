/*
  If a scientist knows the wavelength of an electromagnetic wave, she can determine what type of radiation 
  it is. Write a program that asks for the wavelength in meters of an electromagnetic wave and then 
  displays what that wave is according to the following chart. (For example, a wave with a wavelength of 
  1E-10 meters would be an X-ray.)

               1x10^-11       1x10^-8         4x10^-7       7x10^-7          7x10^-3        1x10^-2
   <--------------|--------------|--------------|--------------|---------------|--------------|-------------->
    Gamma rays        X-Rays       Ultraviolet    Visible Light    Infrared       Microwaves     Radio Waves
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double wavelength;

    // Ask the user to input the wavelength in meters
    cout << "Enter the wavelength of the electromagnetic wave (in meters): ";
    cin >> wavelength;

    // Determine the type of electromagnetic radiation based on wavelength
    if (wavelength < 1E-11) {
        cout << "The wave is a Gamma ray.\n";
    } else if (wavelength >= 1E-11 && wavelength < 1E-8) {
        cout << "The wave is an X-ray.\n";
    } else if (wavelength >= 1E-8 && wavelength < 4E-7) {
        cout << "The wave is Ultraviolet.\n";
    } else if (wavelength >= 4E-7 && wavelength < 7E-7) {
        cout << "The wave is Visible Light.\n";
    } else if (wavelength >= 7E-7 && wavelength < 1E-3) {
        cout << "The wave is Infrared.\n";
    } else if (wavelength >= 1E-3 && wavelength < 1E-2) {
        cout << "The wave is a Microwave.\n";
    } else if (wavelength >= 1E-2) {
        cout << "The wave is a Radio wave.\n";
    } else {
        cout << "Invalid wavelength.\n";
    }

    return 0;
}

