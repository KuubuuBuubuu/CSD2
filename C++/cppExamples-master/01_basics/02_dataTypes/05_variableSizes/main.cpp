/*
  source: http://www.learncpp.com/cpp-tutorial/23-variable-sizes-and-the-sizeof-operator/
*/

/*
  the quote below is from Lynda.com
  https://www.lynda.com/C-tutorials/Understanding-data-types/
  When choosing a data type, try to choose the smallest possible type
  to hold the data values. This reduces the amount of memory,
  and increases the processing speed of our program.
*/

#include <iostream>
using namespace std;

int main()
{
  using namespace std;
  cout << "bool:\t\t" << sizeof(bool) << " bytes" << endl;
  cout << "char:\t\t" << sizeof(char) << " bytes" << endl;
  cout << "wchar_t:\t" << sizeof(wchar_t) << " bytes" << endl;
  cout << "char16_t:\t" << sizeof(char16_t) << " bytes" << endl; // C++11, may not be supported by your compiler
  cout << "char32_t:\t" << sizeof(char32_t) << " bytes" << endl; // C++11, may not be supported by your compiler
  cout << "short:\t\t" << sizeof(short) << " bytes" << endl;
  cout << "int:\t\t" << sizeof(int) << " bytes" << endl;
  cout << "long:\t\t" << sizeof(long) << " bytes" << endl;
  cout << "long long:\t" << sizeof(long long) << " bytes" << endl; // C++11, may not be supported by your compiler
  cout << "float:\t\t" << sizeof(float) << " bytes" << endl;
  cout << "double:\t\t" << sizeof(double) << " bytes" << endl;
  cout << "long double:\t" << sizeof(long double) << " bytes" << endl;

  cout << endl;
  cout << "you can also use the sizeof operator on a variable name" << endl;
  cout << "To display the size 'int x', we can call sizeof(x):" << endl;
  int x;
  cout << "x is " << sizeof(x) << " bytes" << endl;
  return 0;
}
