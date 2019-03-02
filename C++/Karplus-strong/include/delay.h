<<<<<<< HEAD
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
=======
#ifndef _DELAY_H_
#define _DELAY_H_

#include "noise.h"

class Delay {
  friend class Noise;
public:
  //constructor
  Delay();
  Delay(double delTime, double feedBack, double delSample);
  //functions
  void updateDelay(double delTime,double feedBack);
  void setDelTime(int samples);
  void getDelTime();
  void setFeedBack(double percentage);
  void getFeedBack();
private:
  double delTime;
  double feedBack;
  double delSample;
};

#endif
>>>>>>> 5921d97406b2ac90a88636b747146d7d68351f47
