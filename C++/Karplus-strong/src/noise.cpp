#include "../include/noise.h"
#include <time.h>
using namespace std;

//~~CC~~ but altered the use of it slightly

// Constructor and destructor
Noise::Noise(double samplerate) : Oscillator(samplerate, 60)
{
    srand(time(NULL));
    sample = rand() % 1000 / 1000.0;
    cout << "Created a noise" << endl;
}

Noise::~Noise()
{
    cout << "Destructed a noise" << endl;
}

void Noise::calculate()
{
    sample = rand() % 1000 / 1000.0;
}

//||CC||
