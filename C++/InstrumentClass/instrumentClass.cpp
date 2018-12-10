#include <iostream>
#include "instrumentClass.h"

Instrument::Instrument(std::string type, std::string sound) {
  this->type = type;
  this->sound = sound;
}

void Instrument::makeSound(){
  std::cout << "\nThe " << type << " does " << sound << "." << std::endl;
} //makeSound
