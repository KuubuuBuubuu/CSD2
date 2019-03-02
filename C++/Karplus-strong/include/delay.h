#ifndef _DELAY_H_
#define _DELAY_H_
#include <iostream>
#include "filt.h"
using namespace std;

class Delay
{
  public:
    Delay(double feedback, int delayLength, double *input, int inputLength, float cutoff_frequency, double samplerate);
    ~Delay();
    double getSample(int index);

  private:
    double *delayArray;
    int inputLength;
    double samplerate;
    float cutoff_frequency;
    Filter *lowpassfilter;
    double feedback; // ratio between 0 and 1.
    int delayLength; //amount of samples delay.
    int iMod;        //modulo of the index.
};

#endif