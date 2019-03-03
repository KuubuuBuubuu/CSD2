/*
  *Karplusstrong class, by Kaya Bax and Bas Maat
  A simple C++ class to create a karplusstrong string sound

  PURPOSE:
  This object used to resynthesis a string sound using noise

  USAGE:
  Invoke and object of Karplusstrong. One constructor is available.

  The constructor:
  Karplusstrong(int inputLength, int delayLength, double cutoff_frequency, double samplerate, double feedback)

  inputLength: The length of the noise burst in ms, for optimal effect make this as long as the delayLength
  delayLength: The length of the delay-line in ms
  cutoff_frequency: The cutoff frequency of the lowpass filter
  samplerate: The samplerate in hz
  feedback: The feedback strength ranging from 0.0 to 1.0

  The constructor will create an instance of Noise and an instance of Delay. See each respective header for more information.
  Here will the first Noise burst be calculated and be passed on to the Delay class to prepare the delay line.

  Once the kps is created getSample() can be called from the main program.
  In this function the program can request each sample from the kps according to the indexNumber.
  Every time getSample is called moveIndex() needs to be called right after to move the
  read head of the circular buffer.

  An example of the main program will look like this:

  int main() {
    Karplusstrong karplusstrong(5, 5, 5000, 44100, 0.99);

    while(data_needs_to_run){
      cout << kps.getSample() << endl;
      cout << kps.moveIndex << endl;
    }
  }

  Private members:
    int inputLength;
    double *noiseArray;
    Noise *noiseptr;
    Delay *delayptr;
    int indexNumber = 0;

  inputLength: Length of the input
  noiseArray: Pointer to store the array of the starting burst
  noiseptr: Pointer to store the noise oscillator
  delayptr: Pointer to store the delay class
  indexNumber: Start of the index number
*/

#ifndef _KPS_H_
#define _KPS_H_
#include <iostream>
#include "noise.h"
#include "delay.h"
using namespace std;

class Karplusstrong
{
public:
  Karplusstrong(int inputLength, int delayLength, double cutoff_frequency, double samplerate, double feedback);
  ~Karplusstrong();

  double getSample();
  void moveIndex();


private:
  int inputLength;
  double *noiseArray;
  Noise *noiseptr;
  Delay *delayptr;
  int indexNumber = 0;
  double tapAmount;
};

#endif
