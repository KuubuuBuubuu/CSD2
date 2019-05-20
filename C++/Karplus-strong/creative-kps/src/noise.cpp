#include "../include/noise.h"
#include <time.h>
using namespace std;

Noise::Noise(double samplerate) : Oscillator(samplerate, 60) {
    srand(time(NULL));
    sample = rand() % 1000 / 1000.0;
    //cout << "Created a noise" << endl;
} //constructor

Noise::~Noise() {
    //cout << "Destructed a noise" << endl;
} //destructor

void Noise::calculate() {
    sample = rand() % 1000 / 1000.0;
} //calculate
