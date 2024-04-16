/* 
  Write a program that asks the user to enter their monthly costs for each of the
  following housing-related expenses:
    * rent or mortgage payment
    * phones
    * Internet service utilities
    * cable
    
  The program should then display the total monthly cost of these expenses and the
  total annual cost of these expenses.
*/

#include <iostream>
#include <iomanip>

using namespace std;

// Declare constant for year calculation
const int MONTHS_IN_YEAR = 12;

int main()
{
  // Declare variables
  double mortgageBill, phoneBill, ispBill, cableBill;
  double totalMonthlyExpenses, totalYearlyExpenses;
  // Greeting Screen
  cout << "Welcome to Dan's Expense Calculator\n";
  
  // Prompt user for monthly expenses
  cout << "Please enter your monthly expenses below..\n";
  cout << " - Mortgage: $";
  cin >> mortgageBill;
  
  cout << " - Phone Bill: $";
  cin >> phoneBill;

  cout << " - ISP Bill: $";
  cin >> ispBill;

  cout << " - Cable Bill: $";
  cin >> cableBill;

  // Calculate total monthly expenses
  totalMonthlyExpenses = mortgageBill + phoneBill + ispBill + cableBill;
  totalYearlyExpenses = totalMonthlyExpenses * MONTHS_IN_YEAR;

  // Format output
  cout << fixed << setprecision(2); 

  // Display Results
  cout << "\nYour total Monthly Expenses are: $" << totalMonthlyExpenses << endl;
  cout << "Your total Expenses for the year are: $" << totalYearlyExpenses;
  
  // Exit program
  cout << "\nGoodbye!\n";

  return 0;
}
