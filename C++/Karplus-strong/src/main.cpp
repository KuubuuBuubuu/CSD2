#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <fstream>
#include <thread>

#include "../include/jack_module.h"
#include "../include/oscillator.h"

//Auto_execute
//cd ..; make; cd bin; ./synthsong.exe

#define PI_2 6.28318530717959

using namespace std;

int main(int argc, char **argv)
{
  //Create a JackModule instance
  JackModule jack;

  //~~~~~~~~~~~~~~~~~~~~~~~~~~
  //~~~~~~~~~~~JACK~~~~~~~~~~~
  //~~~~~~~~~~~~~~~~~~~~~~~~~~

  // init the jack, use program name as JACK client name
  jack.init("example.exe");
  double samplerate = jack.getSamplerate();

  //assign a function to the JackModule::onProces
  jack.onProcess = [&synthesizer](jack_default_audio_sample_t *inBuf,
                                  jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {
    static double amplitude = 0.5;
    for (unsigned int i = 0; i < nframes; i++)
    {
      // write sine output * amplitude --> to output buffer
      outBuf[i] = amplitude * synthesizer->getSample();
      // calculate next sample
      synthesizer->tick();
    }
    return 0;
  };

  jack.autoConnect();
  return 0;
}