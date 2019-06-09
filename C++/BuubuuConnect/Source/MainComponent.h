/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Compressor.h"
#include "EQ.h"
#include "Verb.h"
#include <math.h>

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent   : public AudioAppComponent,
						public ChangeListener
{
public:
    //==============================================================================
	MainComponent();
    ~MainComponent();

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    //==============================================================================
    void paint (Graphics& g) override;
    void resized() override;

	float lastSampleRate;

private:
    //==============================================================================
    // Your private member variables go here...


	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
	/* SimpleMode Components */
	Slider dramaSlider;
	Label dramaLabel;
	Label dramaLow;
	Label dramaHigh;

	Slider spaceySlider;
	Label spaceyLabel;
	Label spaceyLow;
	Label spaceyHigh;

	Slider humanSlider;
	Label humanLabel;
	Label humanLow;
	Label humanHigh;

	Slider pitchSlider;
	Label pitchLabel;

	/* Player Components */
	TextButton openButton;
	TextButton playButton;
	TextButton stopButton;

	void openButtonClicked();
	void playButtonClicked();
	void stopButtonClicked();

	enum transportState
	{
		Stopped,
		Starting,
		Stopping,
		Playing
	};

	transportState state;
	void transportStateChanged(transportState newState);
	void changeListenerCallback(ChangeBroadcaster* source) override;

	AudioFormatManager manager;
	std::unique_ptr<AudioFormatReaderSource> playSource;
	AudioTransportSource transport;



	/* Effect Components */
	Compressor comp;
	EQ eq;
	Verb reverb;
	ToggleButton modeSwitch;
	

	double pitch = 0.5;
};