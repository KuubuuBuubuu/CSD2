#include "square.h"


// Constructor and destructor
Square::Square(double samplerate, double frequency) : Oscillator(samplerate, frequency)
{
  // TODO - use setFrequency and phase instead, to prevent outrange values
  std::cout << "\nInside Square::oscillator (double frequency, double phase)"
    << "\nfrequency: " << frequency
    << "\nphase: " << phase;
}

Square::~Square()
{

}

void Square::calculate() {
  // NOTE - calculating a 'dirty square' --> ALIASSING!!
  // calculate new sample
  if(phase <0.5) sample = -1;
  else sample = 1;
}
