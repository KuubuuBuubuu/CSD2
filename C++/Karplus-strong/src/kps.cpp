#include "../include/kps.h"
#include <math.h>
using namespace std;

//Constructor
Karplusstrong::Karplusstrong(int inputLength, double cutoff_frequency, double samplerate, double feedback) {

  //Convert the input in ms to length in samples:
  inputLength = (samplerate / 1000) * inputLength;
  outputArray = new double[inputLength];

  this->inputLength = inputLength;
  if(feedback >= 0.99) {
    feedback = 0.98;
  } //if
  this->feedback = feedback;
  noiseptr = new Noise(samplerate);

  // initialize the white-noise array.
  generateNoise(inputLength);

  //Calculate the best amount of taps for the given frequency.
  tapAmount = ((2.0 / 3.0) * log10(10 ^ 9)) * (samplerate / (cutoff_frequency / 2.0));
  lowpassfilter = new Filter(LPF, tapAmount, samplerate, cutoff_frequency); //Initiate the LPF
} //Constructor

Karplusstrong::~Karplusstrong() {
  delete noiseptr;
  delete outputArray;
  delete lowpassfilter;
  cout << "Karplusstrong deconstructed." << endl;
} //destructor

void Karplusstrong::generateNoise(int inputlength) {
  indexNumber=0;
  for(int i = 0; i < inputLength; i++) {
    outputArray[i] = noiseptr->getSample();
    noiseptr->tick();
  } //forloop
} //generateNoise

double Karplusstrong::getSample() {
  iMod = indexNumber % inputLength;
  if(indexNumber >= inputLength) {
    outputArray[iMod] = lowpassfilter->do_sample(outputArray[iMod]) * feedback; //delayArray[iMod] * feedback;
  } //if
  return outputArray[iMod];
} //getSample

void Karplusstrong::moveIndex() {
  indexNumber++;
} //moveIndex
