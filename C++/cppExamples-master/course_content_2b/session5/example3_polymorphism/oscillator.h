#ifndef _OSCILLATOR_H_
#define _OSCILLATOR_H_
#include <iostream>
#include "math.h"

#define PI_2 6.28318530717959

class Oscillator
{
public:
  //Constructor and destructor
  Oscillator(double samplerate, double frequency);
  virtual ~Oscillator();

  //return the current sample
  double getSample();
  // go to next sample
  void tick();
  // calculate the next sample, abstract / pure virtual method
  // Oscillator is an abstract class --> not allowed to make an instance anymore
  virtual void calculate() = 0;

  //getters and setters
  void setFrequency(double frequency);
  double getFrequency();

  //NOTE - do we need a setter for phase? for now -> not using one

protected:
  double samplerate;
  double amplitude;
  double frequency;
  double phase;
  double sample;
};

#endif
