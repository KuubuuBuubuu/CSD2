/*
  ==============================================================================

    EQ.h
    Created: 21 May 2019 6:39:47pm
    Author:  kayaw

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class EQ    : public Component
{
public:
    EQ();
    ~EQ();

    void paint (Graphics&) override;
    void resized() override;

	void setSub(float sub);
	void setBass(float bass);
	void setMids(float mids);
	void setTreble(float treble);

	void setSampleRate(float sampleRate);
	void updateFilter(float sampleRate);

	void process(int numChannels, int numSamples, const AudioSourceChannelInfo& mainBuffer);

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EQ)
	Label eqTitle;
	Slider subSlider;
	Slider bassSlider;
	Slider midSlider;
	Slider trebleSlider;

	Label subLabel;
	Label bassLabel;
	Label midLabel;
	Label trebleLabel;

	IIRFilter subFilterL;
	IIRFilter subFilterR;
	IIRFilter bassFilterL;
	IIRFilter bassFilterR;
	IIRFilter midFilterL;
	IIRFilter midFilterR;
	IIRFilter trebleFilterL;
	IIRFilter trebleFilterR;
	

	IIRCoefficients coeffs;

	float sampleRate = 44100;
	float subGain = 1;
	float bassGain = 1;
	float midGain = 1;
	float trebleGain = 1;

};
