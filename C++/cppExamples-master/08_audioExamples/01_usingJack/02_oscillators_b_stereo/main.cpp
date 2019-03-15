#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
#include "sine.h"
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

  //create two Sine instances
  Sine sine1(jack.getSamplerate(), 220, 0);
  Sine sine2(jack.getSamplerate(), 440, 0);
  //assign a function to the JackModule::onProces
  jack.onProcess = [&sine1, &sine2](jack_default_audio_sample_t **inBuffers,
    jack_default_audio_sample_t **outBuffers, jack_nframes_t nframes) {

    static double amplitude = 0.5;

    for(unsigned int i = 0; i < nframes; i++) {
      outBuffers[0][i] = amplitude * sine1.getSample();
      outBuffers[1][i] = amplitude * sine2.getSample();
      sine1.tick();
      sine2.tick();
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
    }
  }

  //end the program
  return 0;
} // main()
