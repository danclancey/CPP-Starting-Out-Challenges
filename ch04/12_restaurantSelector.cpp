/*
  A group of friends is coming to visit for your high school reunion. You want to take them out to eat 
  at a local restaurant, but you aren’t sure if any of them have dietary restrictions. Here are your 
  restaurant choices:

                            Vegetarian	            Vegan	            Gluten-Free
    Joe’s Gourmet Burgers	  No	                    No	              No
    Main Street Pizza	      Yes	                    No	              Yes
    Corner Café	            Yes	                    Yes	              Yes
    Mama’s Fine Italian	    Yes	                    No	              No
    The Chef’s Kitchen	    Yes	                    Yes	              Yes
 
  Write a program that asks whether any members of your party are vegetarian, vegan, or gluten-free, 
  and then displays only the restaurants where you can take the group. Here is an example of the 
  program’s output:

    Is anyone in your party a vegetarian (y/n)? y[Enter]

    Is anyone in your party a vegan (y/n)? n[Enter]

    Is anyone in your party gluten-free (y/n)? y[Enter]

    Here are your restaurant choices:

    Main Street Pizza Corner Cafe The Chef’s Kitchen
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string isVegetarian, isVegan, isGlutenFree;
    string matchingRestaurants = "";

    cout << "Welcome to Dan's Restaurant Selector!\n";
    cout << "-------------------------------------\n\n";
    cout << "This program will output restaurants based on dietary restrictions.\n\n";

    // Ask for dietary restrictions
    cout << "Is anyone in your party vegetarian (y/n)? ";
    cin >> isVegetarian;
    cout << "Is anyone in your party vegan (y/n)? ";
    cin >> isVegan;
    cout << "Is anyone in your party gluten-free (y/n)? ";
    cin >> isGlutenFree;

    // Determine matching restaurants
    if (isVegetarian == "n" && isVegan == "n" && isGlutenFree == "n")
    {
        matchingRestaurants += "Joe's Gourmet Burgers\n";
    }
    if (isVegan == "n")
    {
        matchingRestaurants += "Main Street Pizza\n";
    }
    if (isVegan == "n" && isGlutenFree == "n")
    {
        matchingRestaurants += "Mama's Fine Italian\n";
    }
    matchingRestaurants += "Corner Cafe\n";
    matchingRestaurants += "The Chef's Kitchen\n";

    // Display Results
    cout << "\nHere are your restaurant choices:\n\n";
    cout << matchingRestaurants << endl;

    return 0;
}

