#include <iostream>
#include <iomanip>
#include <algorithm>
#include "MovieStats.h"

MovieStats::MovieStats(int numStudents) {
    this->numStudents = numStudents;
    moviesWatched = std::make_unique<int[]>(numStudents);
}

MovieStats::~MovieStats() {
    // The unique_ptr will handle memory deallocation
}

void MovieStats::getMovieData() {
    std::cout << "Enter the number of movies each student watched:\n";
    for (int i = 0; i < numStudents; ++i) {
        std::cout << "Student " << i + 1 << ": ";
        std::cin >> moviesWatched[i];
    }
}

double MovieStats::calculateAverage() {
    int sum = 0;
    for (int i = 0; i < numStudents; ++i) {
        sum += moviesWatched[i];
    }
    return static_cast<double>(sum) / numStudents;
}

double MovieStats::calculateMedian() {
    std::sort(moviesWatched.get(), moviesWatched.get() + numStudents);
    int mid = numStudents / 2;
    if (numStudents % 2 == 0) {
        return (moviesWatched[mid - 1] + moviesWatched[mid]) / 2.0;
    } else {
        return moviesWatched[mid];
    }
}

int MovieStats::calculateMode() {
    // Find the maximum value in moviesWatched to determine the size of the counts array
    int maxMoviesWatched = *std::max_element(moviesWatched.get(), moviesWatched.get() + numStudents);

    // Dynamically allocate the counts array
    std::unique_ptr<int[]> counts = std::make_unique<int[]>(maxMoviesWatched + 1); 
    std::fill(counts.get(), counts.get() + maxMoviesWatched + 1, 0); // Initialize to 0

    for (int i = 0; i < numStudents; ++i) {
        counts[moviesWatched[i]]++;
    }

    int mode = 0;
    int maxCount = 0;
    for (int i = 0; i <= maxMoviesWatched; ++i) { 
        if (counts[i] > maxCount) {
            maxCount = counts[i];
            mode = i;
        }
    }

    // counts array is automatically deallocated when it goes out of scope
    return mode;
}

void MovieStats::displayResults() {
    std::cout << "\nSurvey Results:\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << " - Average: " << calculateAverage() << std::endl;
    std::cout << " - Median:  " << calculateMedian() << std::endl;
    std::cout << " - Mode:    " << calculateMode() << std::endl;
}
