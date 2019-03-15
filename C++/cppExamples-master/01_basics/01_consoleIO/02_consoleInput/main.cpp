/*
main.cpp
Oktober 20, 2016
Ciska Vriezenga
*/

#include <iostream>
using namespace std;

int main()
{
  //declare variables
  string soundDescription;
  //ask user to give input
  cout << "Please enter a single word description of a sound:" << endl;
  cin >> soundDescription;

  //echo the soundDescription
  cout << "You hear a soft \"" << soundDescription << "\"" << endl;

  //exit the programm
  return 0;
}
