#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <fstream>
#include <thread>

#include "jack_module.h"
#include "noise.h"

using namespace std;

int main(int argc, char **argv)
{
  //Create a JackModule instance
  JackModule jack;
  //~~~~~~~~~~~~~~~~~~~~~~~~~~
  //~~~~~~~~~~~JACK~~~~~~~~~~~
  //~~~~~~~~~~~~~~~~~~~~~~~~~~

  // init the jack, use program name as JACK client name
  jack.init("test.exe");
  double samplerate = jack.getSamplerate();

  Noise noise(samplerate);

  Oscillator *oscillator = &noise;

  jack.onProcess = [&oscillator](jack_default_audio_sample_t *inBuf,
                                    jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {
    static double amplitude = 0.5;
    for (unsigned int i = 0; i < nframes; i++)
    {
      outBuf[i] = amplitude * oscillator->getSample();
      oscillator->tick();
    }
    return 0;
  };

  jack.autoConnect();

  bool running = true;
  while(running) {
    if(GetKeyState('Q') & 0x8000) {
      running = false;
      jack.end();
    }
  }
  return 0;
}