#include "../include/noise.h"
#include <time.h>
using namespace std;

//~~CC~~ but altered the use of it slightly

// Constructor and destructor
Noise::Noise(double samplerate, double frequency) : Oscillator(samplerate, frequency)
{
    srand(time(NULL));
    for (int i = 0; i < 128; i++)
    {
        r = rand() % 1000 / 1000.0;
        sample_buffer.push_back(r);
    }
    samplesTillDelay = samplerate / 1000;
    lowpassfilter = new Filter(LPF, 51, 44100, 5000);
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
        newSample = delayedSample;
    }

    sample = newSample + delayedSample;
    delayedSample = sample;
    delayedSample = lowpassfilter->do_sample(delayedSample);
    if (samplePos >= samplesTillDelay)
    {
        delayedSample *= feedback;
        samplePos = 0.0;
    }
    samplePos += 1.0;
}

//||CC||
