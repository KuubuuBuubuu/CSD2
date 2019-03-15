#include <iostream>
using namespace std;

int main(int argc, char **argv) {
  cout << endl << "The main function contains to parameters:" << endl;
  cout << "\t- int argc\n\t- char **argv" << endl;
  cout << endl << "The argument argc represents the size of argv." << endl;
  cout << "The string at argv's first element (argv[0]) represents the program name." << endl;
  cout << "When argc > 1, argv[1] through argv[argc - 1] represent the program parameters." << endl;

  cout << endl << "Try calling this programm with different parameters from the command line." << endl;

  //loop through all arguments
  cout << endl << "argc contains: " << argc << endl;
  for(int i = 0; i < argc; i++) {
    cout  << "argv at index " << i << " contains: ";
    cout  << argv[i] << std::endl;
  }

  //exit the programm
  return 0;
};
