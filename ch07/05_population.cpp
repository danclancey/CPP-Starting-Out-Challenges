/*
In a population, the birth rate and death rate are calculated as follows:

        Birth Rate = Number of Births / Population
        Death Rate = Number of Deaths / Population
 
For example, in a population of 100,000 that has 5,000 births and 2,000 deaths per year,

        Birth Rate = 5000 / 100000 = 0.05
        Death Rate = 2000 / 100000 = 0.02
 
Design a Population class that stores a current population, annual number of births, and 
annual number of deaths for some geographic area. The class should allow these three values 
to be set in either of two ways: by passing arguments to a three-parameter constructor when 
a new Population object is created or by calling the setPopulation, setBirths, and setDeaths 
class member functions. In either case, if a population figure less than 2 is passed to the 
class, use a default value of 2. If a birth or death figure less than 0 is passed in, use a 
default value of 0. The class should also have getBirthRate and getDeathRate functions that 
compute and return the birth and death rates. Write a short program that uses the Population 
class and illustrates its capabilities.
*/

#include <iostream>
#include <iomanip>

using namespace std;

class Population {
    private:
        int population;
        int births;
        int deaths;

    public:
        // Constructors
        Population(int pop, int b, int d);
        Population();

        // Mutator functions 
        void setPopulation(int pop);
        void setBirths(int b);
        void setDeaths(int d);

        // Accessor functions 
        double getBirthRate();
        double getDeathRate();
};

// Param Constructor 
Population::Population(int pop, int b, int d) {
    setPopulation(pop);
    setBirths(b);
    setDeaths(d);
}

// Default constructor
Population::Population() {
    population = 2;
    births = 0;
    deaths = 0;
}

// Setter functions with validation
void Population::setPopulation(int pop) {
    if (pop < 2) {
        population = 2;
    } else {
        population = pop;
    }
}

void Population::setBirths(int b) {
    if (b < 0) {
        births = 0;
    } else {
        births = b;
    }
}

void Population::setDeaths(int d) {
    if(d < 0) {
        deaths = 0;
    } else {
        deaths = d;
    }
}

// Getter Functions to calc birth and death rates 
double Population::getBirthRate() {
    return static_cast<double>(births) / population;
}

double Population::getDeathRate() {
    return static_cast<double>(deaths) / population;
}

int main() {
    int pop, b, d;

    // Get user input for pop, births, deaths 
    cout << "Enter the current population: ";
    cin >> pop;
    cout << "Enter the annual number of births: ";
    cin >> b;
    cout << "Enter the annual number of deaths: ";
    cin >> d;

    // Create Population object 
    Population myPop(pop, b, d);

    // Set to 2 decimal places
    cout << fixed << setprecision(2);

    // Display birth rate and death rate 
    cout << "\nBirth Rate: " << myPop.getBirthRate() << endl;
    cout << "Death Rate: " << myPop.getDeathRate() << endl;

    // Modify pop and display updated rates 
    myPop.setPopulation(1500);
    myPop.setBirths(30);
    myPop.setDeaths(10);

    cout << "Modified population data: \n";
    cout << "Birth Rate: " << myPop.getBirthRate() << endl;
    cout << "Death Rate: " << myPop.getDeathRate() << endl;

    return 0;
}
