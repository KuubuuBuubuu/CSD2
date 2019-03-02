#include "../include/delay.h"

using namespace std;

//Constructor
Delay::Delay(double feedback, int delayLength)
{
  this->feedback = feedback;
  this->delayLength = delayLength;
  cout << "Delay constructed." << endl;
}

Delay::write(int i, oscillator *o)
{
  iMod = i % delayLength;
  cout << "Index " << i << " : ";
  if (iMod == delayLength)
  {
    delSamBuf[iMod] = o->sample[i - delayLength] * feedback + delSamBuf[iMod] * feedback;
    cout << delSamBuff[iMod] << " if " << endl;
  }
  else
  {
    b[iMod] = 0;
    cout << b[iMod] << " else " << endl;
  }
  delSamBuf[i] = o->sample[i - delayLength];
}
}

Delay::read(int i)
{
  // return the current sample.
  return delSamBuf[i]
}
