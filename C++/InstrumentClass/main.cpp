#include <iostream>
#include "instrumentClass.h"
using namespace std;

int main() {
  string type;
  string sound;
  cout << "What instrument do you have?\n";
  cin >> type;
  cout << "And what sound does that " << type << " make?\n";
  cin >> sound;
  Instrument violin(type, sound);
  violin.makeSound();
  return 0;
}
