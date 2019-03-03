#include "../include/noise.h"
#include <time.h>
using namespace std;

//~~CC~~ but altered the use of it slightly

// Constructor and destructor
Noise::Noise(double samplerate, double frequency) : Oscillator(samplerate, frequency)
{
    srand(time(NULL));
    lowpassfilter = new Filter(LPF, samplerate / cutoff_frequency, samplerate, cutoff_frequency);
    cout << "Created a noise" << endl;
}

Noise::~Noise()
{
    cout << "Destructed a noise" << endl;
}

void Noise::calculate()
{
    sample = lowpassfilter->do_sample(rand() % 1000.0 / 1000.0);
}

//||CC||
