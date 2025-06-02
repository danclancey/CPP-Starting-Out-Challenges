#ifndef INVBIN_H
#define INVBIN_H

#include <string>
using namespace std;

class InvBin {
private:
    string description;                     // Item name
    int qty;                                // Quantity of items in this bin

public:
    InvBin(string d = "empty", int q = 0);

    void setDescription(string d);
    string getDescription() const;
    void setQty(int q);
    int getQty() const;
};

#endif

