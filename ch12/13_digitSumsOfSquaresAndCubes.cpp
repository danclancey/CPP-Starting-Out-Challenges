/*
If you add up all the digits in 468, you get 4 + 6 + 8 = 18 The square and cube of 468 are 219024 and 102503232, respectively. 
Interestingly, if you add up the digits of the square or cube, you get 18 again. Are there other integers that share this property? 
Write a program that lists all positive integers k less than 1000 such that the three numbers k, k^2 and k^3 have digits that add up 
to the same number.
*/

#include <iostream>

using namespace std;

int sumDigits(long long n);

int main() {
    cout << "Integers k < 1000 such that k, k^2, and k^3 ahve the same sum of digits:\n";
    bool foundAny = false;

    for (int k = 1; k < 1000; ++k) {
        long long kLL = k;
        long long kSquared = kLL * kLL;
        long long kCubed = kLL * kLL * kLL;

        int sumK = sumDigits(kLL);
        int sumKSquared = sumDigits(kSquared);
        int sumKCubed = sumDigits(kCubed);

        if (sumK == sumKSquared && sumK == sumKCubed) {
            cout << "k = " << k << " (Sum: " << sumK << ")\n";
            foundAny = true;
        }

        if (!foundAny) {
            cout << "No integers found in specified range\n";
        }
    }

    return 0;
}

int sumDigits(long long n) {
    int sum = 0;
    if (n < 0) {
        n = -n;
    }
    if (n == 0) {
        return 0;
    }

    long long currentN = n;
    while (currentN > 0) {
        sum+= currentN % 10;
        currentN /= 10;
    }

    return sum;
}
