//NOTE: Please read kps.h for instructions.

#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <fstream>
#include <thread>
#include <string>

#include "../include/jack_module.h"
#include "../include/kps.h"

using namespace std;

int main(int argc, char **argv)
{
  int length;
  cout << "Please fill in the length in ms of how long the array must be:" << endl;
  cin >> length;

  //Create a JackModule instance
  JackModule jack;
  //~~~~~~~~~~~~~~~~~~~~~~~~~~
  //~~~~~~~~~~~JACK~~~~~~~~~~~
  //~~~~~~~~~~~~~~~~~~~~~~~~~~

  // init the jack, use program name as JACK client name
  jack.init("Karplus Strong [ALPHA]");
  double samplerate = jack.getSamplerate();

  Karplusstrong karplusstrong(length, 5000, samplerate, 0.99); //Initiate the Karplusstrong, see 'kps.h' for more info

  jack.onProcess = [&karplusstrong](jack_default_audio_sample_t *inBuf,
                                    jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {
    static double amplitude = 0.5;
    for (unsigned int i = 0; i < nframes; i++)
    {
      // write sine output * amplitude --> to output buffer
      outBuf[i] = amplitude * karplusstrong.getSample();
      karplusstrong.moveIndex();
    }
    return 0;
  };

  jack.autoConnect();

  std::cout << "\n\nPress SPACE to make sound.\n";
  std::cout << "Press 'q' when you want to quit the program.\n";

  bool running = true;
  bool isPressed = false;
  while(running) {
    if(GetAsyncKeyState(VK_SPACE) < 0 && isPressed == false) {
      karplusstrong.generateNoise(length);
      isPressed = true;
    }
    else if(GetAsyncKeyState(VK_SPACE) == 0 && isPressed == true) {
      isPressed = false;
    }

    if(GetKeyState('Q') & 0x8000) {
      running = false;
      jack.end();
    }
  }
  return 0;
}
