#include <iostream>
#include <thread>
#include "jack_module.h"
#include "sine.h"
#include "square.h"
#include "saw.h"

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

  // create sine wave
  Sine sine(samplerate, 220);
  Square square(samplerate, 220);
  Saw saw(samplerate, 220);
  Oscillator* osc = &sine;
  Oscillator* osc2 = &sine;
  //assign a function to the JackModule::onProces
  jack.onProcess = [&osc, &osc2](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    static double amplitude = 0.5;
    static double amplitude2= 0.4;

    for(unsigned int i = 0; i < nframes; i++) {
      // write sine output * amplitude --> to output buffer
      double outOsc1 = amplitude * osc->getSample();
      double outOsc2 = amplitude2 * osc2->getSample();
      outBuf[i] = outOsc1 + outOsc2;
      // calculate next sample
      osc->tick();
      osc2->tick();
    }

    return 0;
  };

  jack.autoConnect();

  //keep the program running and listen for user input, q = quit
  std::cout << "\n\nPress 'q' when you want to quit the program.\n";
  bool running = true;
  while (running)
  {
    switch (std::cin.get())
    {
      case 'q':
        running = false;
        jack.end();
        break;
      case 'w':
        osc = &sine;
        std::cout << "w is pressed\n";
        break;
      case 'e':
        osc = &square;
        break;
      case 'r':
        osc = &saw;
        break;
      case 's':
        osc2 = &sine;
        break;
      case 'd':
        osc2 = &square;
        break;
      case 'f':
        osc2 = &saw;
        break;
    }
  }

  //end the program
  return 0;
} // main()
