#ifndef _NOISE_H_
#define _NOISE_H_
#include "oscillator.h"
#include <vector>
using namespace std;

#define PI_2 6.28318530717959

class Noise : public Oscillator
{
public:
  //Constructor and destructor
  Noise(double samplerate);
  ~Noise();

  // ovverride calculate method
  vector<double> sample_buffer;
  void calculate();
};

#endif
