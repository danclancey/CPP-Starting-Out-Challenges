#include "Stats.h"

// Constructor - Initialize count to "0"
Stats::Stats() : count(0) {}

// Store value in array if there is room 
bool Stats::storeValue(double value) {
    if (count < 30) {
        values[count] = value;
        count++;
        return true;
    } else {
        return false;   // Array full
    }
}

// Calc total of stored values 
double Stats::total() const {
    double sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += values[i];
    }
    return sum;
}

// Calc average of stored values 
double Stats::average() const {
    if (count == 0)
        return 0.0;   // Prevent division by zero
    return total() / count;
}

// Find index of lowest value 
int Stats::lowest() const {
    int lowestIndex = 0;
    for (int i = 1; i < count; i++) {
        if (values[i] < values[lowestIndex]) {
            lowestIndex = i;
        }
    }

    return lowestIndex;
}

// Find index of highest value 
int Stats::highest() const {
    int highestIndex = 0;
    for (int i = 1; i < count; i++) {
        if (values[i] > values[highestIndex]) {
            highestIndex = i;
        }
    }

    return highestIndex;
}

// Retrieve specific value by index 
double Stats::getValue(int index) const {
    return values[index];
}

// Return number of values stored 
int Stats::getCount() const {
    return count;
}
