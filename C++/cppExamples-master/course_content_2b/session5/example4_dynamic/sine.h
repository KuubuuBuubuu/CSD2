#ifndef _SINE_H_
#define _SINE_H_
#include "oscillator.h"

class Sine : public Oscillator
{
public:
  //Constructor and destructor
  Sine(double samplerate, double frequency);
  ~Sine();

  // override the calculate method --> calculate the next sample
  // keyword 'final' --> prevent it from being overridden in derived class
  void calculate() final;
};

#endif
