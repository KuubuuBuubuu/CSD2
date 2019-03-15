/*
main.cpp
Oktober 20, 2016
Ciska Vriezenga
*/

/*
  Integer, Long, short, float, doable are so called primitive data types.
  These are stored by value and not by reference.

  whole numbers: Integer, Long, short
  floating point numbers: float, double
*/

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
  //declare the variables
  int midiNote;
  float frequency;
  const int base_a4 = 440;

  //ask user for a MIDInote value
  cout << "enter a MIDInote value (from 0 till 119):\n";
  cin >> midiNote;

  //check if entered value is a valid MIDInote value
  if(midiNote < 0 || midiNote > 119) {
    cout << "You entered an incorrect MIDInote value.\n";
    cout << "Please re-run the programm and try again.\n";
    //exit the programm
    return 0;
  }

  //calculate the corresponding frequency
  frequency = base_a4 * pow(2, (midiNote - 57.0) / 12.0);

  //display calculated frequency to user
  cout << "The MIDInote " << midiNote << " frequency is:  " << frequency << endl;

  //exit the programm
  return 0;
}
