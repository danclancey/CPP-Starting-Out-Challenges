#ifndef STATS_H
#define STATS_H 

class Stats {
    private: 
        double values[30];
        int count;

    public:
        // Constructor
        Stats();

        // Functions
        bool storeValue(double value);
        double total() const;
        double average() const;
        int lowest() const;
        int highest() const;
        double getValue(int index) const;
        int getCount() const;
};

#endif 
