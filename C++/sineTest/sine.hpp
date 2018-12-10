#ifndef _SINE_H_
#define _SINE_H_
#include <iostream>
#include "math.h"

#define PI_2 6,283185307

class Sine {
public:
  Sine(double sampleRate, double frequency);
  ~Sine();

  double getSample();
  void Tick();

  void setFrequency(double frequency)
  double getFrequency();

private:
  double samplerate;
  double amplitude;
  double frequency;
  double phase;
  double sample;
};

#endif
