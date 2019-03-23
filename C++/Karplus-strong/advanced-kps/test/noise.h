#ifndef _NOISE_H_
#define _NOISE_H_
#include "oscillator.h"
#include "filt.h"
using namespace std;

#define PI_2 6.28318530717959

class Noise : public Oscillator {
  public:
    //Constructor and destructor
    Noise(double samplerate);
    ~Noise();

    void calculate();

  private:
    double tapAmount;  
    Filter *hpF;
    Filter *lpF;
};

#endif
