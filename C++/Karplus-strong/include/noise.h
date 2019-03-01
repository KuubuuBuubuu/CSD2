#ifndef _NOISE_H_
#define _NOISE_H_
#include "oscillator.h"
#include <vector>
#include "filt.h"
using namespace std;

#define PI_2 6.28318530717959

class Noise : public Oscillator
{
public:
  //Constructor and destructor
  Noise(double samplerate, double frequency);
  ~Noise();

  // ovverride calculate method
  vector<float> sample_buffer;
  void calculate();
  float r;
  float newSample;
  Filter *lowpassfilter;
  float delayedSample = 0.0;
  double feedback = 0.99;
  float samplesTillDelay;
  double samplePos = 0.0;
  float cutoff_frequency = 10000;
  int delayTime = 100;
};

#endif
