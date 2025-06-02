/*
Write a program that displays a simulated paycheck. The program should ask the user to enter the date, the payee’s name, and the 
amount of the check. It should then display a simulated check with the dollar amount spelled out, as shown here:

                                        Date: 12/24/2016
Pay to the Order of: John Phillips              $1920.85
One thousand nine hundred twenty and 85 cents

You may assume the amount is no greater than $10000. Be sure to format the numeric value of the check in fixed-point notation with 
two decimal places of precision. Be sure the decimal place always displays, even when the number is zero or has no fractional part. 
Use either C-strings or string class objects in this program.
*/

#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // For formatting output (setprecision, fixed)
#include <cmath>   // For floor and round
#include <limits>  // For numeric_limits (used in input validation)
#include <algorithm> // For std::transform (used for capitalization)
#include <cctype>    // For toupper

// Arrays for converting numbers to words
const std::vector<std::string> ones = {
    "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
    "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
    "seventeen", "eighteen", "nineteen"
};

const std::vector<std::string> tens = {
    "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
};

// Function to convert a number less than 1000 to words
std::string convertLessThanOneThousand(int number) {
    std::string current;

    if (number >= 100) {
        current += ones[number / 100] + " hundred";
        number %= 100;
        if (number > 0) {
            current += " "; // Add space before tens/ones if needed
        }
    }

    if (number > 0) {
        if (number < 20) {
            current += ones[number];
        } else {
            current += tens[number / 10];
            if (number % 10 > 0) {
                current += " " + ones[number % 10];
            }
        }
    }
    return current;
}

// Function to convert the dollar amount (up to 10000) to words
std::string convertAmountToWords(int number) {
    if (number == 0) {
        return "zero";
    }
    if (number == 10000) {
        return "ten thousand";
    }

    std::string result;

    if (number >= 1000) {
        result += convertLessThanOneThousand(number / 1000) + " thousand";
        number %= 1000;
        if (number > 0) {
            result += " "; // Add space if there are hundreds/tens/ones following
        }
    }

    if (number > 0) {
        result += convertLessThanOneThousand(number);
    }

    return result;
}

// Function to capitalize the first letter of a string
std::string capitalizeFirstLetter(std::string s) {
    if (!s.empty()) {
        s[0] = std::toupper(s[0]);
    }
    return s;
}


int main() {
    std::string date;
    std::string payeeName;
    double amount = -1.0; // Initialize with an invalid value for validation loop

    // --- Get User Input ---
    std::cout << "Enter the date (e.g., MM/DD/YYYY): ";
    std::getline(std::cin, date); // Use getline for potential spaces if needed

    std::cout << "Enter the payee's name: ";
    std::getline(std::cin, payeeName);

    // Input validation loop for the amount
    while (true) {
        std::cout << "Enter the check amount (up to 10000.00): ";
        std::cin >> amount;

        // Check if input failed (e.g., non-numeric input)
        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a numeric value." << std::endl;
            std::cin.clear(); // Clear the error flag
            // Ignore the rest of the invalid input line
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            amount = -1.0; // Reset amount to ensure loop continues correctly
        }
        // Check if amount is within the valid range (0 to 10000 inclusive)
        else if (amount < 0.0 || amount > 10000.0) {
            std::cout << "Amount must be between 0.00 and 10000.00." << std::endl;
            // Clear potential leftover newline character from previous input
             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
             amount = -1.0; // Reset amount
        } else {
             // Clear potential leftover newline character from previous input
             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
             break; // Valid input, exit loop
        }
    }


    // --- Process Amount ---
    int dollars = static_cast<int>(std::floor(amount));
    // Use round to handle potential floating point inaccuracies for cents
    int cents = static_cast<int>(std::round((amount - dollars) * 100));

    // Convert dollar amount to words
    std::string amountInWords = convertAmountToWords(dollars);
    amountInWords = capitalizeFirstLetter(amountInWords); // Capitalize the first letter


    // --- Display Check ---
    std::cout << "\n\n--- Simulated Check ---" << std::endl;
    std::cout << std::setw(60) << std::right << "Date: " << date << std::endl; // Right align date

    // Set up formatting for the numerical amount
    std::cout << std::fixed << std::setprecision(2);

    // Print Payee line with amount aligned to the right
    std::cout << "Pay to the Order of: " << payeeName;
    // Calculate spacing for alignment (approximate)
    int spaces = 60 - (22 + payeeName.length() + 10); // 22 for "Pay...", 10 for $ amount approx
    if (spaces < 1) spaces = 1;
    std::cout << std::string(spaces, ' ') << "$" << amount << std::endl;

    // Print amount in words
    std::cout << amountInWords << " and " << std::setfill('0') << std::setw(2) << cents << "/100 dollars" << std::endl;
    // Alternative ending like the example:
    // std::cout << amountInWords << " and " << cents << (cents == 1 ? " cent" : " cents") << std::endl;

    std::cout << "-----------------------" << std::endl << std::endl;


    return 0;
}
