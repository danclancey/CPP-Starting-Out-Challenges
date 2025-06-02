/*
Write a class whose constructor takes a vector of Student objects, where each Student has a name of type string and a score of type int. 
The class internally stores the data passed to it in its constructor. The class should have an overloaded output operator that outputs 
its data in the form of an HTML table. Make up suitable input and use it to test your class.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Student class
class Student {
public:
    string name;
    int score;

    // Constructor
    Student(string n, int s) : name(n), score(s) {}
};

// Class to manage students and generate HTML table
class StudentHTMLTable {
private:
    vector<Student> students;  // Stores Student objects

public:
    // Constructor that takes a vector of Student objects
    StudentHTMLTable(const vector<Student>& s) : students(s) {}

    // Overloaded output operator to generate an HTML table
    friend ostream& operator<<(ostream& out, const StudentHTMLTable& table);
};

// Overloaded output operator
ostream& operator<<(ostream& out, const StudentHTMLTable& table) {
    out << "<html>\n<head>\n<title>Student Scores</title>\n</head>\n<body>\n";
    out << "<table border='1' style='border-collapse: collapse;'>\n";
    out << "<tr><th>Name</th><th>Score</th></tr>\n";
    for (const Student& student : table.students) {
        out << "<tr><td>" << student.name << "</td><td>" << student.score << "</td></tr>\n";
    }
    out << "</table>\n</body>\n</html>\n";
    return out;
}

int main() {
    // Create a vector of Student objects
    vector<Student> students = {
        Student("Dan", 99),
        Student("Nikki", 95),
        Student("Shane", 85),
        Student("Kristin", 88),
        Student("Tim", 92)
    };

    // Create a StudentHTMLTable object
    StudentHTMLTable htmlTable(students);

    // Output the HTML table
    cout << htmlTable;

    return 0;
}

