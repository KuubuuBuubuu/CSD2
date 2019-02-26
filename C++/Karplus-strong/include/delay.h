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
