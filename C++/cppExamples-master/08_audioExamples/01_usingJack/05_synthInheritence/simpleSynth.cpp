#include "simpleSynth.h"

/*---------------- CONSTRUCTORS / DESTRUCTOR ----------------*/
//constructor - calls the other constructor with midiPitch = 0
SimpleSynth::SimpleSynth(float samplerate)
  : SimpleSynth(samplerate, 0) {}

//using 0 as init value for midiPitch and sine frequency value
SimpleSynth::SimpleSynth(float samplerate, float midiPitch)
  : Synth(samplerate), sine(samplerate, 0) {
    //set midi pitch
    //(we can't do this is Synth constructor, because its derived class does not
    //exist yet, which we do need due to the abstract updateFrequency method
    setMidiPitch(midiPitch);
  }

//destructor - delete s object, set pointer to nullptr
SimpleSynth::~SimpleSynth() {}

/*---------------- PUBLIC METHODS ----------------*/
//returns the current sample
double SimpleSynth::getSample() {
  //TODO add amplitude
  return sine.getSample();
}

//TODO - should we add a clock object with listeners, instead of using tick?
//updates sample, 'tick'
void SimpleSynth::tick() { sine.tick(); }


/*---------------- PRIVATE METHODS ----------------*/
//set the synth's frequency
void SimpleSynth::updateFrequency() {
  sine.setFrequency((double)frequency);
}
