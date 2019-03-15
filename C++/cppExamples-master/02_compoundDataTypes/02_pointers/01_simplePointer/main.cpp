#include <iostream>

/*
 * This main.cpp file contains a simple pointer example.
 *
 * below quoate from: http://www.cplusplus.com/doc/tutorial/pointers/
 * "Variables are stored in the computer's memory and can be accessed by their
 * identifier (their name). This way, the program does not need to care about
 * the physical address of the data in memory; it simply uses the identifier
 * whenever it needs to refer to the variable.
 *
 * For a C++ program, the memory of a computer is like a succession of
 * memory cells, each one byte in size, and each with a unique address.
 * These single-byte memory cells are ordered in a way that allows data
 * representations larger than one byte to occupy memory cells that have
 * consecutive addresses.
 *
 * This way, each cell can be easily located in the memory by means of
 * its unique address. For example, the memory cell with the address 1776
 * always follows immediately after the cell with address 1775 and precedes
 * the one with 1777, and is exactly one thousand cells after 776 and exactly
 * one thousand cells before 2776.
 *
 * When a variable is declared, the memory needed to store its value is
 * assigned a specific location in memory (its memory address).
 * Generally, C++ programs do not actively decide the exact memory addresses
 * where its variables are stored. Fortunately, that task is left to the
 * environment where the program is run - generally, an operating system
 * that decides the particular memory locations on runtime.
 * However, it may be useful for a program to be able to obtain the address
 * of a variable during runtime in order to access data cells that are at a
 * certain position relative to it.
 *
 * ------ HANDS-ON TIPS ------
 * • Add another variable, but use a different data type.
 * Can you first asign the pointer 'aPointer' to the address of x and then
 * reassign it to the address of your new variable?
 *
 * • Can you add a pointer and let it point to the pointer 'aPointer'?
 *
 * • if above works, try out the following, create a program that contains:
 *  - one pointer (pointer 1) that points to an integer
 *  - a second pointer (pointer 2) that points to a different type of variable
 *  - a third pointer (pointer 3) that can point to pointer 1, but can also be
 *    asigned to pointer 3
 *
 * ---------------------------
 */

int main() {
  //create a regular integer and assign the value 10
  int x = 10;
  std::cout << "\nThe interger x conains the value: " << x << std::endl;

  /*
   * The address of a variable can be obtained by preceding the name of
   * a variable with an ampersand sign (&), known as address-of operator. For example:
   */
  std::cout << "The integer x is stored at the address: " << &x << std::endl;

  //create a pointer and assign the address of integer x
  int* aPointer = &x;

  //The pointer aPointer contains the address of integer X
  std::cout << "\nThe pointer aPointer contains the value: " <<
                aPointer << std::endl;
  //The pointer aPointer is also stored at a specific location
  std::cout << "The address of aPointer is: " << &aPointer << std::endl;

  //The pointer aPointer contains the address of integer x and can be used to
  //acces the value stored at this address
  std::cout << "The pointer aPointer is pointing to the value: " <<
                *aPointer << std::endl;
}
