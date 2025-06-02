#include "InvBin.h"

// Constructor with default values
InvBin::InvBin(string d, int q) {
    description = d;
    qty = q;
}

void InvBin::setDescription(string d) {
    description = d;
}

string InvBin::getDescription() const {
    return description;
}

void InvBin::setQty(int q) {
    qty = q;
}

int InvBin::getQty() const {
    return qty;
}


