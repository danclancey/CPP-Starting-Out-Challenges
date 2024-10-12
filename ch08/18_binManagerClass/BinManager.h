#ifndef BINMANAGER_H
#define BINMANAGER_H

#include "InvBin.h"

class BinManager {
private:
    InvBin bin[30];                             // Array of InvBin objects
    int numBins;                                // Number of bins currently in use

public:
    BinManager(); // Default constructor
    BinManager(int size, string d[], int q[]);  // 3-parameter constructor

    string getDescription(int index) const;     // Returns name of one item
    int getQuantity(int index) const;           // Returns quantity of one item
    bool addParts(int binIndex, int q);         // Adds parts to a bin
    bool removeParts(int binIndex, int q);      // Removes parts from a bin
};

#endif

