#include <iostream>

using namespace std;

int main() {
  // Task a
  int i = 3;
  int j = 5;
  int *p = &i;
  int *q = &j;

  cout << "Address of i: " << &i << ", Value of i: " << i << endl;
  cout << "Address of j: " << &j << ", Value of j: " << j << endl;
  cout << "Address stored in p: " << p << ", Value pointed to by p: " << *p << endl;
  cout << "Address stored in q: " << q << ", Value pointed to by q: " << *q << endl;

  // Task b

  *p = 7; // Set the value inside of address p to 7

  *q += 4; // Set the value inside of address q to 3 + 4

  *q = *p + 1; // Set the value inside of address q to 7 + 1

  p = q; // Set the pointer value of p to be same as q ( p point to the same place as q )

  cout << *p << " " << *q << endl; // Print out "8 8" since *q = 8 and p = q.

  return 0;
}
