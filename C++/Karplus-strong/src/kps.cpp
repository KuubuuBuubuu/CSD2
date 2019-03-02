#include "../include/kps.h"
using namespace std;

//Constructor
Karplusstrong::Karplusstrong(int inputLength, int delayLength, float cutoff_frequency, double samplerate, double feedback) //Get the samples from Jack
    : noiseArray(new double[inputLength])
{
    this->inputLength = inputLength;
    Noise noise(samplerate);
    for (int i = 0; i < inputLength; i++)
    {
        noiseArray[i] = noise.getSample();
        noise.tick();
    }

    Delay delay(feedback, delayLength, noiseArray, inputLength, cutoff_frequency, samplerate);

    delayptr = &delay;
    noiseptr = &noise;
    cout << "Karplusstrong constructed." << endl;
}

Karplusstrong::~Karplusstrong()
{
    delete noiseArray;
    cout << "Karplusstrong deconstructed." << endl;
}

double Karplusstrong::getSample(int index) //Get the nframes from Jack
{
    return delayptr->getSample(index);
}