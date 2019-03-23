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
  filter.push_back(new Filter(LPF, tapAmount, samplerate, cutoff_frequency)); //Initiate the LPF
} //Constructor

Karplusstrong::Karplusstrong(int inputLength, string fileLocation, double samplerate, double feedback) {
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

  double upperBound;
  double lowerBound;

  inFile.open(fileLocation);
  if(!inFile){
    cout<<"Unable to open file"<<endl;  //If the file is not in the correct place display this error
    exit(1);
  }
  while(inFile >> fileInput){
      lowerBound = stod(fileInput) - 20;
      upperBound = stod(fileInput) + 20;
      tapAmount = ((2.0 / 3.0) * log10(10 ^ 9)) * (samplerate / (lowerBound / 2.0));
      filter.push_back(new Filter(BPF, tapAmount, samplerate, lowerBound, upperBound));
  }
  inFile.close();
}

Karplusstrong::~Karplusstrong() {
  delete noiseptr;
  delete outputArray;
  for(long long unsigned int i = 0; i < filter.size(); i++){
    delete filter[i];
  }
  cout << "Karplusstrong deconstructed." << endl;
} //destructor

void Karplusstrong::generateNoise(int inputLength) {
  indexNumber=0;
  for(int i = 0; i < inputLength; i++) {
    outputArray[i] = noiseptr->getSample();
    noiseptr->tick();
  } //forloop
} //generateNoise
                           
double Karplusstrong::getSample() {
  double sampleDelay = 0;
  iMod = indexNumber % inputLength;
  if(indexNumber >= inputLength) {
    for(long long unsigned int i = 0; i < filter.size(); i++){
      sampleDelay += filter[i]->do_sample(outputArray[iMod]);
    }
    outputArray[iMod] = (sampleDelay / (double) filter.size()) * feedback;
  } //if

  return outputArray[iMod];
} //getSample

void Karplusstrong::moveIndex() {
  indexNumber++;
} //moveIndex
