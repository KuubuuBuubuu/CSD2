#ifndef _MELODYGENERATOR_H_
#define _MELODYGENERATOR_H_
#include <iostream>
#include "math.h"

using namespace std;

class MelodyGenerator
{
public:
  //Constructor and destructor
  MelodyGenerator(int noteAmount, string root, string scale);
  ~MelodyGenerator();

  //return the current note
  double getNote();

  //add a new note.
  void addNote();

  //getters and setters
  void setMidiValue(int midiValue);
  float getMidiValue();

  void setVelocity(int velocity);
  int getVelocity();

protected:
  int midiValue;
  int velocity;
  int noteAmount;
  string root;
  string scale;
};

#endif
