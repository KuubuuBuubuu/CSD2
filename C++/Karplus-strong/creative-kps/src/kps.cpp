#include "../include/kps.h"
#include <math.h>

using namespace std;

//Constructor
Karplusstrong::Karplusstrong(double inputLength, double cutoff_frequency, double samplerate, double feedback) {

  //Convert the input in ms to length in samples:
  inputLength = (1 / inputLength) * samplerate;
  outputArray.resize(inputLength);

  this->inputLength = inputLength;
  if(feedback > 0.98) {
    feedback = 0.98;
  } //if
  this->feedback = feedback;
  noiseptr = new Noise(samplerate);

  //Calculate the best amount of taps for the given frequency.
  tapAmount = ((2.0 / 3.0) * log10(10 ^ 9)) * (samplerate / (cutoff_frequency / 2.0));
  lowpassfilter = new Filter(LPF, tapAmount, samplerate, cutoff_frequency); //Initiate the LPF
} //Constructor

Karplusstrong::~Karplusstrong() {
  delete noiseptr;
  delete lowpassfilter;
  cout << "Karplusstrong deconstructed." << endl;
} //destructor

void Karplusstrong::generateNoise(double inputLength) {
  this->inputLength = inputLength;
  cout << "inputLength: " << inputLength << endl;
  outputArray.resize((int)inputLength);
  for(int i = 0; i < (int)outputArray.size(); i++) {
    outputArray[i] = noiseptr->getSample();
    noiseptr->tick();
  } //forloop
} //generateNoise

double Karplusstrong::getSample() {
  iMod = indexNumber % (int)inputLength;
  if(indexNumber >= inputLength) {
    outputArray[iMod] = lowpassfilter->do_sample(outputArray[iMod]) * feedback;
  } //if
  return outputArray[iMod];
} //getSample

void Karplusstrong::moveIndex() {
  indexNumber++;
  indexNumber = indexNumber % 4294967295;
} //moveIndex

double Karplusstrong::getOutputSize() {
  return outputArray.size();
}
