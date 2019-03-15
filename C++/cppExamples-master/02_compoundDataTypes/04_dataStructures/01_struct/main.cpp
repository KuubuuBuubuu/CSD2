/*
  In C++ you can define your own types and create variables of those types.
  A data structure is an user-defined data type that groups other data elements
  (the members) together under one name.
  A structure is very useful when you need to group multiple elements together
  and don't need functions (also see "classes").
  In C++ a structure is just like a class, but defaults to public instead of
  private. You are allowed to add functions, but often a structure is used to
  only hold subvariables.
*/

#include <iostream>

struct note {
  int pitch;
  int velocity;
  float duration;
};

note createNote(int p, int vel, float dur)
{
  note newNote;
  newNote.pitch = p;
  newNote.velocity = vel;
  newNote.duration = dur;
  return newNote;
}

void displayNoteValues(note aNote)
{
    std::cout << "\npitch: " << aNote.pitch;
    std::cout << "\nvelocity: " << aNote.velocity;
    std::cout << "\nduration: " << aNote.duration << "\n";
}

int main()
{
  //create a note
  note cQuarterNote;
  cQuarterNote.pitch = 60;
  cQuarterNote.velocity = 80;
  cQuarterNote.duration = 1;
  //display note values
  displayNoteValues(cQuarterNote);

  //create another note with the createNote function
  note eSixteenthNote = createNote(64, 75, 0.5);
  //display note values
  displayNoteValues(eSixteenthNote);

  //end program
  return 0;
}
