#include <iostream>

using namespace std;

int main() {
  // Working with the String object.
  string name("Daniel Neset");

  // Search for the first middle name.
  size_t first_space = name.find(" ", 0);
  // Create a new object with a space at the end.
  string middle_name = "Ove ";
  // Insert the middle name.
  name.insert(first_space + 1, middle_name);
  cout << "The full name is now: " << name << endl;
}
