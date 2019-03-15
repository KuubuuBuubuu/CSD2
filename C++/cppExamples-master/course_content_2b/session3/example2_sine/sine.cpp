#include "sine.h"


// Constructor and destructor
Sine::Sine(double samplerate, double frequency) :
  frequency(frequency), phase(0), sample(0), samplerate(samplerate)
{
  // TODO - use setFrequency and phase instead, to prevent outrange values
  std::cout << "\nInside Sine::oscillator (double frequency, double phase)"
    << "\nfrequency: " << frequency
    << "\nphase: " << phase;
}

Sine::~Sine()
{

}

double Sine::getSample() { return sample; }

void Sine::tick()
{
  // increase phase
  phase += frequency / samplerate;
  // wrap phase from 0 to 1
  if(phase >= 1) phase = phase - 1;

  // calculate new sample
  // NOTE: sin() method is not the most efficient way to calculate the sine value
  sample = sin(phase * PI_2);
}

void Sine::setFrequency(double frequency)
{
  if(frequency > 0 && frequency < 0.5 * samplerate)
  this->frequency = frequency;
}

double Sine::getFrequency()
{
  return frequency;
}
