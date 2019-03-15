#include <iostream>
#include <list>

class Effect {
public:
  Effect(std::string name) : effectName(name) {}
  std::string effectName;
  void process() {
    std::cout << "\n____ Effect - process - " << effectName << std::endl;
  }
};

int main ()
{
  std::list<Effect*> effectChain;
  Effect delay("delay");
  Effect lpf("LPF");
  effectChain.push_back(&delay);
  effectChain.push_back(&lpf);

  std::cout << "\n effectChain contains:";
  std::list<Effect*>::iterator it;
  for((it=effectChain.begin()); (it != effectChain.end()); it++) {
    (*it)->process();
  }

  //end program
  std::cout << std::endl;
  return 0;

}
