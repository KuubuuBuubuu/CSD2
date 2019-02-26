#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <fstream>
#include <thread>

#include "../include/jack_module.h"
#include "../include/noise.h"
#include "../include/delay.h"

//Auto_execute
//cd ..; make; cd bin; ./Karplus-Strong.exe

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

  Noise noise(samplerate, 3000);

  Oscillator *oscillator = &noise;

  //assign a function to the JackModule::onProces
  jack.onProcess = [&oscillator](jack_default_audio_sample_t *inBuf,
                                 jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {
    static double amplitude = 0.5;
    for (unsigned int i = 0; i < nframes; i++)
    {
      // write sine output * amplitude --> to output buffer
      outBuf[i] = amplitude * oscillator->getSample();
      // calculate next sample
      oscillator->tick();
    }
    return 0;
  };

  jack.autoConnect();

  std::cout << "\n\nPress 'q' when you want to quit the program.\n";
  bool running = true;
  bool isPressed = false;
  while (running)
  {
    if (GetAsyncKeyState(VK_SPACE) < 0 && isPressed == false)
        {
          for(unsigned int i = 0; i < 5000000; i++) {
            oscillator->setAmplitude(1.0);
          }
          isPressed = true;
          oscillator->setAmplitude(0.0);
        }
    else if(GetAsyncKeyState(VK_SPACE) == 0 && isPressed == true) {
      isPressed = false;
    }

    if(GetKeyState('Q') & 0x8000) {
      running=false;
      jack.end();
    }
  }
  return 0;
}
