#ifndef _SQUARE_H_
#define _SQUARE_H_
#include "oscillator.h"

class Square : public Oscillator
{
public:
  //Constructor and destructor
  Square(double samplerate, double frequency);
  ~Square();

  // override the calculate method --> calculate the next sample
  // keyword 'final' --> prevent it from being overridden in derived class
  void calculate() final;
};

#endif
