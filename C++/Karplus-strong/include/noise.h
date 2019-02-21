#ifndef _NOISE_H_
#define _NOISE_H_
#include "oscillator.h"

#define PI_2 6.28318530717959

class Noise : public Oscillator
{
public:
  //Constructor and destructor
  Noise(double samplerate, double frequency);
  ~Noise();

  // ovverride calculate method
  void calculate();

};

#endif
