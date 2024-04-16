/*
  A novice player needs 78 minutes to complete Level 1 and 144 minutes to
  complete Level 2 of a new video game. Write a program that computes and
  displays in hours and minutes the amount of time each level took and
  and that tells how much longer it took the player to complete Level 2
  than Level 1.
*/

#include <iostream>

using namespace std;

// Declare constants
const int LEVEL_ONE_TIME = 78;
const int LEVEL_TWO_TIME = 144;

int main()
{ 
  // Calculate Level 1 Hours and Minutes
  int levelOneHours = LEVEL_ONE_TIME / 60;
  int levelOneMinutes = LEVEL_ONE_TIME % 60;
  
  // Calculate Level 2 Hours and Minutes
  int levelTwoHours = LEVEL_TWO_TIME / 60;
  int levelTwoMinutes = LEVEL_TWO_TIME % 60;

  // Calculate Difference
  int differenceInTime = LEVEL_TWO_TIME - LEVEL_ONE_TIME;
  int differenceHours = differenceInTime / 60;
  int differenceMinutes = differenceInTime % 60;

  cout << "Time it took to complete Level 1: " << levelOneHours << " hours and "
       << levelOneMinutes << " minutes\n";
  cout << "Time it took to complete Level 2: " << levelTwoHours << " hours and "
       << levelTwoMinutes << " minutes\n";
  cout << "It took an additional " << differenceHours << " hour(s) and " << differenceMinutes
       << " minute(s) to complete Level 2";

  return 0;
}
