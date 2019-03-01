#include "../include/noise.h"
#include <time.h>
using namespace std;

//~~CC~~ but altered the use of it slightly

// Constructor and destructor
Noise::Noise(double samplerate, double frequency) : Oscillator(samplerate, frequency)
{
    srand(time(NULL));
    for (int i = 0; i < 88; i++)
    {
        r = rand() % 1000 / 1000.0;
        sample_buffer.push_back(r);
    }
    cout << sample_buffer.size() << endl;
    ;
    samplesTillDelay = samplerate / 1000;
    lowpassfilter = new Filter(LPF, samplerate / cutoff_frequency, samplerate, cutoff_frequency);
    cout << "Created a noise" << endl;
}

Noise::~Noise()
{
    cout << "Destructed a noise" << endl;
}

void Noise::calculate()
{
    if (sample_buffer.size() != 0)
    {
        newSample = sample_buffer[0];
        sample_buffer.erase(sample_buffer.begin());
    }
    else
    {
        newSample = 0;
    }

    sample = newSample;
    if (sample > 0.01)
    {
        delayedSample = lowpassfilter->do_sample(newSample);
        sample_buffer.push_back(delayedSample);
    }
}

//||CC||
