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

 // C++11 enum class, with encapsulated members
 enum class OscillatorType : int {
   sine = 1, // starting with 1 is the convention
   saw,
   square,
   end
 };

 // allow the usage of the increment operator type++
 OscillatorType operator++(OscillatorType& type, int)
 {
    type = static_cast<OscillatorType>(static_cast<int>(type)+1);
    if(type == OscillatorType::end) type = OscillatorType::sine;
    return type;
 }


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


  //assign a function to the JackModule::onProces
  jack.onProcess = [&sine, &saw, &square, &samplerate](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {
    // switch oscillator type every second
    static int count = 0;
    static OscillatorType type = OscillatorType::sine;
    static Oscillator* oscillator = &sine;

    static double amplitude = 0.5;

    for(unsigned int i = 0; i < nframes; i++) {
      // write sine output * amplitude --> to output buffer
      outBuf[i] = amplitude * oscillator->getSample();
      // calculate next sample
      oscillator->tick();

      if(count >= samplerate){
        count = 0;
        type++;
        std::cout << "\ncurrent oscillator type, int value: " << (int)type;
        // select correct osccilator according to type value
        switch(type) {
          case OscillatorType::sine:
            oscillator = &sine;
            break;
          case OscillatorType::saw:
            oscillator = &saw;
            break;
          case OscillatorType::square:
            oscillator = &square;
            break;
          default:
            break;
         }
       }
      // increment count;
      count++;
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
        jack.end();
        running = false;
        break;
    }
  }

  //end the program
  return 0;
} // main()
