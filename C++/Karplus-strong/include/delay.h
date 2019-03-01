#include <vector>
#include <iostream>
#include "../include/oscillator.h"

class Delay
{
  public:
    Delay(double feedback, int delayLength);
    void write(int i, oscillator *o);
    int read(int i); // set i to be sample_buffer size.

  private:
    std::vector<double> delSamBuf[Oscillator::sample_buffer.size()];
    double feedback; // ratio between 0 and 1.
    int delayLength; //amount of samples delay.
    int iMod;        //modulo of the index.
}