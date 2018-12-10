#include <iostream>

class Bicycle{
  void pedal();
};

void Bicycle::pedal(){
  std::cout << "pedal pedal pedal\n";

}

int main(){
  std::cout << "\nCreating a Bicycle object.\n";
}
