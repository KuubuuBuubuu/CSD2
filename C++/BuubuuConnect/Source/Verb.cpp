/*
  ==============================================================================

    Verb.cpp
    Created: 25 May 2019 7:13:56pm
    Author:  kayaw

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Verb.h"
#include <string>

//==============================================================================
Verb::Verb()
{
	setSize(600, 200);
	reverbTitle.setText("Reverb", dontSendNotification);
	reverbTitle.setBounds(0, 0, 100, 20);
	params.damping = 0.5f;
	params.width = 0.5f;
	params.wetLevel = 0.0f;
	verb.setParameters(params);
	addAndMakeVisible(reverbTitle);

	/** Length */
	lengthSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
	lengthSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 20);
	lengthSlider.setRange(0, 100, 0.001);
	lengthSlider.onValueChange = [this]
	{
		params.roomSize = lengthSlider.getValue() / 100.0;
		verb.setParameters(params);
	};
	lengthSlider.setValue(0);
	lengthSlider.setTextValueSuffix("%");

	lengthLabel.setText("Length", dontSendNotification);
	lengthLabel.attachToComponent(&lengthSlider, false);

	addAndMakeVisible(lengthSlider);
	addAndMakeVisible(lengthLabel);

	/** Mix */
	mixSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
	mixSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 20);
	mixSlider.setRange(0, 100, 1);
	mixSlider.onValueChange = [this]
	{
		params.dryLevel = 1.0f - (mixSlider.getValue() / 100.0);
		params.wetLevel = mixSlider.getValue() / 100.0;
		verb.setParameters(params);
	};
	mixSlider.setValue(0);
	

	mixLabel.setText("Mix", dontSendNotification);
	mixLabel.attachToComponent(&mixSlider, false);

	addAndMakeVisible(mixSlider);
	addAndMakeVisible(mixLabel);
	

}

Verb::~Verb()
{
}

void Verb::paint (Graphics& g)
{
	g.setColour(Colours::darkslategrey);
	Line<float> bottomLine(Point<float>(0, getHeight()), Point<float>(1200, getHeight()));
	g.drawLine(bottomLine, 2.0);

	Line<float> sideLine(Point<float>(getWidth(), 0), Point<float>(getWidth(), getHeight()));
	g.drawLine(sideLine, 2.0);
	int i = 100-mixSlider.getValue();
	std::string suffix = "/";
	suffix += std::to_string(i);
	mixSlider.setTextValueSuffix(suffix);
}

void Verb::resized()
{
	lengthSlider.setBounds(100, 40, 150, 150);
	mixSlider.setBounds(250, 40, 150, 150);

}

void Verb::setSampleRate(float sampleRate)
{
	verb.setSampleRate(sampleRate);
}


void Verb::setLength(float length)
{
	lengthSlider.setValue(length);
}

void Verb::setMix(float mix)
{
	mixSlider.setValue(mix);
}

void Verb::reverberate(int numChannels, int numSamples, const AudioSourceChannelInfo& mainBuffer)
{
	/*for (int channel = 0; channel < numChannels; channel++)
	{
		float* const buffer = mainBuffer.buffer->getWritePointer(channel, mainBuffer.startSample);
		verb.processMono(buffer, numSamples);
	}*/

	float* const left = mainBuffer.buffer->getWritePointer(0, mainBuffer.startSample);
	float* const right = mainBuffer.buffer->getWritePointer(1, mainBuffer.startSample);
	verb.processStereo(left, right, numSamples);
	
}