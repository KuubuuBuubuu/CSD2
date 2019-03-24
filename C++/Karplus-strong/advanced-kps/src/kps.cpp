#include "../include/kps.h"
#include <math.h>
using namespace std;

//Constructor for the normal kps
Karplusstrong::Karplusstrong(int inputLength, double cutoff_frequency, double samplerate, double feedback) {

  //Convert the input in ms to length in samples:
  inputLength = (samplerate / 1000) * inputLength;
  outputArray.resize(inputLength);

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

//The constructor for the advanced kps
Karplusstrong::Karplusstrong(int inputLength, string fileLocation, double samplerate, double feedback, int test) {
  
  //Convert the input in ms to length in samples:
  inputLength = (samplerate / 1000) * inputLength;
  outputArray.resize(inputLength);

  this->inputLength = inputLength;
  //Safety guard, otherwise it fails
  if(feedback >= 0.99) {
    feedback = 0.98;
  } //if
  this->feedback = feedback;
  noiseptr = new Noise(samplerate);

  // initialize the white-noise array.
  generateNoise(inputLength);

  //Read out the file with the right frequencies
  inFile.open(fileLocation);
  if(!inFile){
    cout<<"Unable to open file"<<endl;  //If the file is not in the correct place display this error
    exit(1);
  }
  while(inFile >> dataEntry){
    fileInput = stod(dataEntry);  //Convert input to double
    if(!start){ //Normal flow
      //Create upper bound for the previous filter
      upperBound = (fileInput - prevFreq) / 2.0;
      tapAmountU = ((2.0 / 3.0) * log10(10 ^ 9)) * (samplerate / (upperBound / 2.0));
      filter.push_back(new Filter(LPF, tapAmountU, samplerate, upperBound));

      //Create lowerbound for the new filter
      lowerBound = upperBound;
      tapAmountL = ((2.0 / 3.0) * log10(10 ^ 9)) * (samplerate / (lowerBound / 2.0));
      filter.push_back(new Filter(LPF, tapAmountL, samplerate, lowerBound));
      prevFreq = fileInput;
    } else { //First flow
      //Create the first input of a lpf, the lowest bound there is
      lowerBound = (fileInput - prevFreq) / 2;
      tapAmountL = ((2.0 / 3.0) * log10(10 ^ 9)) * (samplerate / (lowerBound / 2.0));
      filter.push_back(new Filter(LPF, tapAmountL, samplerate, lowerBound));
      start = false;
      prevFreq = fileInput;
    }
  }
  inFile.close();
  //Draw the last filter
  upperBound = fileInput + 200;
  if(upperBound > samplerate/2.0){
    upperBound = (samplerate/2.0) - 100;
  }
  tapAmountU = ((2.0 / 3.0) * log10(10 ^ 9)) * (samplerate / (upperBound / 2.0));
  filter.push_back(new Filter(LPF, tapAmountU, samplerate, upperBound));
}

Karplusstrong::~Karplusstrong() {
  delete noiseptr;
  for(long long unsigned int i = 0; i < filter.size(); i++){
    delete filter[i];
  }
} //destructor

void Karplusstrong::generateNoise(int inputLength) {
  //this->inputLength=inputLength;
  for(int i = 0; i < this->inputLength; i++) {
    outputArray[i] = noiseptr->getSample();
    noiseptr->tick();
  } //forloop
} //generateNoise
                           
double Karplusstrong::getSample() {
  double sampleDelay = 0;
  double sampleStorage = 0;
  iMod = indexNumber % this->inputLength;
  //pull the original sample through every filter that is created and store the final value in sampleStorage.
    for(long long unsigned int i = 0; i < filter.size(); i+=2){
      sampleDelay = filter[i]->do_sample(outputArray[iMod]);
      sampleDelay = sampleDelay - filter[i+1]->do_sample(sampleDelay);
      sampleStorage+=sampleDelay;
    }

    //Average the number and use the feedback as safety guard
    outputArray[iMod] = (sampleStorage / ((double) filter.size()/(filter.size()/2.0)))*feedback;

  return outputArray[iMod];
} //getSample

void Karplusstrong::moveIndex() {
  indexNumber++;
} //moveIndex
