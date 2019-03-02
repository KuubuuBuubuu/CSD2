#include "../include/delay.h"
using namespace std;

//Constructor
Delay::Delay(double feedback, int delayLength, double *input, int inputLength, double cutoff_frequency, double samplerate) //Get the samples from Jack
    : delayArray(new double[inputLength])
{
  cout << "Delay constructed." << endl;
  this->delayLength = delayLength;
  this->feedback = feedback;
  this->cutoff_frequency = cutoff_frequency;
  this->samplerate = samplerate;
  this->inputLength = inputLength;
  for (int i = 0; i < inputLength; i++)
  {
    delayArray[i] = input[i]; //Prepare the first input
  }
  lowpassfilter = new Filter(LPF, samplerate / cutoff_frequency, samplerate, cutoff_frequency); //Initiate the LPF
}

Delay::~Delay()
{
<<<<<<< HEAD
  this->feedback = feedback;
  this->delayLength = delayLength;
  cout << "Delay constructed." << endl;
=======
  delete delayArray;
  delete lowpassfilter;
  cout << "Delay deconstructed." << endl;
>>>>>>> delay
}

double Delay::getSample(int index)
{
<<<<<<< HEAD
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
=======
  iMod = index % inputLength;
  if (index >= delayLength)
  {
    if (delayLength == inputLength)
    {
      delayArray[iMod] = lowpassfilter->do_sample(delayArray[iMod]) * feedback;
    }
    else
    {
      delayArray[iMod] = lowpassfilter->do_sample((delayArray[iMod] + delayArray[(((index - delayLength) % inputLength) + inputLength) % 5])) * feedback; //Lowpass here
    }
  }
  return delayArray[iMod];
}
>>>>>>> delay
