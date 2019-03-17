#include "noise.h"
#include <time.h>
using namespace std;

Noise::Noise(double samplerate) : Oscillator(samplerate, 60) {
    srand(time(NULL));
    tapAmount = ((2.0 / 3.0) * log10(10 ^ 9)) * (samplerate / ((500) / 2.0));
    sample = rand() % 1000 / 1000.0;
    cout << "Created a noise" << endl;
    myFilter = new Filter(BPF, tapAmount, samplerate, 500, 5000);
} //constructor

Noise::~Noise() {
    cout << "Destructed a noise" << endl;
} //destructor

void Noise::calculate() {
    sample = rand() % 1000 / 1000.0;
    sample = myFilter->do_sample(sample);
} //calculate
