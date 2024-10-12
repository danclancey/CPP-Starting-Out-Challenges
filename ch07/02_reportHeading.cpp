/*
Design a class called Heading that has data members to hold the company name and the report name. 
A two-parameter default constructor should allow these to be specified at the time a new Heading 
object is created. If the user creates a Heading object without passing any arguments, 
“ABC Industries” should be used as a default value for the company name and “Report” should be 
used as a default for the report name. The class should have member functions to print a heading 
in either one-line format, as shown here:

        Pet Pals Payroll Report

or in four-line “boxed” format, as shown here:

        ********************************************************
                            Pet Pals
                          Payroll Report
        ********************************************************
Try to figure out a way to center the headings on the screen, based on their lengths. Demonstrate 
the class by writing a simple program that uses it.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Heading {
    private:
        string companyName;
        string reportName;
    public:
        Heading();
        Heading(string c, string r);

        void print1LineHeading();
        void printBoxheading();

};

Heading::Heading() {
    companyName = "ABC Industries";
    reportName = "Report";
}

Heading::Heading(string c, string r) {
    companyName = c;
    reportName = r;
}

void Heading::print1LineHeading() {
    cout << companyName << " " << reportName << endl;
}

void Heading::printBoxheading() {
   int boxWidth = 40;

   // Print top border of box 
   cout << string(boxWidth, '*') << endl;

   // Center the company name and report within box 
   cout << setw((boxWidth + companyName.length()) / 2)  << companyName << endl;
   cout << setw((boxWidth + reportName.length()) / 2) << reportName << endl;

   // Print the bottom border of box 
   cout << string(boxWidth, '*') << endl;
}

int main() {
    string company;
    string report;

    // Get input for Company name and report name 
    cout << "Please enter the Company Name: ";
    getline(cin, company); 
    cout << "Please enter the Report Name: ";
    getline(cin, report);
    
    // Create heading object with user input
    Heading userHeading(company, report);

    // Display two different headings
    cout << "\nOne line Heading: \n";
    userHeading.print1LineHeading();
    cout << "\nBoxed Heading: \n";
    userHeading.printBoxheading();

    return 0;
}
