#ifndef _VOICEMANAGER_H_
#define _VOICEMANAGER_H_

#include <iostream>
#include <vector>

using namespace std;

class VoiceManager {
public:
  VoiceManager(int maxVoices, double samplerate, string root);
  ~VoiceManager();

  void addVoice();
  void removeVoice();
  int getVoice();

  void setPitch(int semitones);
  double getPitch();

  double getNoiseLength();

  void setRoot(string root);




private:
  double samplerate;
  int currentVoice;
  int voice;
  int maxVoices;
  double rootPitch;
  vector<double> voicePitch;
  vector<double> voiceLength;
};

#endif
