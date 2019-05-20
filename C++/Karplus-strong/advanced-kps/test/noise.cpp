#include "noise.h"
#include <time.h>
using namespace std;

Noise::Noise(double samplerate) : Oscillator(samplerate, 60) {
    srand(time(NULL));
    tapAmount = ((2.0 / 3.0) * log10(10 ^ 9)) * (samplerate / ((700) / 2.0));
    sample = rand() % 1000 / 1000.0;
    cout << "Created a noise" << endl;
    hpF = new Filter(LPF, tapAmount, samplerate, 700);
    lpF = new Filter(LPF, ((2.0 / 3.0) * log10(10 ^ 9)) * (samplerate / ((500) / 2.0)), samplerate, 500);
} //constructor

Noise::~Noise() {
    delete hpF;
    delete lpF;
    cout << "Destructed a noise" << endl;
} //destructor

void Noise::calculate() {
    sample = rand() % 1000 / 1000.0;
    //sample = lpF->do_sample(sample);
    sample = sample - hpF->do_sample(sample);
} //calculate