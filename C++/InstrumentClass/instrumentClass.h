#include <iostream>
#pragma once

using namespace std;

class Instrument {
  public:
    Instrument(string type, string sound);
    string type;
    string sound;

  void makeSound();
}; // Instrument
