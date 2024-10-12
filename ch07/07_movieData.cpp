/*
Write a program that uses a structure named MovieData to store the following 
information about a movie: title, director, release year, and running time.

Include a constructor that allows all four of these member data values to be 
specified at the time a MovieData variable is created. The program should create 
two MovieData variables and pass each one in turn to a function that displays 
the information about the movie in a clearly formatted manner. Pass the MovieData 
variables to the display function by value.
*/

#include <iostream>
#include <string>

using namespace std;

struct MovieData {
    string title;
    string director;
    int releaseYear;
    int runningTime;

    MovieData(string t, string d, int y, int r) {
      title = t;
      director = d;
      releaseYear = y;
      runningTime = r;
    }
};

// Function Prototype
void displayMovieData(MovieData movie);

int main() {
    // Create two MovieData 
    MovieData movie1("Inception", "Christopher Nolan", 2010, 148);
    MovieData movie2("Sicario", "Denis Villeneuve", 2015, 121);

    // Display information for each movie 
    displayMovieData(movie1);
    displayMovieData(movie2);

    return 0;
}

void displayMovieData(MovieData movie) {
    cout << "Title:\t\t" << movie.title << endl;
    cout << "Director:\t" << movie.director << endl;
    cout << "Release Year:\t" << movie.releaseYear << endl;
    cout << "Running Time:\t" << movie.runningTime << " minutes\n";
    cout << "---------------------------------\n";
}


