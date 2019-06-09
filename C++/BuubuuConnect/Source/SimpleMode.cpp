/*
  ==============================================================================

    SimpleMode.cpp
    Created: 21 May 2019 6:39:04pm
    Author:  kayaw

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "SimpleMode.h"

//==============================================================================
SimpleMode::SimpleMode()
{
	setSize(1200, 350);

	/** Sliders */
	dramaSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
	dramaSlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
	dramaSlider.setRange(0, 100, 1);
	dramaSlider.setValue(0);
	dramaSlider.setTextValueSuffix(" %");

	spaceySlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
	spaceySlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	spaceySlider.setRange(0, 100, 1);
	spaceySlider.setValue(0);
	spaceySlider.setTextValueSuffix(" %");

	humanSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
	humanSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	humanSlider.setRange(0, 100, 1);
	humanSlider.setValue(0);
	humanSlider.setTextValueSuffix(" %");

	pitchSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
	pitchSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 20);
	pitchSlider.setRange(-12, 12, 1);
	pitchSlider.setValue(0);
	pitchSlider.setTextValueSuffix(" semitones");

	/** Labels */
	dramaLabel.setText("Epicness", dontSendNotification);
	dramaLabel.attachToComponent(&dramaSlider, false);
	spaceyLabel.setText("Spaceyness", dontSendNotification);
	spaceyLabel.attachToComponent(&spaceySlider, false);
	humanLabel.setText("Robotifier [PLACEHOLDER]", dontSendNotification);
	humanLabel.attachToComponent(&humanSlider, false);
	pitchLabel.setText("Pitch", dontSendNotification);
	pitchLabel.attachToComponent(&pitchSlider, false);

	dramaLow.setText("Dull", dontSendNotification);
	dramaHigh.setText("Michael Bay", dontSendNotification);
	spaceyLow.setText("Reality", dontSendNotification);
	spaceyHigh.setText("Trippin", dontSendNotification);
	humanLow.setText("Human", dontSendNotification);
	humanHigh.setText("0x45656570", dontSendNotification);

	dramaSlider.setBounds(0, 25, 300, 300);
	addAndMakeVisible(dramaSlider);
	spaceySlider.setBounds(300, 25, 300, 300);
	addAndMakeVisible(spaceySlider);
	humanSlider.setBounds(600, 25, 300, 300);
	addAndMakeVisible(humanSlider);
	pitchSlider.setBounds(900, 25, 300, 300);
	addAndMakeVisible(pitchSlider);

	addAndMakeVisible(dramaLabel);
	addAndMakeVisible(spaceyLabel);
	addAndMakeVisible(humanLabel);
	addAndMakeVisible(pitchLabel);

	dramaLow.setBounds(dramaSlider.getX() + 25, dramaSlider.getY() + dramaSlider.getHeight() - 30, 50, 20);
	addAndMakeVisible(dramaLow);
	dramaHigh.setBounds(dramaSlider.getX() + dramaSlider.getWidth() - 100, dramaSlider.getY() + dramaSlider.getHeight() - 30, 100, 20);
	addAndMakeVisible(dramaHigh);
	spaceyLow.setBounds(spaceySlider.getX() + 25, spaceySlider.getY() + spaceySlider.getHeight() - 30, 50, 20);
	addAndMakeVisible(spaceyLow);
	spaceyHigh.setBounds(spaceySlider.getX() + spaceySlider.getWidth() - 100, spaceySlider.getY() + spaceySlider.getHeight() - 30, 100, 20);
	addAndMakeVisible(spaceyHigh);
	humanLow.setBounds(humanSlider.getX() + 25, humanSlider.getY() + humanSlider.getHeight() - 30, 50, 20);
	addAndMakeVisible(humanLow);
	humanHigh.setBounds(humanSlider.getX() + humanSlider.getWidth() - 100, humanSlider.getY() + humanSlider.getHeight() - 30, 100, 20);
	addAndMakeVisible(humanHigh);
}

SimpleMode::~SimpleMode()
{
}

void SimpleMode::paint (Graphics& g)
{

	

	

	g.setColour(Colours::darkslategrey);
	Line<float> line(Point<float>(0, 350), Point<float>(1200, 350));
	g.drawLine(line, 2.0f);
}

void SimpleMode::resized()
{
    
}
