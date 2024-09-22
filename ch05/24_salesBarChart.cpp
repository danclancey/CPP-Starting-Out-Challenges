/*
Write a program that asks the user to enter today’s sales rounded to the nearest $100 
for each of three stores. The program should then produce a bar graph displaying each 
store’s sales. Create each bar in the graph by displaying a row of asterisks. Each 
asterisk should represent $100 of sales.

Here is an example of the program’s output. User input included 

        Enter today's sales for store 1: 1000[Enter]
        Enter today's sales for store 2: 1200[Enter]
        Enter today's sales for store 3: 900[Enter]
            DAILY SALES
          (each * = $100)
        Store 1: **********
        Store 2: ************
        Store 3: *********
*/

#include <iostream>

using namespace std;

int main() {
    int sales1, sales2, sales3;

    // Prompt for tbday's sales for each store
    cout << "Enter today's sales for store 1 (rounded to nearest $100): ";
    cin >> sales1;

    cout << "Enter today's sales for store 2 (rounded to nearest $100): ";
    cin >> sales2;

    cout << "Enter today's sales for store 3 (rounded to nearest $100): ";
    cin >> sales3;

    // Calculate the number of asterisks for each store's sales
    int stars1 = sales1 / 100;
    int stars2 = sales2 / 100;
    int stars3 = sales3 / 100;

    // Display the bar graph
    cout << "\n    DAILY SALES\n";
    cout << "  (each * = $100)\n";

    cout << "Store 1: ";
    for (int i = 0; i < stars1; i++) {
        cout << "*";
    }
    cout << endl;

    cout << "Store 2: ";
    for (int i = 0; i < stars2; i++) {
        cout << "*";
    }
    cout << endl;

    cout << "Store 3: ";
    for (int i = 0; i < stars3; i++) {
        cout << "*";
    }
    cout << endl;

    return 0;
}

