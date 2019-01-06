#include <iostream>
#include <time.h>
#include "MelodyGenerator.h"

using namespace std;

MelodyGenerator::MelodyGenerator(int bpm, int noteAmount, string root, string scale) :
 bpm(bpm), noteAmount(noteAmount), root(root), scale(scale)
{
  cout << "\nInside MelodyGenerator(int bpm, int noteAmount, string root, string scale)"
    << "\nbpm: " << bpm
    << "\nnoteAmount: " << noteAmount
    << "\nkey: " << root << " " << scale << "\n\n";

    if(root == "a")
    {
      this->rootMidiValue = 57;
    }
    else if(root == "ais" || root == "bes")
    {
      this->rootMidiValue = 58;
    }
    else if(root == "b")
    {
      this->rootMidiValue = 59;
    }
    else if(root == "c")
    {
      this->rootMidiValue = 60;
    }
    else if(root == "cis" || root == "des")
    {
      this->rootMidiValue = 61;
    }
    else if(root == "d")
    {
      this->rootMidiValue = 62;
    }
    else if(root == "dis" || root == "es")
    {
      this->rootMidiValue = 63;
    }
    else if(root == "e")
    {
      this->rootMidiValue = 64;
    }
    else if(root == "f")
    {
      this->rootMidiValue = 65;
    }
    else if(root == "fis" || root == "ges")
    {
      this->rootMidiValue = 66;
    }
    else if(root == "g")
    {
      this->rootMidiValue = 67;
    }
    else if(root == "gis" || root == "as")
    {
      this->rootMidiValue = 68;
    }

  if (scale=="major")
  {
    pitchList = {-3, -1, 0, 2, 4, 5, 7, 9};
  }
  else if(scale=="minor")
  {
    pitchList = {-4, -2, 0, 2, 3, 5, 7, 8};
  }
  else
  {
    cout << "...How about minor? :D\n\n";
    pitchList = {-4, -2, 0, 2, 3, 5, 7, 8};
  }
}

MelodyGenerator::~MelodyGenerator()
{
  cout << "\nInside MelodyGenerator::~MelodyGenerator";
}


//go to next note
void MelodyGenerator::generate()
{
  srand(time(0));

  pitch.push_back(pitchList[step] + rootMidiValue);

  for (int x=0; x <= (noteAmount-1); x++)
  {
    randomStep = rand() %3 -1;
    step += randomStep;


    if (step < 0)
    {
      step=1;
    }
    else if (step>7)
    {
      step=6;
    }

    pitch.push_back(pitchList[step] + rootMidiValue);


    int randomLength = rand() %4 + 1;
    if(randomLength == 4)
    {
      randomLength=8;
    }
    noteLength.push_back(randomLength);


    //debugging
    cout << "Pitch: " << pitch[x]
    << "\nLength: " << noteLength[x] << "\n\n";
  }
}


void MelodyGenerator::setRoot(string root)
{

}
