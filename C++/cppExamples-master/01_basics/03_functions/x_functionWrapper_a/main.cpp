#include <iostream>


/*
See also example "\02_compoundDataTypes\02_pointers\04_pointerToFunction"

quote from http://en.cppreference.com/w/cpp/utility/functional/function:
(since C++11)
Class template std::function is a general-purpose polymorphic function wrapper.
Instances of std::function can store, copy, and invoke any Callable target --
functions, lambda expressions, bind expressions, or other function objects,
as well as pointers to member functions and pointers to data members.

The stored callable object is called the target of std::function.
If a std::function contains no target, it is called empty. Invoking the
target of an empty std::function results in std::bad_function_call exception
being thrown.

std::function satisfies the requirements of CopyConstructible and
CopyAssignable."
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
    std::function <int (int)>alterateNumber;
    std::cout << "We store the function addOne in the "
      << "function wrapper alterateNumber.\n";
    alterateNumber = addOne;

    // run alterateNumber
    std::cout << "The function alterateNumber returns "
      << alterateNumber( 2 ) << " when we pass 2.\n";

      std::cout << "We store the function multiplyByTen in the "
        << "function wrapper alterateNumber.\n";
      alterateNumber = multiplyByTen;

    // run alterateNumber
    std::cout << "The function alterateNumber returns "
      << alterateNumber( 2 ) << " when we pass 2.\n";

    return 0;
}
