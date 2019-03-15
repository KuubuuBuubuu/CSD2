/*
See also example 01_basics/03_functions/x_functionWrapper_a

* ------ HANDS-ON TIPS ------
* Outcomment line 17 t/m 19. Before running the code: what will be printed
* to the the consoles?
* ---------------------------
*/

#include "audioManager.h"



int main()
{
  AudioManager audioManager;
  //set customProcess method, using a lambda functions
  audioManager.customProcess = [&]() {
    std::cout << "\nInside the customProcess function";
  };
  audioManager.init();


  audioManager.callback();

  //end program
  return 0;
} // main
