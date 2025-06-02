/* 
Modify the program you wrote for Programming Challenge 15 so it stores the names in a vector of strings, 
rather than in an array of strings. Create the vector without specifying a size and then use the 
push_back member function to add an element holding each string to the vector as it is read in from a 
file. Instead of assuming there are always 20 strings, read in the strings and add them to the vector 
until there is no data left in the file. The data can be found in the names.dat file.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Function prototype
void selectionSort(vector<string>& vec);
void displayVector(const vector<string>& vec);
void readNamesFromFile(vector<string>& vec, const string& filename);

int main()
{
    vector<string> names;

    // Read names from the file
    readNamesFromFile(names, "names.dat");

    // Display the original list
    cout << "Original list of names:\n";
    displayVector(names);

    // Sort the vector
    selectionSort(names);

    // Display the sorted list
    cout << "\nSorted list of names:\n";
    displayVector(names);

    return 0;
}

// Function to read names from file and store in the vector
void readNamesFromFile(vector<string>& vec, const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error opening file: " << filename << endl;
        exit(1);  // Exit the program if the file cannot be opened
    }

    string name;
    // Read names from the file and add them to the vector
    while (getline(inputFile, name)) {
        vec.push_back(name);
    }

    inputFile.close();  // Close the file after reading
}

// Selection sort function for vector of strings
void selectionSort(vector<string>& vec)
{
    int minIndex;
    string minValue;

    for (size_t start = 0; start < vec.size() - 1; start++)
    {
        minIndex = start;
        minValue = vec[start];
        for (size_t index = start + 1; index < vec.size(); index++)
        {
            if (vec[index] < minValue) // Compare strings
            {
                minValue = vec[index];
                minIndex = index;
            }
        }
        // Swap the found minimum value with the current start position
        swap(vec[minIndex], vec[start]);
    }
}

// Function to display the vector
void displayVector(const vector<string>& vec)
{
    for (const auto& name : vec)
    {
        cout << name << endl;
    }
}

