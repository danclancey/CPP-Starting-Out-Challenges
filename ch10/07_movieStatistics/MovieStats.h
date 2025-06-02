#ifndef MOVIESTATS_H
#define MOVIESTATS_H

#include <vector>
#include <memory>

class MovieStats {
private:
    int numStudents;
    std::unique_ptr<int[]> moviesWatched; 

public:
    MovieStats(int numStudents);
    ~MovieStats();

    void getMovieData();
    double calculateAverage();
    double calculateMedian();
    int calculateMode(); 

    void displayResults();
};
#endif