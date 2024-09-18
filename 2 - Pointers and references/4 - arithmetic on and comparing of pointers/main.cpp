#include <iostream>

using namespace std;

int main() {

  // Addition on a pointer
  cout << "Adding 1 to a pointer." << endl;

  double table[5];
  double *pointer;

  pointer = table; // Pointer points to table[0]
  *pointer = 1.5;
  cout << "Setting the value of table[0] with the pointer: " << *pointer << endl;
  *(pointer + 1) = *pointer;
  cout << "Setting the value of table[1] with the pointer: " << table[1] << endl;
  table[1] = 5.0;
  pointer++;
  cout << "Changing where pointer points to in the memory address: " << *pointer << endl;

  // subtract from tow pointers
  cout << "Subtracting from pointers." << endl;

  // The string that is pointed to is constant.
  const char *text = "One example";
  // Set the start pointer to the same memory address as text.
  const char *start = text;

  // At the end the pointer points to the last character of the C-style string.
  while (*text != '\0')
    text++;

  // Subtract the length between the pointers.
  int length = text - start;
  cout << "Text length is: " << length << endl;

  // Comparing pointers
  cout << "Comparing pointers." << endl;

  int number[5];
  int *pointer1 = &number[1];
  int *pointer2 = &number[1];

  if (pointer1 == pointer2) {
    cout << "Pointer1 and Pointer2 points to the same memory address: " << pointer1 << endl;
  }

  pointer1++;
  if (pointer1 != pointer2) {
    cout << "Pointer1 and Pointer2 are no pointing to the same memory address: " << pointer1 << " : " << pointer2 << endl;
  }

  if (pointer1 >= pointer2) {
    cout << "Pointer1 points to a higher memory address:" << pointer1 << " : " << pointer2 << endl;
  }

  return 0;
}
