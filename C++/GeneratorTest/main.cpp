#include <iostream>
#include <thread>
#include "jack_module.h"
#include "MelodyGenerator.h"

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
  int q1;
  cout << "What's your bpm?\n";
  cin >> q1;

  int q2;
  cout << "\n\nHow many notes should be in your melody?\n";
  cin >> q2;

  string q3;
  cout << "\n\nWhat do you want your root to be? (a - as)\n";
  cin >> q3;

  string q4;
  cout << "\n\nWhat scale do you want to use? You can choose between: \n- major \n- minor\n";
  cin >> q4;

  MelodyGenerator melody(q1, q2, q3, q4);
  melody.generate();

char exitter;
cout << "Press Any button to exit the program.";
cin >> exitter;
    }
