/*
Design a class for a widget manufacturing plant. Assuming that 10 widgets may be produced 
each hour, the class object will calculate how many days it will take to produce any 
number of widgets. (The plant operates two 8-hour shifts per day.) Write a program that 
asks the user for the number of widgets that have been ordered and then displays the number 
of days it will take to produce them. Think about what values your program should accept 
for the number of widgets ordered.
*/

#include <iostream>

using namespace std;

class WidgetFactory {
    private:
        int widgets;
        const int WIDGETS_PER_HOUR = 10;
        const int OPERATING_HOURS = 16;
        
        // Function to calc days to produce widgets 
        int calculateDays(int widgets);

    public:
        WidgetFactory();
        WidgetFactory(int w);

        void displayDays();
};

// Default constructor, no widgets produced 
WidgetFactory::WidgetFactory() : widgets(0) {}

// Parameterized Cosntructor 
WidgetFactory::WidgetFactory(int w) {
    if (w < 0) {
        cout << "Invalid number of widgets. Setting to 0.\n";
        widgets = 0;
    } else {
        widgets = w;
    }
}

// Function to calculate days to produce widgets 
int WidgetFactory::calculateDays(int w) {
    int widgetsPerDay = OPERATING_HOURS * WIDGETS_PER_HOUR;
    int days = w / widgetsPerDay;

    if (w % widgetsPerDay != 0)
        days++; // Add one day for remaining widgets  
    
    return days;
}

// Function to display amount of days 
void WidgetFactory::displayDays() {
    cout << "\nIt will take " << calculateDays(widgets) << " days to "
         << "manufacture " << widgets << " widgets.\n";
}

int main() {
    int userWidgets;

    cout << "Please enter number of widgets: ";
    cin >> userWidgets;

    WidgetFactory widgetFactory(userWidgets);
    widgetFactory.displayDays();

    return 0;

}
