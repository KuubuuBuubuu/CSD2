/*
  ==============================================================================

    EQ.cpp
    Created: 21 May 2019 6:39:47pm
    Author:  kayaw

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "EQ.h"

//==============================================================================
EQ::EQ()
{
	setSize(600, 200);
	eqTitle.setText("Equaliser", dontSendNotification);
	eqTitle.setBounds(0, 0, 100, 20);
	addAndMakeVisible(eqTitle);

	/** Sub */
	subSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
	subSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 20);
	subSlider.setRange(-10, 10, 1);
	subSlider.setTextValueSuffix(" dB");
	subSlider.onValueChange = [this]
	{
		subGain = Decibels::decibelsToGain(subSlider.getValue());
		updateFilter(sampleRate);
	};
	subSlider.setValue(0);


	subLabel.setText("Sub", dontSendNotification);
	subLabel.attachToComponent(&subSlider, false);


	addAndMakeVisible(subSlider);
	addAndMakeVisible(subLabel);

	/** Bass */
	bassSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
	bassSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 20);
	bassSlider.setRange(-10, 10, 1);
	bassSlider.onValueChange = [this]
	{
		bassGain = Decibels::decibelsToGain(bassSlider.getValue());
		updateFilter(sampleRate);
	};
	bassSlider.setValue(0);
	bassSlider.setTextValueSuffix(" dB");

	bassLabel.setText("Bass", dontSendNotification);
	bassLabel.attachToComponent(&bassSlider, false);

	addAndMakeVisible(bassSlider);
	addAndMakeVisible(bassLabel);

	/** Mids */
	midSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
	midSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 20);
	midSlider.setRange(-10, 10, 1);
	midSlider.onValueChange = [this]
	{
		midGain = Decibels::decibelsToGain(midSlider.getValue());
		updateFilter(sampleRate);
	};
	midSlider.setValue(0);
	midSlider.setTextValueSuffix(" dB");

	midLabel.setText("Mids", dontSendNotification);
	midLabel.attachToComponent(&midSlider, false);

	addAndMakeVisible(midSlider);
	addAndMakeVisible(midLabel);

	/** Treble */
	trebleSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
	trebleSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 20);
	trebleSlider.setRange(-10, 10, 1);
	trebleSlider.onValueChange = [this]
	{
		trebleGain = Decibels::decibelsToGain(trebleSlider.getValue());
		updateFilter(sampleRate);
	};
	trebleSlider.setValue(0);
	trebleSlider.setTextValueSuffix(" dB");

	trebleLabel.setText("Treble", dontSendNotification);
	trebleLabel.attachToComponent(&trebleSlider, false);

	addAndMakeVisible(trebleSlider);
	addAndMakeVisible(trebleLabel);

}

EQ::~EQ()
{
}

void EQ::paint (Graphics& g)
{
	g.setColour(Colours::darkslategrey);
	Line<float> bottomLine(Point<float>(0, getHeight()), Point<float>(1200, getHeight()));
	g.drawLine(bottomLine, 2.0f);

	Line<float> sideLine(Point<float>(getWidth(), 0), Point<float>(getWidth(), getHeight()));
	g.drawLine(sideLine, 2.0f);
}

void EQ::resized()
{
	subSlider.setBounds(100, 40, 50, 150);
	bassSlider.setBounds(150, 40, 50, 150);
	midSlider.setBounds(200, 40, 50, 150);
	trebleSlider.setBounds(250, 40, 50, 150);

}

void EQ::setSub(float sub)
{
	subSlider.setValue(sub);
}

void EQ::setBass(float bass)
{
	bassSlider.setValue(bass);
}

void EQ::setMids(float mids)
{
	midSlider.setValue(mids);
}

void EQ::setTreble(float treble)
{
	trebleSlider.setValue(treble);
}

void EQ::setSampleRate(float sampleRate)
{
	this->sampleRate = sampleRate;
}


void EQ::updateFilter(float sampleRate)
{
	
	subFilterL.setCoefficients(coeffs.makeLowShelf(sampleRate, 75, 0.5, subGain));
	subFilterR.setCoefficients(coeffs.makeLowShelf(sampleRate, 75, 0.5, subGain));
	bassFilterL.setCoefficients(coeffs.makePeakFilter(sampleRate, 100, 0.5, bassGain));
	bassFilterR.setCoefficients(coeffs.makePeakFilter(sampleRate, 100, 0.5, bassGain));
	midFilterL.setCoefficients(coeffs.makePeakFilter(sampleRate, 900, 0.5, midGain));
	midFilterR.setCoefficients(coeffs.makePeakFilter(sampleRate, 900, 0.5, midGain));
	trebleFilterL.setCoefficients(coeffs.makeHighShelf(sampleRate, 8000, 0.5, trebleGain));
	trebleFilterR.setCoefficients(coeffs.makeHighShelf(sampleRate, 8000, 0.5, trebleGain));
}

void EQ::process(int numChannels, int numSamples, const AudioSourceChannelInfo& mainBuffer)
{
	
	float*  left = mainBuffer.buffer->getWritePointer(0, mainBuffer.startSample);
	float*  right = mainBuffer.buffer->getWritePointer(1, mainBuffer.startSample);
	subFilterL.processSamples(left , numSamples);
	subFilterR.processSamples(right, numSamples);
	bassFilterL.processSamples(left, numSamples);
	bassFilterR.processSamples(right, numSamples);
	midFilterL.processSamples(left, numSamples);
	midFilterR.processSamples(right, numSamples);
	trebleFilterL.processSamples(left, numSamples);
	trebleFilterR.processSamples(right, numSamples);

}