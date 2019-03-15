#include <iostream>
#include <fstream>
#include <sys/stat.h>
using namespace std;


bool fileExists(const std::string& filename)
{
  // create a variable of type "struct stat"
  struct stat buffer;
  //check if file exists
  if (stat(filename.c_str(), &buffer) != -1)
  {
    return true;
  }
  return false;
}

int main (int argc, char **argv) {
  // retrieve fileName
  std::string fileNamePrefix;
  if(argc > 1) {
    fileNamePrefix = argv[1];
  } else fileNamePrefix = "output";

  std::string fileNameExtension;
  if(argc > 2) {
    fileNameExtension = argv[1];
  } else fileNameExtension = "txt";

  std::string fileName = fileNamePrefix + "." + fileNameExtension;
  std::cout << "\n" << fileName << "\n";
  // does file already exists?
  if(fileExists(fileName))
  {
    std::cout <<  "\nFile already exists, do you want to overwrite it? y / n?\n";
    std::string answer;
    std::cin >> answer;
    if(answer != "y")
    {
      std::cout <<  "\nDO NOT OVERWRITE --> EXITING NOW!\n";
      return 0;
    }
  }

  // open file
  ofstream myfile (fileName);
  if (myfile.is_open())
  {
    // write to file
    myfile << "Adding the first line to the file.\n";
    myfile << "Another line.\n";
    myfile.close();
  }
  else cout << "Unable to open file";
  // end program
  return 0;
}
