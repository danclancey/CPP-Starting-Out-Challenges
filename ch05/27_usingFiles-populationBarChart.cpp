/*
Write a program that produces a bar chart showing the population growth of Prairieville, a small 
town in the Midwest, at 20-year intervals during the past 100 years. The program should read in 
the population figures (rounded to the nearest 1,000 people) for 1910, 1930, 1950, 1970, 1990, 
and 2010 from a file. For each year it should display the date and a bar consisting of one asterisk 
for each 1,000 people. The data can be found in the people.txt file located in the Chapter 5 
programs folder on the book’s companion website.

Here is an example of how the chart might begin:

        PRAIRIEVILLE POPULATION GROWTH
        (each * represents 1000 people)
        1910  **
        1930  ****
        1950  *****
*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    ifstream inputFile("people.txt");
    int population;
    int years[] = {1910, 1930, 1950, 1970, 1990, 2010};  // The years of population data
    int index = 0;

    // Check if the file opened successfully
    if (!inputFile) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    // Display header for the population bar chart
    cout << "PRAIRIEVILLE POPULATION GROWTH\n";
    cout << "(each * represents 1000 people)\n";

    // Read population data and display the bar chart
    while (inputFile >> population) {
        cout << years[index] << "  ";  // Display the year

        // Display asterisks representing population (1 asterisk = 1000 people)
        for (int i = 0; i < population / 1000; i++) {
            cout << "*";
        }

        cout << endl;
        index++;
    }

    // Close the file
    inputFile.close();

    return 0;
}

