#ifndef _NOISE_H_
#define _NOISE_H_
#include "oscillator.h"
#include "filt.h"
using namespace std;

#define PI_2 6.28318530717959

class Noise : public Oscillator
{
public:
  //Constructor and destructor
  Noise(double samplerate, double frequency);
  ~Noise();

  void calculate();
  Filter *lowpassfilter;
  float cutoff_frequency = 5000;
};

#endif
