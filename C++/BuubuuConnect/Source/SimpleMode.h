/*
  ==============================================================================

    SimpleMode.h
    Created: 21 May 2019 6:39:04pm
    Author:  kayaw

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class SimpleMode    : public Component
{
public:
    SimpleMode();
    ~SimpleMode();

    void paint (Graphics&) override;
    void resized() override;


private:
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SimpleMode)
	Slider dramaSlider;
	Slider spaceySlider;
	Slider humanSlider;
	Slider pitchSlider;

	Label dramaLabel;
	Label spaceyLabel;
	Label humanLabel;
	Label pitchLabel;

	Label dramaLow;
	Label dramaHigh;
	Label spaceyLow;
	Label spaceyHigh;
	Label humanLow;
	Label humanHigh;
};
