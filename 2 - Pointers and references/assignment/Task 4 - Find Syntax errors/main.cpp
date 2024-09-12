#include <iostream>

using namespace std;

int main() {
  int a = 5;

  // Change int &b, this is because references in c++ must be initialized while pointers do not.
  int &b = a;
  int *c;

  // c =&b will work but it is a lot easier to read with
  c = &b;

  // Change *a = *b + *c, this is because "a" is not a pointer, one can only de-reference a pointer.
  a = b + *c;

  // Change &b = 2, this is because a reference cannot change the address it refers to.
  b = 2;
}
