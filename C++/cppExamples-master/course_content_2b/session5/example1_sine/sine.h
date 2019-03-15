#ifndef _SINE_H_
#define _SINE_H_
#include <iostream>
#include "math.h"

#define PI_2 6.28318530717959


class Sine
{
public:
  //Constructor and destructor
  Sine(double samplerate, double frequency);
  ~Sine();

  //return the current sample
  double getSample();
  // go to next sample
  void tick();

  //getters and setters
  void setFrequency(double frequency);
  double getFrequency();

  //NOTE - do we need a setter for phase? for now -> not using one

private:
  double samplerate;
  double frequency;
  double phase;
  double sample;
};

#endif
