/*
  Movie theaters often make more money on food and drink sales than they do on ticket sales. One particular theater charges 
  $10 for tickets to evening shows and just $3 for kiddie matinees. They have discovered that the average evening patron 
  spends $6.50 on concessions and the average matinee patron spends $8.50 on concessions.

  Write a program that computes and displays what percent of evening show income and what percent of matinee show income 
  comes from ticket sales and what percent comes from concession stand purchases.
*/

#include <iostream>
#include <iomanip>

using namespace std;

// Declare constants
const double EVENING_TICKET = 10;
const double KIDDIE_MATINEE_TICKET = 3;
const double AVG_EVENING_CONCESSION = 6.50;
const double AVG_MATINEE_CONCESSION = 8.50;

int main() 
{
  
  // calculate avgerage amount patron spends in evening and matinee
  double avgEveningSales = EVENING_TICKET + AVG_EVENING_CONCESSION;
  double avgMatineeSales = KIDDIE_MATINEE_TICKET + AVG_MATINEE_CONCESSION;
  
  // calculate percentage of ticket and concession sales for evening
  double pctEveningTicketSales = EVENING_TICKET / avgEveningSales;
  double pctEveningConcessionSales = AVG_EVENING_CONCESSION / avgEveningSales;

  // calculate percentage of ticket and concession sales for matinee
  double pctMatineeTicketSales = KIDDIE_MATINEE_TICKET / avgMatineeSales;
  double pctMatineeConcessionSales = AVG_MATINEE_CONCESSION / avgMatineeSales;

  // display results
  cout << "Welcome to Dan's Theater Sales Caculator!\n\n";
  cout << "This program will calculate the percentage of evening show income\n"
       << "and what percent of matinee show income comes from ticket sales\n"
       << "and what percent comes from concession stand purchases.\n\n";
  cout << "Evening Ticket Price: $" << fixed << setprecision(2) << EVENING_TICKET << endl
       << "Matinee Ticket Price: $" << KIDDIE_MATINEE_TICKET << endl
       << "Evening Concession Sales Per Patron: $" << AVG_EVENING_CONCESSION << endl
       << "Matinee Concession Sales per Patron: $" << AVG_MATINEE_CONCESSION << endl << endl;
  cout << "Percent of Evening Sales from Tickets: " << pctEveningTicketSales * 100 << "%\n"
       << "Percent of Evening Sales from Concessions: " << pctEveningConcessionSales * 100 << "%\n"
       << "Percent of Matinee Sales from Tickets: " << pctMatineeTicketSales * 100 << "%\n"
       << "Percent of Matinee Sales from Concessions: " << pctMatineeConcessionSales * 100 << "%\n";

  return 0;

}
