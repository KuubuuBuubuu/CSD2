#include "saw.h"


// Constructor and destructor
Saw::Saw(double samplerate, double frequency) : Oscillator(samplerate, frequency)
{
  // TODO - use setFrequency and phase instead, to prevent outrange values
  std::cout << "\nInside Saw::oscillator (double frequency, double phase)"
    << "\nfrequency: " << frequency
    << "\nphase: " << phase;
}

Saw::~Saw()
{
  std::cout << "\nInside Saw::~Saw";
}

void Saw::calculate() {
  // NOTE - calculating a 'dirty saw' --> ALIASSING!!
  // calculate new sample
  sample = phase * 2 - 1;
}
