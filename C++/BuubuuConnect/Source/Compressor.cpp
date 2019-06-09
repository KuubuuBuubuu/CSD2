/*
  ==============================================================================

    Compressor.cpp
    Created: 21 May 2019 6:40:05pm
    Author:  kayaw

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Compressor.h"
#include <math.h>

//==============================================================================
Compressor::Compressor()
{
	setSize(1200, 200);
	compTitle.setText("Compressor", dontSendNotification);
	compTitle.setBounds(0, 0, 100, 20);
	addAndMakeVisible(compTitle);

	/** Threshold */
	thresholdSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
	thresholdSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 20);
	thresholdSlider.setRange(-144, 0, 1);
	thresholdSlider.setSkewFactorFromMidPoint(-18);
	thresholdSlider.setValue(0);
	thresholdSlider.setTextValueSuffix(" dB");
	thresholdSlider.onValueChange = [this]
	{
		thresholdValue = Decibels::decibelsToGain(thresholdSlider.getValue());
		DBG(thresholdValue);
	};

	thresholdLabel.setText("Threshold", dontSendNotification);
	thresholdLabel.attachToComponent(&thresholdSlider, false);

	addAndMakeVisible(thresholdSlider);
	addAndMakeVisible(thresholdLabel);

	/** Ratio */
	ratioSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
	ratioSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 20);
	ratioSlider.setRange(1, 100, 0.1f);
	ratioSlider.setSkewFactorFromMidPoint(10);
	ratioSlider.setValue(1);
	ratioSlider.setTextValueSuffix(":1");
	ratioSlider.onValueChange = [this]
	{

	};

	ratioLabel.setText("Ratio", dontSendNotification);
	ratioLabel.attachToComponent(&ratioSlider, false);

	addAndMakeVisible(ratioSlider);
	addAndMakeVisible(ratioLabel);

	/** Attack */
	attackSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
	attackSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 20);
	attackSlider.setRange(1.0, 100.0, 1);
	attackSlider.setSkewFactorFromMidPoint(40);
	attackSlider.setValue(50.0);
	attackSlider.setTextValueSuffix(" ms");
	attackSlider.onValueChange = [this]
	{
		attackValue = attackSlider.getValue() * (sampleRate / 1000.0);
		DBG(attackValue);
	};

	attackLabel.setText("Attack", dontSendNotification);
	attackLabel.attachToComponent(&attackSlider, false);

	addAndMakeVisible(attackSlider);
	addAndMakeVisible(attackLabel);

	/** Release */
	releaseSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
	releaseSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 20);
	releaseSlider.setRange(1.0, 200.0, 1);
	releaseSlider.setSkewFactorFromMidPoint(80);
	releaseSlider.setValue(70.0);
	releaseSlider.setTextValueSuffix(" ms");
	releaseSlider.onValueChange = [this]
	{
		releaseValue = releaseSlider.getValue() * (sampleRate / 1000.0);
		DBG(releaseValue);
	};

	releaseLabel.setText("Release", dontSendNotification);
	releaseLabel.attachToComponent(&releaseSlider, false);

	addAndMakeVisible(releaseSlider);
	addAndMakeVisible(releaseLabel);

	/** Gain */
	gainSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
	gainSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 20);
	gainSlider.setRange(-20, 20, 1);
	gainSlider.setValue(0);
	gainSlider.setTextValueSuffix(" dB");
	gainSlider.onValueChange = [this]
	{
		gainValue = Decibels::decibelsToGain(gainSlider.getValue());
		DBG(gainValue);
	};

	gainLabel.setText("Gain", dontSendNotification);
	gainLabel.attachToComponent(&gainSlider, false);

	addAndMakeVisible(gainSlider);
	addAndMakeVisible(gainLabel);

	compressionAmount = 1.0;
}

Compressor::~Compressor()
{
}

void Compressor::paint (Graphics& g)
{
	g.setColour(Colours::darkslategrey);
	Line<float> line(Point<float>(0, getHeight()), Point<float>(1200, getHeight()));
	g.drawLine(line, 2.0f);
}

void Compressor::resized()
{
	thresholdSlider.setBounds(100, 40, 150, 150);
	ratioSlider.setBounds(250, 40, 150, 150);
	attackSlider.setBounds(400, 40, 150, 150);
	releaseSlider.setBounds(550, 40, 150, 150);
	gainSlider.setBounds(700, 40, 150, 150);

}

void Compressor::setSampleRate(float sampleRate)
{
	this->sampleRate = sampleRate;
}
void Compressor::setThreshold(float threshold)
{
	thresholdSlider.setValue(threshold);
}

void Compressor::setRatio(float ratio)
{
	ratioSlider.setValue(ratio);
}

void Compressor::setAttack(float attack)
{
	attackSlider.setValue(attack);
}

void Compressor::setRelease(float release)
{
	releaseSlider.setValue(release);
}

void Compressor::setGain(float gain)
{
	gainSlider.setValue(gain);
}

float Compressor::getThreshold()
{
	return thresholdSlider.getValue();
}

float Compressor::getRatio()
{
	return ratioSlider.getValue();
}

float Compressor::getAttack()
{
	return attackSlider.getValue();
}

float Compressor::getRelease()
{
	return releaseSlider.getValue();
}

float Compressor::getGain()
{
	return gainSlider.getValue();
}

void Compressor::compress(int numChannels, int numSamples, const AudioSourceChannelInfo& mainBuffer)
{
	for (int channel = 0; channel < numChannels; channel++)
	{
		float* const buffer = mainBuffer.buffer->getWritePointer(channel, mainBuffer.startSample);

		for (int sample = 0; sample < numSamples; sample++)
		{
			if (fabs(buffer[sample]) > thresholdValue)
			{
				if (compressionAmount < ratioSlider.getValue())
				{
					compressionAmount += (ratioSlider.getValue() / attackValue);
				}
				else
				{
					compressionAmount = ratioSlider.getValue();
				}
				
			}
			else if(fabs(buffer[sample]) <= thresholdValue)
			{

				if (compressionAmount > 1.0)
				{
					compressionAmount -= (ratioSlider.getValue() / releaseValue);
				}
				else
				{
					compressionAmount = 1.0;
				}
				
			}
			buffer[sample] *= thresholdValue + ((1 - thresholdValue) / compressionAmount);
			buffer[sample] *= gainValue;
		}
	}
}

void Compressor::update()
{
	thresholdValue = thresholdValue = Decibels::decibelsToGain(thresholdSlider.getValue());
	gainValue = 1.0;
}