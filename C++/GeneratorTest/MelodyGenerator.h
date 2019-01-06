#ifndef _MELODYGENERATOR_H_
#define _MELODYGENERATOR_H_
#include <iostream>
#include <vector>
#include "math.h"

using namespace std;

class MelodyGenerator
{
public:
  //Constructor and destructor
  MelodyGenerator(int bpm, int noteAmount, string root, string scale);
  ~MelodyGenerator();
  int bpm;
  int noteAmount;
  string root;
  string scale;
  vector<int> pitch = {};
  vector<double> noteLength = {2};
  vector<int> pitchList = {};



 int rootMidiValue;
 int step = 2; //starting position; Start at chosen root.
 int randomStep = rand() %3 -1;
 int randomLength = rand() %3 +1;

  //go to next note
  void generate();

  void setRoot(string root);


private:
  float sixteenth = (60.0 / bpm) / 4.0;
};

#endif
