/*

 Audio File Player - Read in an audio file and send it to your speaker.
 Copyright (C) 2016 Dsperados <info@dsperados.com>

 This work is free. You can redistribute it and/or modify it under the
 terms of the Do What The Fuck You Want To Public License, Version 2,
 as published by Sam Hocevar. See the LICENSE file for more details.

 ---------------------------------------------------------------------

 This example shows you how to read in an audio file from disk, extract
 some meta-data from it, and then stream its actual sample content to your
 speakers.

 */

#include <bear/Audio/File.hpp>
#include <bear/Audio/Output.hpp>
#include <iostream>

using namespace bear;
using namespace std;
using namespace unit;

int main()
{
    // Open an audio file
    // Fill in the path to audiofile:
    string path = "/Users/ciska/CODE/_cpp/bearAudio/bear-examples/filePlayerTest/rotatingMarble.wav";
    audio::File file(path);

    // Get some information about this file
    cout << "Number of channels: " << file.getChannelCount() << endl;
    cout << "Sampling rate: " << file.getSampleRate() << endl;
    cout << "Number of frames: " << file.getFrameCount() << endl;
    cout << "Format: " << file.getFormat() << " (" << file.getSubFormat() << ")" << endl;
    cout << "Duration: " << file.getFrameCount() / (double)file.getSampleRate() << endl;

    // Set-up audio stream (see "Audio Output" example for more on this)
    auto& output = audio::Output::getDefaultOutput();
    output.onOutput = [&](auto outputs, auto numChannels, auto numFrames)
    {
        // Iterator over all samples in the buffer
        for (auto frame = 0; frame < numFrames; ++frame)
        {
            // Read the next frame from the file
            auto data = file.readFrameFloat();

            // Copy the necessary amount of channels over into the audio output buffer
            for (auto channel = 0; channel < min(data.size(), numChannels); ++channel)
                outputs[channel][frame] = data[channel];
        }
    };

    // Start the audio stream
    output.start();

    // Wait until enter was pressed
    cout << "press return/enter to quit" << endl;
    cin.get();

    // Stop the audio stream
    output.stop();

    return 0;
}
