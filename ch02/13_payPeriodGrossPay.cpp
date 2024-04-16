/* 
  A particular employee earns $39,000 anually. Write a program that determines
  and displays what the amount of his gross pay will be for each pay period if
  he is paid twice a month (24 pay checks per year) and if he is paid bi-weekly
  (26 checks per year)
*/

#include <iostream>
#include <iomanip>

using namespace std;

// declare constant for annual pay
const double ANNUAL_PAY = 39000;

int main() 
{
  // Display pay per paycheck
  cout << "Gross Paycheck Calculator for $39,000/yr\n";
  cout << fixed << setprecision(2);
  cout << "If paid twice a month: $" << ANNUAL_PAY / 24 << " per paycheck\n";
  cout << "If paid bi-weekly: $" << ANNUAL_PAY / 26 << " per paycheck\n";

  return 0;
}
