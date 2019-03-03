#include "../include/kps.h"
#include <math.h>
using namespace std;

//Constructor
Karplusstrong::Karplusstrong(int inputLength, double cutoff_frequency, double samplerate, double feedback) //Get the samples from Jack
{
  inputLength = (samplerate / 1000) * inputLength; //Convert the input in ms to length in samples
  outputArray = new double[inputLength];
  this->inputLength = inputLength;
  this->feedback = feedback;
  noiseptr = new Noise(samplerate);
  for (int i = 0; i < inputLength; i++)
  {
    outputArray[i] = noiseptr->getSample();
    noiseptr->tick();
  }
  tapAmount = ((2.0 / 3.0) * log10(10 ^ 9)) * (samplerate / (cutoff_frequency / 2.0));
  lowpassfilter = new Filter(LPF, tapAmount, samplerate, cutoff_frequency); //Initiate the LPF
}

Karplusstrong::~Karplusstrong()
{
  delete noiseptr;
  delete outputArray;
  delete lowpassfilter;
  cout << "Karplusstrong deconstructed." << endl;
}

double Karplusstrong::getSample() //Get the nframes from Jack
{
  iMod = indexNumber % inputLength;
  if (indexNumber >= inputLength)
  {
    outputArray[iMod] = lowpassfilter->do_sample(outputArray[iMod]) * feedback; //delayArray[iMod] * feedback;
  }
  return outputArray[iMod];
}

void Karplusstrong::moveIndex()
{
  indexNumber++;
}
