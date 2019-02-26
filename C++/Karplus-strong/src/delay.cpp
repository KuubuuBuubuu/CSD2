#include "../include/delay.h"

Delay::Delay() {
  std::cout << "This is an empty delay. All variables are NULL."
}

Delay::Delay(double delTime, double feedBack, double delSample):
  delTime(delTime), feedBack(feedBack), delSample(delSample)

void updateDelay(double delTime,double feedBack) {
  delSample = Noise.sample + 
