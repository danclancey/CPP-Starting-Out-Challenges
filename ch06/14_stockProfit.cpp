/*
The profit from the sale of a stock can be calculated as follows:

        Profit = ((NS * SP) - SC) - ((NS * PP) + PC)

    - where NS is the number of shares,
    - SP is the sale price per share,
    - SC is the sale commission paid,
    - PP is the purchase price per share,
    - and PC is the purchase commission paid.

If the calculation yields a positive value, then the sale of the stock resulted in a profit. If the 
calculation yields a negative number, then the sale resulted in a loss.

Write a function that accepts as arguments the number of shares, the purchase price per share, the purchase 
commission paid, the sale price per share, and the sale commission paid. The function should return the 
profit (or loss) from the sale of stock.

Demonstrate the function in a program that asks the user to enter the necessary data and displays the 
amount of the profit or loss.
*/

#include <iostream>
#include <iomanip>

using namespace std;

// Function prototype
double calculateProfit(int numberOfShares, double purchasePrice, double purchaseCommission, double salePrice, double saleCommission);

int main() {
    int numberOfShares;
    double purchasePrice, purchaseCommission, salePrice, saleCommission;

    // Get user input for the stock transaction details
    cout << "Enter the number of shares: ";
    cin >> numberOfShares;

    cout << "Enter the purchase price per share: $";
    cin >> purchasePrice;

    cout << "Enter the purchase commission paid: $";
    cin >> purchaseCommission;

    cout << "Enter the sale price per share: $";
    cin >> salePrice;

    cout << "Enter the sale commission paid: $";
    cin >> saleCommission;

    // Calculate the profit or loss
    double profitOrLoss = calculateProfit(numberOfShares, purchasePrice, purchaseCommission, salePrice, saleCommission);

    // Display the result
    cout << fixed << setprecision(2);
    if (profitOrLoss > 0) {
        cout << "\nYou made a profit of $" << profitOrLoss << endl;
    } else if (profitOrLoss < 0) {
        cout << "\nYou incurred a loss of $" << -profitOrLoss << endl;
    } else {
        cout << "\nYou broke even with no profit or loss." << endl;
    }

    return 0;
}

// Function to calculate the profit or loss from the stock sale
double calculateProfit(int numberOfShares, double purchasePrice, double purchaseCommission, double salePrice, double saleCommission) {
    double totalPurchaseCost = (numberOfShares * purchasePrice) + purchaseCommission;
    double totalSaleRevenue = (numberOfShares * salePrice) - saleCommission;
    return totalSaleRevenue - totalPurchaseCost;
}

