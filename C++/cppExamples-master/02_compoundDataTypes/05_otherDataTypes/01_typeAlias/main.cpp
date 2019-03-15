/*
You can create an alias of a type. For example when a type_name is long or
unclear, you can create an alias.

  typedef unsigned long uLong;
  typedef jack_default_audio_sample_t sampleT;

C++11 offers alias declarations:

  using uLong = unsigned long;

quote from http://www.cplusplus.com/doc/tutorial/other_data_types/:
"Both aliases defined with typedef and aliases defined with using are
semantically equivalent. The only difference being that typedef has certain
limitations in the realm of templates that using has not. Therefore, using
is more generic, although typedef has a longer history and is probably more
common in existing code.""
*/

#include <iostream>

int main()
{
  //define an alias of an unsigned long
  typedef unsigned long uLong;
  //create an unsigned long instance, using the alias
  uLong aNumber = 10;
  //aNumber = -10;

  std::cout << "Created an unsigned long variable, containing the value: "
    << aNumber << "\n";

  //define an alias of an unsigned int
  using  uInt = unsigned int;
  //create an unsigned int instance, using the alias
  uInt anotherNumber = 100;
  std::cout << "Created an unsigned int variable, containing the value: "
    << anotherNumber << "\n";

  //end program
  return 0;
} //main
