#include <iostream>

using namespace std;

int main() {

  // Pointer points to the data cell that the number is inn, but *pointer points to its value.

  int number = 5;
  int *pointer;

  pointer = &number;

  cout << "Number: " << number << " Reference: " << &number << endl;
  cout << "Number: " << number << " Pointer: " << pointer << endl;

  *pointer = 6;

  cout << "Change the value that the pointer points to: " << *pointer << endl;
}
