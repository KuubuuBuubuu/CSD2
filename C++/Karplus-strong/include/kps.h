#ifndef _KPS_H_
#define _KPS_H_
#include <iostream>
#include "noise.h"
#include "delay.h"
using namespace std;

class Karplusstrong
{
  public:
    Karplusstrong(int inputLength, int delayLength, float cutoff_frequency, double samplerate, double feedback);
    ~Karplusstrong();

    double getSample(int index);

  private:
    int inputLength;
    double *noiseArray;
    Oscillator *noiseptr;
    Delay *delayptr;
};

#endif