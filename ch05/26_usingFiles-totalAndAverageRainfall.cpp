/*
Write a program that reads in from a file a starting month name, an ending month name, and then 
the monthly rainfall for each month during that period. As it does this, it should sum the 
rainfall amounts and then report the total rainfall and average rainfall for the period. For 
example, the output might look like this:

    During the months of March–June, the total rainfall was 7.32 inches and the average monthly 
    rainfall was 1.83 inches.

Data for the program can be found in the rainfall.txt file located in the Chapter 5 programs 
folder on the book’s companion website.

**Hint**: After reading in the month names, you will need to read in rain amounts until the EOF 
is reached and count how many pieces of rain data you read in.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    ifstream inputFile("rainfall.txt");
    string startMonth, endMonth;
    double rainfall, totalRainfall = 0;
    int count = 0;

    // Check if file opened successfully
    if (!inputFile) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    // Read the starting and ending month
    inputFile >> startMonth;
    inputFile >> endMonth;

    // Read in the rainfall data and calc total and increment count
    while (inputFile >> rainfall) {
        totalRainfall += rainfall;
        count++;
    }

    // Close the file
    inputFile.close();

    // Calc average rainfall
    double averageRainfall = totalRainfall / count;

    // Display the results
    cout << fixed << setprecision(2);
    cout << "During the months of " << startMonth << "–" << endMonth << ", the total rainfall was "
         << totalRainfall << " inches and the average monthly rainfall was "
         << averageRainfall << " inches." << endl;

    return 0;
}

