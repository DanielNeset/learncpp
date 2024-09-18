#include <iostream>

using namespace std;

int main() {
  // Depending on the compiler implementations, a random value is possible stored at this memory address,
  // and 4 bytes are typically needed to store an int value.
  int value;

  // The value 2 is stored at the same memory address.
  value = 2;

  // Outputs the start of the memory address where the value 2 is stored.
  cout << "The memory address for value: " << &value << endl;
  // Outputs how many bytes are needed to store an int value at the current system
  cout << "Size of Value in bytes: " << sizeof(value) << endl;

  // Depending on the compiler implementation, might point to a random memory address.
  int *pointer;
  // Output the int value stored at possible a random memory address. Might cause segmentation fault.
  cout << "The pointer who point to a random memory address value: " << *pointer << endl;
  // Pointer not points to the memory address 0. This indicates that pointer does not point to a valid address.
  pointer = nullptr;
  // Pointer now points to the memory address of the value 2.
  pointer = &value;
  cout << "The value of the variable vaule: " << value << endl;
  // Changes the value at address that the pointer points to 4
  *pointer = 4;
  cout << "The new value of the variable vaule: " << *pointer << endl;

  // A reference must refer to a value!
  // reference is now a reference to value, and can be used as the value variable can be used.
  int &referece = value;
  cout << "Value of the reference: " << referece << endl;
  referece = 5;
  cout << "New value of variable value set by the reference: " << referece << endl;
  cout << "The value of the variable value: " << value << endl;
}
