/*
  main.cpp
  Oktober 21, 2016
  Ciska Vriezenga
*/

/*
  A character is a so called primitive data type.
  Primitive data types are stored by value and not by reference.
  A character can present: letters, punctuation symbols, comparison operators

  the quote below is from Lynda.com
  https://www.lynda.com/C-tutorials/Understanding-data-types/
  The character data type is interesting, because it stores all characters,
  numbers, and symbols. As decimal values.
  For example, the letter capital A, is stored as the number 65.
  We can see the translation of all the codes using an ASCII code table,
  which provides the character and coding scheme, used universally
  by both programming languages.
*/

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
  //declare the variables
  int noteIndex;


  const char majorScaleC[] = {'c', 'd', 'e', 'f', 'g', 'a', 'b'};

  //ask user for a number from 1 till 7
  cout << "Please enter a whole number from 1 till 7:\n";
  cin >> noteIndex;

  //check if the user entered a number from 1 till 7
  if(noteIndex < 1 && noteIndex > 7){
    cout << "You entered an incorrect number.\n";
    cout << "Please re-run the programm and try again.\n";
    //exit the programm
    return 0;
  }

  //display the to the number corresponding note value in a C major scale
  cout << "Note number " << noteIndex << " in the C major scale is a ";
  cout << majorScaleC[noteIndex - 1] << ".\n";

  //exit the programm
  return 0;
}
