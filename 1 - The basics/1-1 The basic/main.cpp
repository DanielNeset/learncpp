#include <iostream> // Include the iostream lib.

using namespace std; // Using standard namespace.

int main() {

  int a;
  int b[3]; // A whole number with 3 elements.
  double c;

  cout << "a = " << a << ", c = " << c << endl; // Print out the text

  for (int i = 0; i < 5; i++) {
    cout << "i = " << i << " table element: " << b[i] << endl;
  }

  return 0;
}
