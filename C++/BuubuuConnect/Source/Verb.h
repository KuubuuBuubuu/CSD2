/*
  ==============================================================================

    Verb.h
    Created: 25 May 2019 7:13:56pm
    Author:  kayaw

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class Verb    : public Component
{
public:
    Verb();
    ~Verb();

    void paint (Graphics&) override;
    void resized() override;

	void setSampleRate(float sampleRate);

	void setLength(float length);
	void setMix(float mix);

	void reverberate(int numChannels, int numSamples, const AudioSourceChannelInfo& mainBuffer);

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Verb)
	Slider lengthSlider;
	Slider mixSlider;

	Label lengthLabel;
	Label mixLabel;
	Label reverbTitle;

	Reverb verb;
	Reverb::Parameters params;
};
