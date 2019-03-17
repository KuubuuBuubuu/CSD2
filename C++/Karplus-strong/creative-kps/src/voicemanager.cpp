#include "../include/voicemanager.h"
#include <math.h>

using namespace std;

VoiceManager::VoiceManager(int maxVoices, double samplerate, string root) {
  this->maxVoices = maxVoices;
  this->samplerate = samplerate;
  voicePitch.resize(maxVoices);
  voiceLength.resize(maxVoices);
  if(root=="a") {
    this->rootPitch = 220 * pow(2, 0/12.0);
  }
  else if(root=="ais" || root=="bes") {
    this->rootPitch = 220 * pow(2, 1/12.0);
  }
  else if(root=="b") {
    this->rootPitch = 220 * pow(2, 2/12.0);
  }
  else if(root=="c") {
    this->rootPitch = 220 * pow(2, 3/12.0);
  }
  else if(root=="cis" || root=="des") {
    this->rootPitch = 220 * pow(2, 4/12.0);
  }
  else if(root=="d") {
    this->rootPitch = 220 * pow(2, 5/12.0);
  }
  else if(root=="dis" || root=="es") {
    this->rootPitch = 220 * pow(2, 6/12.0);
  }
  else if(root=="e") {
    this->rootPitch = 220 * pow(2, 7/12.0);
  }
  else if(root=="f") {
    this->rootPitch = 220 * pow(2, 8/12.0);
  }
  else if(root=="fis" || root=="ges") {
    this->rootPitch = 220 * pow(2, 9/12.0);
  }
  else if(root=="g") {
    this->rootPitch = 220 * pow(2, 10/12.0);
  }
  else if(root=="gis" || root=="as") {
    this->rootPitch = 220 * pow(2, 11/12.0);
  }
}

VoiceManager::~VoiceManager() {
}

void VoiceManager::addVoice() {
  voice++;
  currentVoice = voice % maxVoices;
}

void VoiceManager::removeVoice() {
  voice--;
  currentVoice = voice % maxVoices;
}

int VoiceManager::getVoice() {
  return currentVoice;
}

void VoiceManager::setPitch(int semitones) {
  voicePitch[currentVoice] = rootPitch * pow(2, semitones/12.0);
  voiceLength[currentVoice] = 1 / voicePitch[currentVoice] * samplerate;
}

double VoiceManager::getPitch() {
  return voicePitch[currentVoice];
}

double VoiceManager::getNoiseLength() {
  return voiceLength[currentVoice];
}
