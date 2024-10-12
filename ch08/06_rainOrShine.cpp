/*
An amateur meteorologist wants to keep track of weather conditions 
during the past year’s three-month summer season and has designated 
each day as either rainy (‘R’), cloudy (‘C’), or sunny (‘S’). Write 
a modular program that stores this information in a 3 x 30  array of 
characters, where the row indicates the month (0=June, 1=July, 2=August)
and the column indicates the day of the month. Note that data is not 
being collected for the 31st of any month. The program should begin by 
calling a function to read the weather data in from a file. Then it 
should create a report that displays for each month and for the whole 
three-month period, how many days were rainy, how many were cloudy, and 
how many were sunny. To help it do this, it should use a value-returning 
function that is passed the array, the number of the month to examine, 
and the character to look for (‘R’, ‘C’, or ‘S’). This function should 
return the number of days the indicated month had the requested weather. 
Data for the program can be found in the rain_or_shine.dat file located 
in the Chapter 8 programs folder on this book’s companion website
*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int NUM_DAYS = 30;
const int NUM_MONTHS = 3;

// Function prototypes
void readWeatherData(char weather[][NUM_DAYS], const string& filename);
int countWeatherDays(const char weather[][NUM_DAYS], int month, char condition);
void displayReport(const char weather[][NUM_DAYS]);

int main() {
    char weather[NUM_MONTHS][NUM_DAYS];

    // Read weather data from file into the array
    readWeatherData(weather, "rain_or_shine.dat");

    // Display the report based on the read data
    displayReport(weather);

    return 0;
}

// Function to read weather data from a file into the 2D array
void readWeatherData(char weather[][NUM_DAYS], const string& filename) {
    ifstream file(filename);  // Open the file for reading
    if (!file) {
        // Check if the file opened successfully
        cerr << "Error opening file " << filename << endl;
        exit(EXIT_FAILURE);  // Exit if the file can't be opened
    } else {
        // Read data for each month and each day
        for (int currMonth = 0; currMonth < NUM_MONTHS; ++currMonth) {
            for (int currDay = 0; currDay < NUM_DAYS; ++currDay) {
                file >> weather[currMonth][currDay];

                // Validate that the input is one of 'R', 'C', or 'S'
                while (weather[currMonth][currDay] != 'R' &&
                       weather[currMonth][currDay] != 'C' &&
                       weather[currMonth][currDay] != 'S') {
                    cerr << "Invalid weather data in file. Expected 'R', 'C', or 'S'. Exiting." << endl;
                    exit(EXIT_FAILURE);  // Exit if the data is invalid
                }
            }
        }
    }
    file.close();  // Close the file after reading
}

// Function to count the number of days with a specific weather condition in a given month
int countWeatherDays(const char weather[][NUM_DAYS], int month, char condition) {
    int count = 0;  // Counter for the specified weather condition
    for (int day = 0; day < NUM_DAYS; ++day) {
        if (weather[month][day] == condition) {
            count++;  // Increment the counter if the condition matches
        }
    }
    return count;  // Return the total count of the specified condition
}

// Function to display the weather report for each month and overall
void displayReport(const char weather[][NUM_DAYS]) {
    const string monthNames[] = {"June", "July", "August"};  // Names of the months
    int totalRainy = 0, totalCloudy = 0, totalSunny = 0;  // Counters for overall conditions

    cout << "\nWeather Report:\n";
    cout << "---------------------------\n";

    // Loop through each month to calculate and display the weather data
    for (int month = 0; month < NUM_MONTHS; ++month) {
        int rainy = countWeatherDays(weather, month, 'R');   // Count rainy days for the month
        int cloudy = countWeatherDays(weather, month, 'C');  // Count cloudy days for the month
        int sunny = countWeatherDays(weather, month, 'S');   // Count sunny days for the month

        // Update the totals for the entire period
        totalRainy += rainy;
        totalCloudy += cloudy;
        totalSunny += sunny;

        // Display the report for the current month
        cout << "Month: " << setw(6) << monthNames[month] << endl;
        cout << " - Rainy Days:  " << setw(2) << rainy << endl;
        cout << " - Cloudy Days: " << setw(2) << cloudy << endl;
        cout << " - Sunny Days:  " << setw(2) << sunny << endl;
        cout << endl;
    }

    // Display the overall weather report for the entire period
    cout << "Overall Report:\n";
    cout << " - Total rainy days:  " << totalRainy << endl;
    cout << " - Total cloudy days: " << totalCloudy << endl;
    cout << " - Total sunny days:  " << totalSunny << endl;
}

