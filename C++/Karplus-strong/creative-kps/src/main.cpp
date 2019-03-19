//NOTE: Please read kps.h for instructions.

#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include <vector>
#include <fstream>
#include <thread>

#include "../include/jack_module.h"
#include "../include/kps.h"
#include "../include/voicemanager.h"

using namespace std;

int main(int argc, char **argv)
{
  //Create a JackModule instance
  JackModule jack;
  //~~~~~~~~~~~~~~~~~~~~~~~~~~
  //~~~~~~~~~~~JACK~~~~~~~~~~~
  //~~~~~~~~~~~~~~~~~~~~~~~~~~

  // init the jack, use program name as JACK client name
  jack.init("Karplus Strong [ALPHA]");
  double samplerate = jack.getSamplerate();
  VoiceManager voice(6, samplerate, "c");

  //Karplusstrong kps1(220, 5000, samplerate, 0.98); //Initiate the kps1, see 'kps.h' for more info
  //Karplusstrong kps2(220, 5000, samplerate, 0.98); //Initiate the kps1, see 'kps.h' for more info
  //Karplusstrong kps3(220, 5000, samplerate, 0.98); //Initiate the kps1, see 'kps.h' for more info
//  Karplusstrong kps4(220, 5000, samplerate, 0.98); //Initiate the kps1, see 'kps.h' for more info
//  Karplusstrong kps5(220, 5000, samplerate, 0.98); //Initiate the kps1, see 'kps.h' for more info
//  Karplusstrong kps6(220, 5000, samplerate, 0.98); //Initiate the kps1, see 'kps.h' for more info

  jack.onProcess = [&voice](jack_default_audio_sample_t *inBuf,
                                    jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {
    static double amplitude = 0.9;
    for (unsigned int i = 0; i < nframes; i++)
    {
      // write sine output * amplitude --> to output buffer
      outBuf[i] = amplitude * voice.getSamples();
      voice.moveIndexes();
    }
    return 0;
  };

  jack.autoConnect();

  std::cout << "\n\nPress SPACE to make sound.\n";
  std::cout << "Press 'q' when you want to quit the program.\n";

  bool running = true;
  bool isPressedq = false;
  bool isPressed2 = false;
  bool isPressedw = false;
  bool isPressed3 = false;
  bool isPressede = false;
  bool isPressedr = false;
  bool isPressed5 = false;
  bool isPressedt = false;
  bool isPressed6 = false;
  bool isPressedy = false;
  bool isPressed7 = false;
  bool isPressedu = false;
  bool isPressedi = false;


  while(running) {
    if(GetAsyncKeyState('Q') < 0 && isPressedq == false) {
      voice.addVoice();
      voice.setPitch(0);
      voice.generateNoise(voice.getVoice(), voice.getNoiseLength());
      isPressedq = true;
    }
    else if(GetAsyncKeyState('Q') == 0 && isPressedq == true) {
      voice.removeVoice();
      isPressedq = false;
    }

    if(GetAsyncKeyState('2') < 0 && isPressed2 == false) {
      voice.addVoice();
      voice.setPitch(1);
      voice.generateNoise(voice.getVoice(), voice.getNoiseLength());
      isPressed2 = true;
    }
    else if(GetAsyncKeyState('2') == 0 && isPressed2 == true) {
      voice.removeVoice();

      isPressed2 = false;
    }

    if(GetAsyncKeyState('W') < 0 && isPressedw == false) {
      voice.addVoice();
      voice.setPitch(2);
      voice.generateNoise(voice.getVoice(), voice.getNoiseLength());
      isPressedw = true;
    }
    else if(GetAsyncKeyState('W') == 0 && isPressedw == true) {
      voice.removeVoice();

      isPressedw = false;
    }


    if(GetAsyncKeyState('3') < 0 && isPressed3 == false) {
      voice.addVoice();
      voice.setPitch(3);
      voice.generateNoise(voice.getVoice(), voice.getNoiseLength());
      isPressed3 = true;
    }
    else if(GetAsyncKeyState('3') == 0 && isPressed3 == true) {
      voice.removeVoice();
      isPressed3 = false;
    }

    if(GetAsyncKeyState('E') < 0 && isPressede == false) {
      voice.addVoice();
      voice.setPitch(4);
      voice.generateNoise(voice.getVoice(), voice.getNoiseLength());
      isPressede = true;
    }
    else if(GetAsyncKeyState('E') == 0 && isPressede == true) {
      voice.removeVoice();

      isPressede = false;
    }

    if(GetAsyncKeyState('R') < 0 && isPressedr == false) {
      voice.addVoice();
      voice.setPitch(5);
      voice.generateNoise(voice.getVoice(), voice.getNoiseLength());
      isPressedr = true;
    }
    else if(GetAsyncKeyState('R') == 0 && isPressedr == true) {
      voice.removeVoice();

      isPressedr = false;
    }

    if(GetAsyncKeyState('5') < 0 && isPressed5 == false) {
      voice.addVoice();
      voice.setPitch(6);
      voice.generateNoise(voice.getVoice(), voice.getNoiseLength());
      isPressed5 = true;
    }
    else if(GetAsyncKeyState('5') == 0 && isPressed5 == true) {
      voice.removeVoice();
      isPressed5 = false;
    }

    if(GetAsyncKeyState('T') < 0 && isPressedt == false) {
      voice.addVoice();
      voice.setPitch(7);
      voice.generateNoise(voice.getVoice(), voice.getNoiseLength());
      isPressedt = true;
    }
    else if(GetAsyncKeyState('T') == 0 && isPressedt == true) {
      voice.removeVoice();
      isPressedt = false;
    }

    if(GetAsyncKeyState('6') < 0 && isPressed6 == false) {
      voice.addVoice();
      voice.setPitch(8);
      voice.generateNoise(voice.getVoice(), voice.getNoiseLength());
      isPressed6 = true;
    }
    else if(GetAsyncKeyState('6') == 0 && isPressed6 == true) {
      voice.removeVoice();
      isPressed6 = false;
    }

    if(GetAsyncKeyState('Y') < 0 && isPressedy == false) {
      voice.addVoice();
      voice.setPitch(9);
      voice.generateNoise(voice.getVoice(), voice.getNoiseLength());
      isPressedy = true;
    }
    else if(GetAsyncKeyState('Y') == 0 && isPressedy == true) {
      voice.removeVoice();
      isPressedy = false;
    }

    if(GetAsyncKeyState('7') < 0 && isPressed7 == false) {
      voice.addVoice();
      voice.setPitch(10);
      voice.generateNoise(voice.getVoice(), voice.getNoiseLength());
      isPressed7 = true;
    }
    else if(GetAsyncKeyState('7') == 0 && isPressed7 == true) {
      voice.removeVoice();
      isPressed7 = false;
    }

    if(GetAsyncKeyState('U') < 0 && isPressedu == false) {
      voice.addVoice();
      voice.setPitch(11);
      voice.generateNoise(voice.getVoice(), voice.getNoiseLength());
      isPressedu = true;
    }
    else if(GetAsyncKeyState('U') == 0 && isPressedu == true) {
      voice.removeVoice();
      isPressedu = false;
    }

    if(GetAsyncKeyState('I') < 0 && isPressedi == false) {
      voice.addVoice();
      voice.setPitch(12);
      voice.generateNoise(voice.getVoice(), voice.getNoiseLength());
      isPressedi = true;
    }
    else if(GetAsyncKeyState('I') == 0 && isPressedi == true) {
      voice.removeVoice();
      isPressedi = false;
    }


    if(GetKeyState(VK_BACK) & 0x8000) {
      running = false;
      jack.end();
    }
  }
  return 0;
}
