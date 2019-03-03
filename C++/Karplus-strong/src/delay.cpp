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
  delete delayArray;
  delete lowpassfilter;
  cout << "Delay deconstructed." << endl;
}

void Delay::setSample(int index)
{
  iMod = index % inputLength;
  if (index >= delayLength)
  {
    if (delayLength == inputLength)
    {
      delayArray[iMod] = delayArray[iMod] * feedback; //lowpassfilter->do_sample(delayArray[iMod]) * feedback;
    }
    else
    {
      delayArray[iMod] = (delayArray[iMod] + delayArray[(((index - delayLength) % inputLength) + inputLength) % 5]) * feedback; //lowpassfilter->do_sample((delayArray[iMod] + delayArray[(((index - delayLength) % inputLength) + inputLength) % 5])) * feedback; //Lowpass here
    }
  }
}

double Delay::getSample()
{
  return delayArray[iMod];
}
