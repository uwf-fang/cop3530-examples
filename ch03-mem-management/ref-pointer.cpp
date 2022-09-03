/**
 *  Compare reference and pointer types
 */
#include <iostream>
using namespace std;

// swap pointer version
void swap(int * ptr1, int * ptr2) {
  int tmp = *ptr1;
  *ptr1 = *ptr2;
  *ptr2 = tmp;
}

// swap ref version
// cleaner syntax
void swap(int & ref1, int & ref2) {
  int tmp = ref1;
  ref1 = ref2;
  ref2 = tmp;
}

// pointer to objects
void printLength(string * ptr1) {
  // ptr1->length() is a shorthand for (*ptr1).length()
  cout << "Length of the string: " << ptr1->length() << endl;
}

// ref to objects
void printLength(string & ref1) {
  cout << "Length of the string: " << ref1.length() << endl;
}

int main(int argc, char const *argv[])
{
  int a = 1;
  int b = 2;

  cout << "a = " << a << "; b = " << b <<endl;
  cout << "swap as pointer\n";
  swap(&a, &b);  // call pointer version, ptr1 = &a
  cout << "a = " << a << "; b = " << b <<endl;
  cout << "swap as reference\n";
  swap(a, b);  // call ref version, ref1 = a
  cout << "a = " << a << "; b = " << b <<endl;

  string str1 = "abc";
  string *ptr1 = &str1;

  printLength(ptr1);  // pointer, string * ptr1 = ptr1;
  printLength(&str1);  // pointer, string * ptr1 = &str1;
  printLength(str1);  // reference, string & ref1 = str1;

  return 0;
}
