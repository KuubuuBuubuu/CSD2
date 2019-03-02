#ifndef _KPS_H_
#define _KPS_H_
#include <iostream>
#include "noise.h"
#include "delay.h"
using namespace std;

class Karplusstrong
{
public:
  Karplusstrong(int inputLength, int delayLength, double cutoff_frequency, double samplerate, double feedback);
  ~Karplusstrong();

  double getSample();
  void moveIndex();

private:
  int inputLength;
  double *noiseArray;
  Noise *noiseptr;
  Delay *delayptr;
  int indexNumber = 0;
};

#endif