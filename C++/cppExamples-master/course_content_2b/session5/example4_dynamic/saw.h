#ifndef _SAW_H_
#define _SAW_H_
#include "oscillator.h"

class Saw : public Oscillator
{
public:
  //Constructor and destructor
  Saw(double samplerate, double frequency);
  ~Saw();

  // override the calculate method --> calculate the next sample
  // keyword 'final' --> prevent it from being overridden in derived class
  void calculate() final;
};

#endif
