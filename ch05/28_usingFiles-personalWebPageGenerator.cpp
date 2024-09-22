/*
Write a program that asks the user for their name, a sentence or two that describes 
themself, and a title for the web page. Here is an example of the program’s screen:


        Enter your name:  Julie Taylor [Enter]
        Describe yourself:  I am a Comp. Sci. major and a member of the Jazz Club. 
                            I hope to be a mobile app developer some day. [Enter]
        Enter a title for your web page:  About Me [Enter]

Once the user has entered the requested input, the program should create an output 
file named the same as the user’s title, with the extension html. In this case the 
file that the program creates would be named About Me.html. Here is an example of 
the file contents your program should generate using the sample input previously 
shown. After your program runs, the html file can be opened in a browser to display 
a simple web page.


        <html>
        <head>
          <title>About Me</title>
        </head>
        <body>
          <center>
          <h1>Julie Taylor</h1>
          </center>
          <hr>
          I am a Comp Sci. major and a member of the Jazz Club. I hope to be a mobile app developer some day.
          <hr>
        </body>
        </html>
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string name, description, title;

    // Prompt for name, description, and title
    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Describe yourself: ";
    getline(cin, description);

    cout << "Enter a title for your web page: ";
    getline(cin, title);

    // Create file with the title as the filename, adding ".html" extension
    string fileName = title + ".html";
    ofstream outFile(fileName);

    // Check if the file was opened successfully
    if (!outFile) {
        cout << "Error creating file!" << endl;
        return 1;
    }

    // Write the HTML content to the file
    outFile << "<html>\n";
    outFile << "<head>\n";
    outFile << "  <title>" << title << "</title>\n";
    outFile << "</head>\n";
    outFile << "<body>\n";
    outFile << "  <center>\n";
    outFile << "  <h1>" << name << "</h1>\n";
    outFile << "  </center>\n";
    outFile << "  <hr>\n";
    outFile << "  " << description << "\n";
    outFile << "  <hr>\n";
    outFile << "</body>\n";
    outFile << "</html>\n";

    // Close the file
    outFile.close();

    // Let the user know the file was created
    cout << "Web page created: " << fileName << endl;

    return 0;
}

