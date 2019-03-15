#include <iostream>


/*
* With a pointer you can store a reference to a function.
* Instead of using a pointer you can also store a function reference in
* a std::function wrapper. See example "\03_functions\x_functionWrapper"
* ------ HANDS-ON TIPS ------
* • Create another function that returns an int and takes 1 int as parameter.
*   Assign this new function to the alternateNumber function pointer.
*   Run it, using this pointer.
*
* • Create two functions following the same signature that differ from the
*   alternateNumber function signature.
*   Create a function pointer, according to the signature of these 2 functions.
*   Assign the functions to the pointer and run them using the function pointer.
* ---------------------------
*/

//adds 1 to the passed number and returns the new value
int addOne(int aNumber) {
  return ++aNumber;
}

//adds 1 to the passed number and returns the new value
int multiplyByTen(int aNumber) {
  return aNumber * 10;
}

int main()
{
    std::cout << "We assign the function addOne "
      << "to the alterateNumber function pointer\n";
    int (*alterateNumber)(int);
    alterateNumber = &addOne;

    /* call alterateNumber (you do not need to write (*alterateNumber)(2) ) */
    std::cout << "The function alterateNumber returns "
      << alterateNumber( 2 ) << " when we pass 2.\n";
    /* (but if you want to, you may)*/
    std::cout << "The function alterateNumber returns "
      << (*alterateNumber)( 4 ) << " when we pass 4.\n";

    std::cout << "\nWe assign the function multiplyByTen "
      << "to the alterateNumber function pointer\n";
      alterateNumber = &multiplyByTen;

    /* call alterateNumber (you do not need to write (*alterateNumber)(2) ) */
    std::cout << "The function alterateNumber returns "
      << alterateNumber( 2 ) << " when we pass 2.\n";
    /* (but if you want to, you may)*/
    std::cout << "The function alterateNumber returns "
      << (*alterateNumber)( 4 ) << " when we pass 4.\n";

    return 0;
}
