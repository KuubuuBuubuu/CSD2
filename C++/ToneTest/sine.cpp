#include "sine.h"


// Constructor and destructor
Sine::Sine(double samplerate, double frequency) :
  Oscillator(samplerate, frequency)
{
  // TODO - use setFrequency and phase instead, to prevent outrange values
}

Sine::~Sine()
{
}


void Sine::calculate()
{

  // calculate sample
  // NOTE: sin() method is not the most efficient way to calculate the sine value
  sample = sin(phase * PI_2);
}
