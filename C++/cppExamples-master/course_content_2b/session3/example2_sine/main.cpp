#include <iostream>
#include "sine.h"
#include "writeToFile.h"

int main() {
  int samplerate = 44100;

  // create sine wave
  Sine sine(samplerate, 220);

  // write 1 second of samples to file
  WriteToFile fileWriter("output.csv", true);
  for(int i = 0; i < samplerate; i++) {
    fileWriter.write(std::to_string(sine.getSample()) + "\n");
    sine.tick();
  }

  // end of program
  return 0;
}
