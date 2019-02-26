#include "../include/noise.h"
#include <time.h>
using namespace std;

//~~CC~~ but altered the use of it slightly

// Constructor and destructor
Noise::Noise(double samplerate, double frequency) : Oscillator(samplerate, frequency)
{
    srand(time(NULL));
    lowpassfilter = new Filter(LPF, 51, 44100, 200);
    cout << "Created a noise" << endl;
}

Noise::~Noise()
{
    cout << "Destructed a noise" << endl;
}

void Noise::calculate()
{
    // calculate sample
    newSample = rand() % 1000 / 1000.0 * amplitude;
    sample = lowpassfilter->do_sample(newSample);
}

//||CC||
