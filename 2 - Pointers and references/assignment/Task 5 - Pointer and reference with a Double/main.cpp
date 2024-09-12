#include <iostream>

using namespace std;

int main() {

  double number;
  double *pointer = &number;
  double &reference = number;

  cout << "Pointer: " << *pointer << " Reference: " << &reference << endl;

  number = 10.5;
  cout << "Number: " << number << endl;

  *pointer = 5.5;
  cout << "Number: " << number << endl;

  reference = 3.5;
  cout << "Number: " << number << endl;

  return 0;
}
