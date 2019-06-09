# Buubuu Connect
## A Virtual Audio Mixer/Router Software
###### Prototype version

This is a **prototype** of the Buubuu Connect application.
Buubuu Connect provides a JUCE-made virtual audio mixer, with a *compressor*, *graphic equalizer*, and *reverb* built internally.
This application is meant for streamers, that searches for fun effects on their voices. This app focuses on two aspects:

* *Simplicity*: This application is an all-in-one program, that's way easier to set up, than through a DAW with options like Jack and/or Virtual Audio Cable.
* *Efficiency*: Due to this processing audio effects internally, it's able to keep latency lower than alternatives like the one mentioned above.

## Building
To build this program, you need [Projucer](https://shop.juce.com/get-juce/download) to open .jucer files.
Open the .jucer file included in this folder, and build from there.

## Usage
If you open the .exe file (or .app for Mac or the Linux file) you start in the **Simple Mode**. Here you have 4 dials:

* **_Epicness:_**
Controls how deep and masculine your voice sounds. Varies from the dull real voice to a world full of explosions and stuff!

* **_Spaceyness: _**
Makes your voice float into space! Varies from your real room acoustics to being on some -probably illegal- pharmaceutics. Perfect if you need wayyyy too much depth!

* Robotifier:
This is for when you want to become the next T-Pain! Gives your voice perfect autotuned pitch in the key of C Major! (This dial is a placeholder; it's effect will be added in a later update)

* Pitch:
Changes your voice's pitch from very low to very high (This dial is also a placeholder, whose effect will be added in a later update.)

*(If you want to have more control over your effects, you can check the advanced tickbox in the upper right corner.)*

## What's Working?
- Compressor;
- 4-Band graphic EQ;
- Reverb;
- Having the Simple Mode dials change the effects' settings.

## Future plans
- Changing the file playback into live audio streaming;
- Making a virtual audio device, so you can select this as an input device (eg. in Discord);
- Pitch detection & Auto-Tune;
- Pitch-Shifting (without net data loss through oversampling);
- Settings save/load functions.
- Different time effects (Delay, Chorus, Flanger etc.);
- Visual Feedback with VU-Meters;
- Parametric EQ.
