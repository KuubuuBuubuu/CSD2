#include "audioManager.h"

void AudioManager::callback()
{
  customProcess();
}


void AudioManager::init()
{
  std::cout << "\nInside AudioManager::init method.";
  if(customProcess) {
    std::cout << "\nThe customProcess method is assigned.";
  } else {
    //assign processChain method
    std::cout << "\nThe customProcess method is NOT assigned, "
      << "therefor assigning AudioManager::defaultProcess method.";
    AudioManager::customProcess = std::bind(&AudioManager::defaultProcess, this);
  }
}


void AudioManager::defaultProcess()
{
  std::cout << "\nInside AudioManager::defaultProcess method.";
}
