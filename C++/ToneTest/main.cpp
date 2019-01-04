#include <iostream>
#include <windows.h>
#include <thread>
#include <math.h>
#include "jack_module.h"
#include "sine.h"
#include "square.h"
#include "saw.h"
using namespace std;
/*
 * NOTE: jack2 needs to be installed
 * jackd invokes the JACK audio server daemon
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 * on mac, you can start the jack audio server daemon in the terminal:
 * jackd -d coreaudio
 */

#define PI_2 6.28318530717959

int main(int argc,char **argv)
{
  // create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  double samplerate = jack.getSamplerate();

  int startFreq = 110;
  double mult = 0;
  int freq = startFreq * pow(2,(mult/12));
  int correct = 0;
  int wrong = 0;
  int lastFreq;
  int ans;
  char cont;

  // create sine wave
  Sine sine(samplerate, freq);
  Oscillator* osc = &sine;
  //assign a function to the JackModule::onProces
  jack.onProcess = [&osc](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    static double amplitude = 0.5;

    for(unsigned int i = 0; i < nframes; i++) {
      // write sine output * amplitude --> to output buffer
      outBuf[i] = amplitude * osc->getSample() ;
      // calculate next sample
      osc->tick();
    }

    return 0;
  };

  jack.autoConnect();



  do
  {
    srand(time(0));
    do
    {
      lastFreq = freq;
      mult = (rand() %28) * 3;
      freq = startFreq * pow(2, (mult/12));
    } while (freq==0 || freq==lastFreq || freq>15000);
    sine.setFrequency(freq);
    system("CLS");
    cout << "\n #################### Kuubuu's Ear Training #################### \n\n What do you guess this frequency is? ";
    cin >> ans;

    if (ans >= 0.666 * freq && ans <= 1.333 * freq && ans != freq)
    {
      cout << "The Correct answer was: " << freq << " Hz. Close Enough! \n";
      correct++;
    }

    else if (ans == freq)
    {
      cout << "The Correct answer was: " << freq << " Hz. Perfect! \n";
      correct++;
    }

    else
    {
      cout << "The Correct answer was: " << freq << " Hz. Not Even Close! Boo! \n";
      wrong++;
    }
    cout << "\n\n########## CURRENT SCORE ##########\n\n" << "            Right:  " << correct << "\n            Wrong:  " << wrong;
    cout<<"\n\nWould you like to continue? (y/n): ";
    cin>>cont;
  } while (cont=='y');

  jack.end();



  //end the program
  return 0;
} // main()
