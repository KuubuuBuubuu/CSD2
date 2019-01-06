#include <iostream>
#include <thread>
#include "jack_module.h"
#include "MelodyGenerator.h"

using namespace std;

int main()
{
  int q1;
  cout << "What's your bpm?\n";
  cin >> q1;

  int q2;
  cout << "\nHow many notes should be in your melody?\n";
  cin >> q2;

  string q3;
  cout << "\nWhat do you want your root to be? (a - as)\n";
  cin >> q3;

  string q4;
  cout << "\nWhat scale do you want to use? You can choose between: \n- major \n- minor \n- phrygian \n- lydian \n- harmonicminor \n- dorian#4 - Kayas Favorite :D\n";
  cin >> q4;

  MelodyGenerator melody(q1, q2, q3, q4);
  melody.generate();

system("pause");
}
