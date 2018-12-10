#include <iostream>

class Vehicle {
protected:
  std::string brand;
  std::string name;

  int sizeX;
  int sizeY;
  int sizeZ;

  int R; // \
  int G; //  - 0 - 255
  int B; // /

public:
  Vehicle();
  Vehicle(std::string a, std::string b) : brand(a), name(b) {}

  int speed; // km/h

  int angleH; // 0=West 0.5=North 1=East 1.5=South
  int angleV; // 0=Front 0.5=Up 1=UpsideDown 1.5=Down

  int posX; // \
  int posY; //  - meters from mid of field.
  int posZ; // /
};
