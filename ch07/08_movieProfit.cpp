/*
Modify the Movie Data program written for Programming Challenge 8 to include two more 
members that hold the movie’s production costs and first-year revenues. The constructor 
should be modified so that all six member values can be specified when a MovieData 
variable is created. Modify the function that displays the movie data to display the 
title, director, release year, running time, and first year’s profit or loss. Also, 
improve the program by having the MovieData variables passed to the display function as 
constant references.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct MovieData {
    string title;
    string director;
    int releaseYear;
    int runningTime;
    double productionCost;
    double firstYearRevenue;

    MovieData(string t, string d, int y, int r, double pCost, double fRevenue) {
      title = t;
      director = d;
      releaseYear = y;
      runningTime = r;
      productionCost = pCost;
      firstYearRevenue = fRevenue;
    }
};

// Function Prototype
void displayMovieData(MovieData& movie);

int main() {
    // Create two MovieData 
    MovieData movie1("Inception", "Christopher Nolan", 2010, 148, 160000000, 830000000);
    MovieData movie2("Sicario", "Denis Villeneuve", 2015, 121, 30000000, 84900000);

    // Display information for each movie 
    displayMovieData(movie1);
    displayMovieData(movie2);

    return 0;
}

void displayMovieData(MovieData& movie) {
    cout << "Title:\t\t" << movie.title << endl;
    cout << "Director:\t" << movie.director << endl;
    cout << "Release Year:\t" << movie.releaseYear << endl;
    cout << "Running Time:\t" << movie.runningTime << " minutes\n";
    cout << "---------------------------------\n";

    // Calc profit or loss
    double profitOrLoss = movie.firstYearRevenue - movie.productionCost;
    cout << "First year Profit/Loss: $" << fixed << setprecision(2) << profitOrLoss << endl;
    cout << "---------------------------------\n";
}
