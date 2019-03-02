#include "../include/delay.h"
using namespace std;

//Constructor
Delay::Delay(double feedback, int delayLength, double *input, int inputLength, float cutoff_frequency, double samplerate) //Get the samples from Jack
    : delayArray(new double[inputLength])
{
    this->delayLength = delayLength;
    this->feedback = feedback;
    this->cutoff_frequency = cutoff_frequency;
    this->samplerate = samplerate;
    this->inputLength = inputLength;
    for (int i = 0; i < inputLength; i++)
    {
        delayArray[i] = input[i]; //Prepare the first input
    }
    lowpassfilter = new Filter(LPF, samplerate / cutoff_frequency, samplerate, cutoff_frequency); //Initiate the LPF
    cout << "Delay constructed." << endl;
}

Delay::~Delay()
{
    delete delayArray;
    delete lowpassfilter;
    cout << "Delay deconstructed." << endl;
}

double Delay::getSample(int index) //Get the nframes from Jack
{
    iMod = index % inputLength;
    if (index >= delayLength)
    {
        if (delayLength == inputLength)
        {
            delayArray[iMod] = lowpassfilter->do_sample(delayArray[iMod]) * feedback;
        }
        else
        {
            delayArray[iMod] = lowpassfilter->do_sample((delayArray[iMod] + delayArray[(((iMod - delayLength) % inputLength) + inputLength) % 5])) * feedback; //Lowpass here
        }
        if (delayArray[iMod] < 1.0 / 4294967296.0)
        {
            delayArray[iMod] = 0;
        }
        return delayArray[iMod];
    }
    else
    {
        return delayArray[iMod];
    }
}

/*
int main()
{   
    srand(time(NULL));
    double feedback = 0.99;
    int iMod = 0;
    int delaylength = 2;
    int arrayLength = 3;
    double a[arrayLength];
    double b[arrayLength];
    for(int i = 0; i < arrayLength; i++){
        a[i] = rand() % 1000 / 1000.0;
        b[i] = a[i];
    }

    for(int i = 0; i < 44100; i++){
      iMod = i % arrayLength;
      cout << "index " << iMod << ": ";
      if(i >= delaylength){
        if(delaylength == arrayLength){
          b[iMod]*=feedback;
        } else{
            b[iMod] = (b[iMod] + b[(((iMod-delaylength) % arrayLength) + arrayLength) % 5]) * feedback;
          }
        if(b[iMod] < 1.0/4294967296.0){
            b[iMod] = 0;
          }
        cout<<b[iMod]<<endl;
      } else {
        cout << a[iMod] << " input Vals " << endl;
      }
    }
    
    return 0;
}
*/