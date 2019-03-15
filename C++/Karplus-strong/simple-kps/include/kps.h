/*
  *Karplusstrong class, by Kaya Bax and Bas Maat
  A simple C++ class to create a filtered circular delay loop.

  PURPOSE:
  It's a complete package that:
  - Creates a custom-length buffer of white noise-samples, and a same-sized delay buffer.
  - Makes an Infinite impulse response out of that delay by feeding it back to the output;
  - Puts all samples through one (or multiple) equalising filters, each time it's called.
  NOTE: The eq-filter is a class forked from the FIR filter class, by Mike Perkins
  For background, see the post http://www.cardinalpeak.com/blog?p=1841

  USAGE:
  Make an object of the class, with the following variables in the following order:
  - inputLength;        : Length of the input array to be delayed, in ms. This length will also decide the pitch of the instrument.
  - cutoff_frequency;   : The frequency at which your filter will start working, in Hz. (NOTE: see filt.h for usage on how to add more filters.)
  - samplerate          : Your system's samplerate in Hz (in main.cpp, you can get the samplerate from Jack.)
  - feedback            : Ratio between 0 and 0.98, amount of feedback of the delay.

  The constructor will create an instance of Noise and an instance of Delay. See each respective header for more information.
  Here will the first Noise burst be calculated and be passed on to the Delay class to prepare the delay line.

  Once the object is created, you can call getSample() from the main program.
  In this function the program can request each sample from the object according to the indexNumber.
  Every time getSample is called moveIndex() needs to be called right after,
  to move the read head of the circular buffer.

  EXAMPLE CODE:
###########################################################
  int main() {
    Karplusstrong karplusstrong(5, 5, 5000, 44100, 0.99);

    while(data_needs_to_run){
      cout << kps.getSample() << endl;
      cout << kps.moveIndex << endl;
    }
  }
###########################################################
  Functions (Public) :
    double getSample();                   : Both writes and reads the sample.
    void generateNoise(int inputLength);  : generates a new noise (starts the loop from the beginning).
    void moveIndex();                     : Moves the indexNumber +1.

  Variables (Private) :
    int inputLength;                      : Length of the input, converted from ms to samples.
    double *noiseArray;                   : Pointer to store the array of the starting burst.
    Noise *noiseptr;                      : Pointer to store the noise oscillator.
    Delay *delayptr;                      : Pointer to store the delay class.
    int indexNumber = 0;                  : Start of the index number.

*/

#ifndef _KPS_H_
#define _KPS_H_
#include <iostream>
#include "noise.h"
#include "filt.h"
using namespace std;

class Karplusstrong
{
public:
  Karplusstrong(int inputLength, double cutoff_frequency, double samplerate, double feedback);
  ~Karplusstrong();

  double getSample();
  void generateNoise(int inputLength);
  void moveIndex();

private:
  int inputLength;
  double *outputArray;
  Noise *noiseptr;
  Filter *lowpassfilter;
  int indexNumber = 0;
  double feedback;
  int iMod;
  double tapAmount;
};

#endif
