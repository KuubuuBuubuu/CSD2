/*
  main.cpp
  Oktober 21, 2016
  Ciska Vriezenga
*/

/*
  A boolean is a called primitive data type.
  Primitive data types are stored by value and not by reference.

  A boolean is either true or false
*/

#include <iostream>
using namespace std;

int main()
{
  //declare and initiate variables
  int interval, guessedInterval, minInterval, maxInterval;
  bool correctAnswer = false;
  const char majorScaleC[] = {'c', 'd', 'e', 'f', 'g', 'a', 'b'};

  //set the minimum and maximum distance between notes in scale
  minInterval = 1;
  maxInterval = 7;

  /* initialize random seed: */
  srand (time(NULL));
  interval = minInterval + (rand() % (int)(maxInterval - minInterval + 1));

  while(!correctAnswer) {
    cout << endl << "**** GUESS THE NOTE DISTANCE ****" << endl << endl;
    cout << "Please enter the interval in the C major scale,\n";
    cout << "between the following notes: " << majorScaleC[0];
    cout << " and " << majorScaleC[Interval - 1];
    cout << "." << endl;
    cin << guessedInterval;
    //check if the user entered a number from 1 till 7
    if(guessedInterval < 1 && guessedInterval > 7){
      cout << "You entered an incorrect number.\n";
      cout << "Please re-run the programm and try again.\n";
      //go to end loop
      break;
    }
    correctAnswer = true;
  }

  cout << "still printing this";


  //exit the programm
  return 0;
}
