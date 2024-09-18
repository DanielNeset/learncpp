#include <iostream>

using namespace std;

/**
 * Can use const int* pointer; Can point to an int, but cannot modify the int it points to. Can change where it points to.
 * Can use int* const pointer; Cannot change where the pointer point to, but can modify the data at that memory address it points to.
 * Can use const int* const pointer; Cannot change where the pointer points to, nor the modify the data it is pointed to.
 */

int main() {
  cout << "Point to constant data." << endl;

  int value = 5;
  const int *pointer = &value;

  cout << "Value before: " << *pointer << endl;

  // *pointer = 10; Error modifying a const location.
  value = 10;
  cout << "Value after: " << *pointer << endl;

  // Example 2
  cout << "Constant pointer to data." << endl;

  int value1 = 5;
  // int value2 = 10;
  int *const pointer2 = &value1;

  cout << "Value 1 before: " << *pointer2 << endl;
  // pointer2 = &value2; Error modifying since the pointer is constant.
  *pointer2 = 20;
  cout << "Value 1 after: " << *pointer2 << endl;

  // Example 3
  cout << "Constant pointer to constant data" << endl;

  int value4 = 5;
  const int *const pointer3 = &value4;

  // Can not change the where the pointer points to (Memory address), nor modify the value it is pointed to.
  cout << "Value: " << *pointer3 << endl;

  return 0;
}
