#include "../include/noise.h"
#include <time.h>
using namespace std;

//~~CC~~ but altered the use of it slightly

// Constructor and destructor
Noise::Noise(double samplerate, double frequency) : Oscillator(samplerate, frequency)
{
    srand(time(NULL));
    cout << "Created a sine" << endl;
}

Noise::~Noise()
{
    cout << "Destructed a sine" << endl;
}

void Noise::calculate()
{
    // calculate sample
    sample = rand() % 1000 / 1000.0;
}

//||CC||