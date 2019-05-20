#include "../include/voicemanager.h"
#include <math.h>

using namespace std;

VoiceManager::VoiceManager(int maxVoices, double samplerate) {
  this->maxVoices = maxVoices;
  this->samplerate = samplerate;
  this->rootPitch = 220 * pow(2, 3/12.0);
  kps.resize(maxVoices);
  for(int i=0; i < maxVoices; i++) {
    kps[i] = new Karplusstrong(220, 5000, samplerate, 0.98);
  }
  voicePitch.resize(maxVoices);
  voiceLength.resize(maxVoices);


}

VoiceManager::~VoiceManager() {
  for(int i = 0; i < maxVoices; i++) {
    delete kps[i];
  }
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

int VoiceManager::getMaxVoices() {
  return maxVoices;
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

void VoiceManager::moveIndexes() {
  for(int i=0; i < maxVoices; i++) {
    kps[i]->moveIndex();
  }
}

double VoiceManager::getSamples() {
  double sample;
  for(int i=0; i < maxVoices; i++) {
    sample += kps[i]->getSample() / 3.0;
  }
  return sample;
}

void VoiceManager::generateNoise(int voiceNum, double noiseLength) {
  kps[voiceNum]->generateNoise(noiseLength);
}

void VoiceManager::increaseOctave() {
  rootPitch *= 2.0;
  //cout << "rootPitch: " << rootPitch << endl;
}

void VoiceManager::decreaseOctave() {
  rootPitch /= 2.0;
  //cout << "rootPitch: " << rootPitch << endl;
  }

void VoiceManager::transposeUp() {
  rootPitch *= pow(2, 1/12.0);
}

void VoiceManager::transposeDown() {
  rootPitch *= pow(2, -1/12.0);
}
