#ifndef _H_SIMPLE_SYNTH_
#define _H_SIMPLE_SYNTH_

#include "synth.h"
#include "sine.h"

class SimpleSynth : public Synth {
public:
  //constructor
  SimpleSynth(float samplerate);
  SimpleSynth(float samplerate, float midiPitch);
  //prevent the default constructor to be generated
  SimpleSynth() = delete;
  //destructor
  ~SimpleSynth();
  //override base methods
  double getSample() override;
  void tick() override;

protected:
  void updateFrequency() override;

private:
  Sine sine;
};

#endif
