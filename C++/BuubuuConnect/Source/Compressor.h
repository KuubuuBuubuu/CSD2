/*
  ==============================================================================

    Compressor.h
    Created: 21 May 2019 6:40:05pm
    Author:  kayaw

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class Compressor    : public Component
{
public:
	Compressor();
    ~Compressor();

    void paint (Graphics&) override;
    void resized() override;

	void setSampleRate(float sampleRate);

	void setThreshold(float threshold);
	void setRatio(float ratio);
	void setAttack(float attack);
	void setRelease(float release);
	void setGain(float gain);

	float getThreshold();
	float getRatio();
	float getAttack();
	float getRelease();
	float getGain();

	void compress(int numChannels, int numSamples, const AudioSourceChannelInfo& mainBuffer);
	void update();

private:
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Compressor)
	Slider thresholdSlider;
	Slider ratioSlider;
	Slider attackSlider;
	Slider releaseSlider;
	Slider gainSlider;

	Label thresholdLabel;
	Label ratioLabel;
	Label attackLabel;
	Label releaseLabel;
	Label gainLabel;
	Label compTitle;

	float maxValue;
	float thresholdValue;
	float attackValue;
	float releaseValue;
	float gainValue;
	float compressionAmount;
	float sampleRate;
};
