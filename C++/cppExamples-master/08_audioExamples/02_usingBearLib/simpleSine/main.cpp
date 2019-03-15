#include <bear/Audio/Output.hpp>
#include <iostream>
#include <cmath>

using namespace bear;
using namespace std;
using namespace unit;

/*
 * Using the bear-audio library, documentation:
 * http://api.dsperados.com/bear/audio/annotated.html
 */

int main(int argc, const char * argv[]) {
  //get bear audio output object
  auto& output = audio::Output::getDefaultOutput();


  /*
   * http://api.dsperados.com/bear/audio/classbear_1_1audio_1_1_output.html#aabb3549a6c52cc8fbcb4fbcfd2ef36df
   * output.onOuput -> Callback that will be used to provide new audio samples.
   * After calling start() this function will continually be polled for new
   * audio samples. This process can be stopped by calling stop().
   * parameters:
   * outputs - data Array to write the samples to, in [channel][frame] order
   * channelCount - numChannels The number of channels in the data, aka the size of its first dimension
   * frameCount - numFrames The number of frames in the data, aka the size of its second dimension
   */
  //set callback function (using a labmda function, see \05_cpp11And14\01_lambdaFunction)
  output.onOutput = [&](auto outputs, size_t channelCount, size_t frameCount)
  {
    //retrieve sampleRate
    const auto sampleRate = output.getSampleRate();

    //Iterate over the frames
    //ouputs is ordered in channels, then samples.
    //In this example we first take a frame (all channels at the same moment)
    //then iterate over the channels
    for (auto frame = 0; frame < frameCount; ++frame)
    {
      //Generate the new output sample
      //TODO - make static example project
      //static double phase -> phase is global but only visible inside scope of
      //this forloop.
      static double phase = 0;
      auto sample = sin(phase);

      //Increase the phase for next round
      phase += 220 / sampleRate * 2 * M_PI;
      if (phase >= 2 * M_PI)
        phase -= 2 * M_PI;

      //Iterate over the channels
      for (auto channel = 0; channel < channelCount; ++channel) {
        outputs[channel][frame] = sample * 0.4;
      }
    }
  };

  output.start();

  bool running = true;
  while (running)
  {
      switch (cin.get())
      {
          case 'q': running = false; break;
      }
  }

  // Stop the output stream
  output.stop();

  return 0;
}
