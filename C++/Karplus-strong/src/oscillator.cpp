#include "../include/oscillator.h"
using namespace std;

//~~CC~~

Oscillator::Oscillator(double samplerate, double frequency) : samplerate(samplerate), frequency(frequency), phase(0), sample(0) {
    amplitude = 0.0;
} //constructor

Oscillator::~Oscillator() {
    cout << "Desructed Oscillator" << endl;
} //destructor

double Oscillator::getSample() {
    return sample;
} //getSample

void Oscillator::tick() {
  // increase phase
  phase += frequency / samplerate;

  // wrap phase from 0 to 1
  if(phase >= 1) {
    phase = phase - 1;
  } //if

  calculate();
} //tick

void Oscillator::calculate() {
    cout << ".";
} //calculate

void Oscillator::setFrequency(double frequency) {
  if(frequency > 0 && frequency < 0.5 * samplerate) {
    this->frequency = frequency;
  } //if
} //setFrequency

double Oscillator::getFrequency() {
    return frequency;
} //getFrequency

void Oscillator::setAmplitude(double amplitude) {
    this->amplitude = amplitude;
} //setAmplitude

double Oscillator::getAmplitude() {
    return amplitude;
} //getAmplitude

//||CC||
