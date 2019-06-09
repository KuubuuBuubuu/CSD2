/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent() : state(Stopped)
{
	// Make sure you set the size of the component after
	// you add any child components.
	setSize(1200, 350);

	// Sliders //
	/* dramaSlider */
	dramaSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
	dramaSlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
	dramaSlider.setRange(0, 100, 1);

	dramaSlider.setTextValueSuffix(" %");
	dramaSlider.onValueChange = [this]
	{
		eq.setBass(dramaSlider.getValue() * 0.03);
		eq.setMids(0 - (dramaSlider.getValue() * 0.03));
		comp.setThreshold(0 - (dramaSlider.getValue() * 0.1));
		comp.setRatio(1 + dramaSlider.getValue() * 0.02);
		comp.setGain(dramaSlider.getValue() * 0.003);
		reverb.setLength((dramaSlider.getValue() * 0.1) + (spaceySlider.getValue() * 0.7));
		reverb.setMix((dramaSlider.getValue() * 0.2) + (spaceySlider.getValue() * (0.6 - (dramaSlider.getValue() * 0.002))));
	};
	dramaSlider.setValue(0);

	/* spaceySlider */
	spaceySlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
	spaceySlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	spaceySlider.setRange(0, 100, 1);
	spaceySlider.setTextValueSuffix(" %");
	spaceySlider.onValueChange = [this]
	{
		eq.setSub(0 - spaceySlider.getValue() * 0.03);
		eq.setTreble(0 - spaceySlider.getValue() * 0.03);
		comp.setAttack(50 + spaceySlider.getValue() * 0.3);
		comp.setRelease(30 + spaceySlider.getValue() * 0.6);
		reverb.setLength((dramaSlider.getValue() * 0.1) + (spaceySlider.getValue() * 0.85));
		reverb.setMix((dramaSlider.getValue() * 0.2) + (spaceySlider.getValue() * (0.6 - (dramaSlider.getValue() * 0.002))));
	};
	

	/* humanSlider */
	humanSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
	humanSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	humanSlider.setRange(0, 100, 1);
	humanSlider.setValue(0);
	humanSlider.setTextValueSuffix(" %");

	/* pitchSlider*/
	pitchSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
	pitchSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 20);
	pitchSlider.setRange(-12, 12, 1);
	pitchSlider.onValueChange = [this]
	{
		pitch = pow(2, (pitchSlider.getValue() / 12));
	};
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

	/** Positioning */
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


	addChildComponent(comp);
	addChildComponent(eq);
	addChildComponent(reverb);

	modeSwitch.setBounds(getRight() - 100, 0, 30, 20);
	modeSwitch.setButtonText("Advanced");
	modeSwitch.changeWidthToFitText();
	addAndMakeVisible(modeSwitch);
	modeSwitch.onStateChange = [this]
	{
		if (modeSwitch.getToggleState() == false)
		{
			comp.setVisible(false);
			eq.setVisible(false);
			reverb.setVisible(false);
			if (getHeight() != 350) {
				int growth = 16;
				for (int i = 750; i > 350; i-=growth) {
					setSize(1200, i);
					growth *= 2;
				}
			}
			setSize(1200, 350);
		}
		else if (modeSwitch.getToggleState() == true)
		{
			comp.setVisible(true);
			eq.setVisible(true);
			reverb.setVisible(true);
			if (getHeight() != 750) {
				int growth = 16;
				for (int i = 350; i < 750; i+=growth) {
					setSize(1200, i);
					growth *= 2;
				}
			}
			setSize(1200, 750);
		}
	};

	openButton.setBounds(0, getHeight() - 25, 25, 25);
	openButton.setButtonText("Open");
	openButton.changeWidthToFitText();
	openButton.onClick = [this] {openButtonClicked(); };
	addAndMakeVisible(openButton);
	 
	playButton.setBounds(openButton.getRight() + 10, getHeight() - 25, 25, 25);
	playButton.setButtonText("Play");
	playButton.changeWidthToFitText();
	playButton.onClick = [this] {playButtonClicked(); };
	addAndMakeVisible(playButton);

	stopButton.setBounds(playButton.getRight(), getHeight() - 25, 25, 25);
	stopButton.setButtonText("Stop");
	stopButton.changeWidthToFitText();
	stopButton.onClick = [this] {stopButtonClicked(); };
	addAndMakeVisible(stopButton);


	transport.addChangeListener(this);

	manager.registerBasicFormats();
	
    // Some platforms require permissions to open input channels so request that here
    if (RuntimePermissions::isRequired (RuntimePermissions::recordAudio)
        && ! RuntimePermissions::isGranted (RuntimePermissions::recordAudio))
    {
        RuntimePermissions::request (RuntimePermissions::recordAudio,
                                     [&] (bool granted) { if (granted)  setAudioChannels (2, 2); });
    }
    else
    {
        // Specify the number of input and output channels that we want to open
        setAudioChannels (2, 2);
    }
}

MainComponent::~MainComponent()
{
    // This shuts down the audio device and clears the audio source.
    shutdownAudio();
}


//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
	double playBackRate = sampleRate * pitch;
	comp.setSampleRate(playBackRate);
	eq.setSampleRate(playBackRate);
	reverb.setSampleRate(playBackRate);

	transport.prepareToPlay(samplesPerBlockExpected, playBackRate);
	
	dramaSlider.setValue(0);
	spaceySlider.setValue(0);
	
}

void MainComponent::openButtonClicked()
{
	//choose a file
	FileChooser chooser("Choose a WAV file.", File::getSpecialLocation(File::userDesktopDirectory), "*.wav;*.aiff", true, false);
	//if the user chooses a file
	if (chooser.browseForFileToOpen())
	{
		File myFile;
		//what did the user choose?
		myFile = chooser.getResult();
		//read the file
		AudioFormatReader* reader = manager.createReaderFor(myFile);

		if(reader != nullptr) 
		{
			//get the file ready to play
			std::unique_ptr<AudioFormatReaderSource> tempSource(new AudioFormatReaderSource(reader, true));

			transport.setSource(tempSource.get());
			transportStateChanged(Stopped);

			playSource.reset(tempSource.release());
		}

	}

}

void MainComponent::playButtonClicked()
{
	comp.update();
	transportStateChanged(Starting);
}

void MainComponent::stopButtonClicked()
{
	transportStateChanged(Stopping);

}

void MainComponent::transportStateChanged(transportState newState)
{
	if (newState != state)
	{
		state = newState;

		switch (state)
		{
		case Stopped:
			playButton.setEnabled(true);
			stopButton.setEnabled(false);
			transport.setPosition(0.0);
			break;

		case Starting:
			playButton.setEnabled(false);
			stopButton.setEnabled(true);
			transport.start();
			break;

		case Stopping:
			playButton.setEnabled(true);
			stopButton.setEnabled(false);
			transport.stop();
			break;

		case Playing:
			playButton.setEnabled(false);
			stopButton.setEnabled(true);
			break;

		}
	}
}

void MainComponent::changeListenerCallback(ChangeBroadcaster* source)
{
	if (source == &transport)
	{
		if (transport.isPlaying())
		{
			transportStateChanged(Playing);
		}
		else
		{
			transportStateChanged(Stopped);
		}
	}
}


void MainComponent::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
{
	bufferToFill.clearActiveBufferRegion();
	transport.getNextAudioBlock(bufferToFill);
	int channelAmount = bufferToFill.buffer->getNumChannels();
	int sampleAmount = bufferToFill.buffer->getNumSamples();
	
	comp.compress(channelAmount, sampleAmount, bufferToFill);
	eq.process(channelAmount, sampleAmount, bufferToFill);
	reverb.reverberate(channelAmount, sampleAmount, bufferToFill);


}

void MainComponent::releaseResources()
{
    // This will be called when the audio device stops, or when it is being
    // restarted due to a setting change.

    // For more details, see the help for AudioProcessor::releaseResources()
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

	g.setColour(Colours::darkslategrey);
	Line<float> line(Point<float>(0, 350), Point<float>(1200, 350));
	g.drawLine(line, 2.0f);
}

void MainComponent::resized()
{
	comp.setBounds(0, 350, 1200, 200);
	eq.setBounds(0, 550, 600, 200);
	reverb.setBounds(600, 550, 600, 200);
	
}