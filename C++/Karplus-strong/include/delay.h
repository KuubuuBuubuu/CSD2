/*
  Delay class, by Kaya Bax and Bas Maat
  A simple C++ class to feedback delay an incoming signal with

  PURPOSE:
  This object is used to delay an incoming signal in an IIR manner

  USAGE:
  Invoke and object of Delay. One constructor is available.
  
  The constructor:
  Delay(double feedback, int delayLength, double *input, int inputLength, double cutoff_frequency, double samplerate);

  feedback: The feedback strength ranging from 0.0 to 1.0
  *input: the array with the values of the input
  delayLength: The length of the delay-line in samples
  inputLength: The length of the input in samples
  cutoff_frequency: The cutoff frequency of the lowpass filter
  samplerate: The samplerate in hz

  The constructor will create an instance of Noise and an instance of Delay. See each respective header for more information.
  Here the input will be set as the first values the delay will put out. The delay will start the time in samples later the user sets it
  to be.

  Once the delay is created getSample() can be called from the main program.
  In this function the program can request each sample from the kps according to the indexNumber.
  This is where the output buffer is circular and will delay and feedback itself.

  An example of the main program will look like this:

  int main() { 
    Delay delay(feedback, delayLength, inputArray, inputLength, cutoff_frequency, samplerate);

    while(data_needs_to_run){
      cout << delay.getSample() << endl;
    }
  }

  Private members:
    double *delayArray;
    int inputLength;
    double samplerate;
    double cutoff_frequency;
    Filter *lowpassfilter;
    double feedback;
    int delayLength;
    int iMod;

  *delayArray: Length of the input
  inputLength: Pointer to store the array of the starting burst
  samplerate: Pointer to store the noise oscillator
  cutoff_frequency: Pointer to store the delay class
  *lowpassfilter: Start of the index number
  feedback: The amount of feedback
  delayLength: The length of the delay-line
  iMod: Index of the sample but modulated so the buffer becomes circular instead of finite
*/

#ifndef _DELAY_H_
#define _DELAY_H_
#include <iostream>
#include "filt.h"
using namespace std;

class Delay
{
public:
  Delay(double feedback, int delayLength, double *input, int inputLength, double cutoff_frequency, double samplerate);
  ~Delay();
  void setSample(int index);

  double getSample();

private:
  double *delayArray;
  int inputLength;
  double samplerate;
  double cutoff_frequency;
  Filter *lowpassfilter;
  double feedback;
  int delayLength;
  int iMod;
};

#endif