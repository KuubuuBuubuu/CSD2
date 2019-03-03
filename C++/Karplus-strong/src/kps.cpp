#include "../include/kps.h"
#include <math.h>
using namespace std;

//Constructor
Karplusstrong::Karplusstrong(int inputLength, int delayLength, double cutoff_frequency, double samplerate, double feedback) //Get the samples from Jack
{
    inputLength = (samplerate / 1000) * inputLength; //Convert the input in ms to length in samples
    delayLength = (samplerate / 1000) * delayLength;
    noiseArray = new double[inputLength];
    this->inputLength = inputLength;
    noiseptr = new Noise(samplerate);
    for (int i = 0; i < inputLength; i++)
    {
        noiseArray[i] = noiseptr->getSample();
        noiseptr->tick();
    }
    tapAmount = ((2.0/3.0) * log10(10^9)) * (samplerate / cutoff_frequency);
    cout << "tapAmount= " << tapAmount << endl;
    delayptr = new Delay(feedback, delayLength, noiseArray, inputLength, cutoff_frequency, samplerate, tapAmount);

}

Karplusstrong::~Karplusstrong()
{
    delete noiseptr;
    delete noiseArray;
    delete delayptr;
    cout << "Karplusstrong deconstructed." << endl;
}

double Karplusstrong::getSample() //Get the nframes from Jack
{
    return delayptr->getSample(indexNumber);
}

void Karplusstrong::moveIndex()
{
    indexNumber++;
}
