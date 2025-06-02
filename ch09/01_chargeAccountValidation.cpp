/*
Write a program that lets the user enter a charge account number. The program should determine 
if the number is valid by checking for it in the following list:

    5658845	4520125	7895122	8777541	8451277	1302850
    8080152	4562555	5552012	5050552	7825877	1250255
    1005231	6545231	3852085	7576651	7881200	4581002

Initialize a one-dimensional array with these values. Then use a simple linear search to locate 
the number entered by the user. If the user enters a number that is in the array, the program 
should display a message saying the number is valid. If the user enters a number not in the 
array, the program should display a message indicating it is invalid.
*/

#include <iostream>
#include <iomanip>
using namespace std;

const int SIZE = 18; // Set size of the array

// Function Prototypes
int linearSearch(long [], int, long);
int binarySearch(long [], int, long);
void sortAccounts(long [], int);

int main()
{
    // Initialize accountNums array
    long accountNums[SIZE] = {8149420, 5333174, 3080098, 6755963, 9526981,
                              4449539, 9387197, 5104726, 2931356, 4282637,
                              1750219, 6086650, 3164838, 2419590, 4578589,
                              9718904, 6749941, 2545408};
    // Declare variables
    long userAccount;
    int index;

    // prompt user for their user account
    cout << "Please enter your account number: ";
    cin >> userAccount;

    // Call functions to search for account number.
    index = linearSearch(accountNums, SIZE, userAccount);
    if (index != -1)
        cout << "User Account found!\n - It is located at array[" << index << "].\n";
    else
        cout << "User Account does not exist!\n";

    return 0;
}

/**********************************************************************
 *                         linearSearch                               *
 * Called by  :  main                                                 *
 * Passed     : 3 arguments: an array of numbers, the size of that    *
 *              array, and the number to search for                   *
 * Purpose    : Determines if the number to search for is in the set  *
 *              of stored numbers and returns hte index location      *
 * Method     : Uses a linear search                                  *
 * Returns    : Index of the account if found, -1 if not found        *
***********************************************************************/
int linearSearch(long accountNums[], int SIZE, long userAcctNum)
{
    for (int count = 0; count < SIZE; count++)
    {
        if (accountNums[count] == userAcctNum)
            return count;
    }
    return -1;
}

