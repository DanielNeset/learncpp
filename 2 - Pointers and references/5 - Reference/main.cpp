#include <iostream>

using namespace std;

int main() {
  int number;
  int &ref = number;

  ref = 5;
  number++;
  cout << "Number is: " << number << " And is referenced from: " << &ref << endl;
}
