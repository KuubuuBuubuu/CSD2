#include <iostream>
#include "vehicle.hpp"
using namespace std;

class Car : public Vehicle {
public:
  Car();
  ~Car();
  Car(string a, string b) : Vehicle(a,b) {}

  void ride();
  void accellerate();
};
