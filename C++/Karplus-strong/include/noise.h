#ifndef _NOISE_H_
#define _NOISE_H_
#include "oscillator.h"
#include "filt.h"

#define PI_2 6.28318530717959

class Noise : public Oscillator
{
public:
  //Constructor and destructor
  Noise(double samplerate, double frequency);
  ~Noise();

  // ovverride calculate method
  void calculate();
  float newSample = 0;
  Filter *lowpassfilter;
};

#endif
