#include <iostream>
#include <thread>
#include "jack_module.h"
#include "sine.h"
#include "saw.h"
#include "square.h"

/*
 * NOTE: jack2 needs to be installed
 * jackd invokes the JACK audio server daemon
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 * on mac, you can start the jack audio server daemon in the terminal:
 * jackd -d coreaudio
 */


int main(int argc,char **argv)
{
  // create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  double samplerate = jack.getSamplerate();

  // create sine wave
  Sine sine(samplerate, 220);
  Saw saw(samplerate, 220);
  Square square(samplerate, 220);

  // NOTE: the code below does not work --> Oscillator is an abstract class
  //Oscillator osc(samplerate, 440);

  // create an osccilator pointer and assign the sine address
  Oscillator* oscillator = &sine;

  // assign a function to the JackModule::onProces
  jack.onProcess = [&oscillator, &samplerate](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    static double amplitude = 0.5;

    for(unsigned int i = 0; i < nframes; i++) {
      // write sine output * amplitude --> to output buffer
      outBuf[i] = amplitude * oscillator->getSample();
      // calculate next sample
      oscillator->tick();
    }

    return 0;
  };

  jack.autoConnect();

  /*
   * NOTE: this is not correct code, because we are changing the same variable
   * in different threads, this purely serves as an example.
   */
  //keep the program running and listen for user input, q = quit
  std::cout << "\n\nPress 'q' when you want to quit the program.\n";
  std::cout << "Press '1' to select the sine wave.\n";
  std::cout << "Press '2' to select the saw wave.\n";
  std::cout << "Press '3' to select the square wave.\n";
  bool running = true;
  while (running)
  {
    switch (std::cin.get())
    {
      case 'q':
        running = false;
        jack.end();
        break;
      case '1':
        oscillator = &sine;
        break;
      case '2':
        oscillator = &saw;
        break;
      case '3':
        oscillator = &square;
        break;
      default:
        break;
    }
  }

  //end the program
  return 0;
} // main()
