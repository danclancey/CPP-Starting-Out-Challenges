/* 
  Modify the program you wrote in Programming Challenge 22 so that it reports the number of pizzas you 
  need to buy for a party if each person attending is expected to eat an average of four slices. The 
  program should ask the user for the number of people who will be at the party and for the diameter of 
  the pizzas to be ordered. It should then calculate and display the number of pizzas to purchase. 
  Because it is impossible to buy a part of a pizza, the number of required pizzas should be displayed 
  as a whole number.
*/

#include <iostream>
using namespace std;

const double PI = 3.14;
const double SLICE_AREA = 14.125;
const int SLICES_PER_PERSON = 4;

int main() 
{
    int numPeople, numSlicesPerPizza;
    double diameter, radius, area;
    int numPizzas;

    // Welcome message and program description
    cout << "Welcome to Joe's Pizza Palace!" << endl;
    cout << "This program calculates the number of pizzas needed for a party based on the number of people attending." << endl << endl;

    // Get the number of people attending the party
    cout << "Enter the number of people attending the party: ";
    cin >> numPeople;

    // Get the diameter of the pizzas to be ordered
    cout << "Enter the diameter of the pizzas in inches: ";
    cin >> diameter;

    // Calculate the radius, area and number of slices per pizza
    radius = diameter / 2.0;
    area = PI * radius * radius;
    numSlicesPerPizza = area / SLICE_AREA;

    // Calculate the total number of slices needed
    int totalSlicesNeeded = numPeople * SLICES_PER_PERSON;

    // Calculate the number of pizzas needed
    numPizzas = (totalSlicesNeeded + numSlicesPerPizza - 1) / numSlicesPerPizza;

    // Display the number of pizzas to purchase
    cout << "For a party of " << numPeople << " people, you need to purchase " << numPizzas << " pizzas." << endl;

    return 0;
}

