#ifndef BINMANAGER_H
#define BINMANAGER_H

#include "InvBin.h"
#include <string>

class BinManager {
private:
    InvBin bin[30];   // Array of InvBin objects
    int numBins;      // Number of bins currently in use

    // Helper function to convert a string to lowercase
    std::string toLowerCase(const std::string& str) const;

public:
    BinManager();                                     // Default constructor
    BinManager(int size, std::string d[], int q[]);   // 3-parameter constructor

    std::string getDescription(int index) const;      // Returns name of one item
    int getQuantity(int index) const;                 // Returns quantity of one item

    // Overloaded functions for managing bins by description
    int getQuantity(const std::string& itemDescription);          // Returns quantity based on description
    bool addParts(const std::string& itemDescription, int q);     // Adds parts based on description
    bool removeParts(const std::string& itemDescription, int q);  // Removes parts based on description

    bool addParts(int binIndex, int q);           // Adds parts to a bin
    bool removeParts(int binIndex, int q);        // Removes parts from a bin
};

#endif

