#include "BinManager.h"
#include <iostream>

#include "BinManager.h"
#include <iostream>

// Default constructor
BinManager::BinManager() {
    numBins = 0;
}

// 3-parameter constructor
BinManager::BinManager(int size, string d[], int q[]) {
    numBins = size;
    for (int i = 0; i < numBins; i++) {
        bin[i] = InvBin(d[i], q[i]);
    }
}

string BinManager::getDescription(int index) const {
    if (index >= 0 && index < numBins) {
        return bin[index].getDescription();
    } else {
        return "Invalid index";
    }
}

int BinManager::getQuantity(int index) const {
    if (index >= 0 && index < numBins) {
        return bin[index].getQty();
    } else {
        return -1;                              // Indicating an invalid index
    }
}

bool BinManager::addParts(int binIndex, int q) {
    if (binIndex >= 0 && binIndex < numBins && q > 0) {
        int newQty = bin[binIndex].getQty() + q;
        bin[binIndex].setQty(newQty);
        return true;
    }
    return false;
}

bool BinManager::removeParts(int binIndex, int q) {
    if (binIndex >= 0 && binIndex < numBins && q > 0 && bin[binIndex].getQty() >= q) {
        int newQty = bin[binIndex].getQty() - q;
        bin[binIndex].setQty(newQty);
        return true;
    }
    return false;
}

