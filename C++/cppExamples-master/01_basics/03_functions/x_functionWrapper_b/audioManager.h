#ifndef _AUDIO_MANAGER_H_
#define _AUDIO_MANAGER_H_

#include <iostream>

class AudioManager {
public:
  void callback();
  void init();
  std::function <void()> customProcess;
private:
  void defaultProcess();
};

#endif
