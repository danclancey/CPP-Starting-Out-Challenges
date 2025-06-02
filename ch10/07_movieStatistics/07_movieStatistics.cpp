/*
Write a program that can be used to gather statistical data about the number of movies college students see in a month. The program should 
ask the user how many students were surveyed and dynamically allocate an array of that size. The program should then allow the user to 
enter the number of movies each student has seen. The program should then calculate the average, median, and mode of the values entered.
*/

#include <iostream>
#include "MovieStats.h"

int main() {
    int numStudents;

    std::cout << "How many students were surveyed? ";
    std::cin >> numStudents;

    MovieStats stats(numStudents);
    stats.getMovieData();
    stats.displayResults();

    return 0;
}
