/*
  A soft drink company recently surveyed 16,500 of its customers and found that approximately
  15 percent of those surveyed purchase one or more energy drinks per week. Of those customers
  who purchase energy drinks, approximately 52 percent of them purchase citrus flavored drinks.

  Write a program that displays the following:
  - The approx number of customers in the survey who purchase one or more energy drinks per week.
  - The approx number of customers in the survey who purchase citrus flavored energy drinks.
*/

#include <iostream>

using namespace std;

const int TOTAL_SURVEYED = 16500;
const double ONE_PER_WEEK_PCT = 0.15;
const double CITRUS_FLAVORED_PCT = 0.52;

int main() 
{
  // Calculate customers who drink one or more per week
  int totalOncePerWeek = TOTAL_SURVEYED * ONE_PER_WEEK_PCT;
  
  // Calculate customer who purchase citrus flavored drinks
  int citrusDrinkers = TOTAL_SURVEYED * CITRUS_FLAVORED_PCT;

  // Display Results 
  cout << "Energy Drink Survey Results:\n"
       << "Total that drink one or more per week: " << totalOncePerWeek << endl
       << "Total that drink citrus flavored: " << citrusDrinkers;

  return 0;
}
