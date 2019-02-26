#ifndef _NOISE_H_
#define _NOISE_H_
#include "oscillator.h"
#include "LowPassFilter.hpp"

#define PI_2 6.28318530717959

class Noise : public Oscillator
{
public:
  //Constructor and destructor
  Noise(double samplerate, double frequency);
  ~Noise();

  // ovverride calculate method
  void calculate();
  float newSample = 1;
  LowPassFilter *lowpassfilter;
};

#endif