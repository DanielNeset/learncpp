#include <iostream>

using namespace std;

int main() {

  // Table that can hold 10 integers
  int table[10];

  // Point to the address of the fifth element of the table
  int *pointer = &table[4];

  table[2] = 5;
  cout << "Value of the third element in the table: " << table[2] << endl;

  pointer[3] = 8;
  cout << "Value of the forth element in the table: " << table[3] << endl;

  *pointer = 0;
  cout << "Value of the fifth element in the table: " << table[4] << endl;

  *table = table[2];
  cout << "Value of the first element in the table: " << table[0] << endl;
}
