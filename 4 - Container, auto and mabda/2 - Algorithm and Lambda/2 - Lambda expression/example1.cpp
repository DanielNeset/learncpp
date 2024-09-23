#include <iostream>

using namespace std;

int main() {
  int number = 1;
  auto print_number = [&number]() { // Get access thru a reference
    cout << number << endl;
  };
  print_number();
  number = 2;
  print_number();

  cout << endl;

  number = 1;
  auto print_number2 = [number]() { // Number is a copy.
    cout << number << endl;
  };
  print_number2();
  number = 2;
  print_number2();
}
