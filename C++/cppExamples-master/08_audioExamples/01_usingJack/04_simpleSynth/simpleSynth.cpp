#include "simpleSynth.h"

/*---------------- CONSTRUCTORS / DESTRUCTOR ----------------*/
//constructor - calls the other constructor with midiPitch = 0
SimpleSynth::SimpleSynth(float samplerate)
  : SimpleSynth(samplerate, 0) {}

//using 0 as init value for midiPitch and sine frequency value
SimpleSynth::SimpleSynth(float samplerate, float midiPitch)
  : samplerate(samplerate), midiPitch(0), sine(samplerate, 0) {
    setMidiPitch(midiPitch);
  }

//destructor - delete s object, set pointer to nullptr
SimpleSynth::~SimpleSynth() {}

/*---------------- PUBLIC METHODS ----------------*/

/*---------------- PUBLIC METHODS ----------------*/
//set the synth's pitch, using midi values.
void SimpleSynth::setMidiPitch(float midiPitch)
{
  //if midiPitch changes less then 1 cents, do not update the midiPitch
  if(midiPitch < this->midiPitch - 0.005 || midiPitch > this->midiPitch + 0.005){
    std::cout << "\nSimpleSynth::setMidiPitch - "
      << "setting midiPitch:" << midiPitch << "\n";
    this->midiPitch = midiPitch;
    setFrequency(mtof(midiPitch));
  }//end if
  else {
    std::cout << "\nSynth::setMidiPitch - "
      << "new midiPitch is same pitch (rounded at cents)\n"
      << "current Pitch: " << this->midiPitch
      << "new pitch: " << midiPitch << "\n";
  }
}

//returns the current midiPitch
float SimpleSynth::getMidiPitch()
{
  return midiPitch;
}

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
void SimpleSynth::setFrequency(float frequency) {
  //do not except frequencies below 0 and above nyquist
  if(frequency > 0 || frequency < 0.5 * samplerate) {
    //call updateFrequency method to allow derived classes to update frequency
    sine.setFrequency((double)frequency);
  }
  else {
    std::cout << "\nSimpleSynth::setFrequency - "
      << "values above nyquist aren't allowed\n";
  }
}

//translates midi to frequency
float SimpleSynth::mtof(float midiPitch)
{
  return pow(2.0,(midiPitch-69.0)/12.0) * 440.0;
}
