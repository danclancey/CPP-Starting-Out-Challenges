#include "BinManager.h"
#include <algorithm> // For std::transform
#include <cctype>    // For std::tolower

// Default constructor
BinManager::BinManager() {
    numBins = 0;
}

// 3-parameter constructor
BinManager::BinManager(int size, std::string d[], int q[]) {
    numBins = size;
    for (int i = 0; i < numBins; i++) {
        bin[i] = InvBin(d[i], q[i]);
    }
}

// Helper function to convert string to lowercase
std::string BinManager::toLowerCase(const std::string& str) const {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

// Overloaded function to get quantity based on item description
int BinManager::getQuantity(const std::string& itemDescription) {
    std::string lowerDescription = toLowerCase(itemDescription); // Convert to lowercase
    for (int i = 0; i < numBins; i++) {
        if (toLowerCase(bin[i].getDescription()) == lowerDescription) {
            return bin[i].getQty();
        }
    }
    return -1; // Item description not found
}

// Overloaded function to add parts based on item description
bool BinManager::addParts(const std::string& itemDescription, int q) {
    std::string lowerDescription = toLowerCase(itemDescription); // Convert to lowercase
    for (int i = 0; i < numBins; i++) {
        if (toLowerCase(bin[i].getDescription()) == lowerDescription) {
            if (q > 0) {
                int newQty = bin[i].getQty() + q;
                bin[i].setQty(newQty);
                return true;
            }
        }
    }
    return false; // Item description not found or invalid quantity
}

// Overloaded function to remove parts based on item description
bool BinManager::removeParts(const std::string& itemDescription, int q) {
    std::string lowerDescription = toLowerCase(itemDescription); // Convert to lowercase
    for (int i = 0; i < numBins; i++) {
        if (toLowerCase(bin[i].getDescription()) == lowerDescription) {
            if (q > 0 && bin[i].getQty() >= q) {
                int newQty = bin[i].getQty() - q;
                bin[i].setQty(newQty);
                return true;
            }
        }
    }
    return false; // Item description not found, invalid quantity, or insufficient stock
}

// Function to get description by index
std::string BinManager::getDescription(int index) const {
    if (index >= 0 && index < numBins) {
        return bin[index].getDescription();
    } else {
        return "Invalid index";
    }
}

// Function to get quantity by index
int BinManager::getQuantity(int index) const {
    if (index >= 0 && index < numBins) {
        return bin[index].getQty();
    } else {
        return -1;                              // Invalid index
    }
}

// Function to add parts by index
bool BinManager::addParts(int binIndex, int q) {
    if (binIndex >= 0 && binIndex < numBins && q > 0) {
        int newQty = bin[binIndex].getQty() + q;
        bin[binIndex].setQty(newQty);
        return true;
    }
    return false;
}

// Function to remove parts by index
bool BinManager::removeParts(int binIndex, int q) {
    if (binIndex >= 0 && binIndex < numBins && q > 0 && bin[binIndex].getQty() >= q) {
        int newQty = bin[binIndex].getQty() - q;
        bin[binIndex].setQty(newQty);
        return true;
    }
    return false;
}

