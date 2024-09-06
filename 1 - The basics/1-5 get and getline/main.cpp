/*
 * Trying to use the getline() and get();
 *
 * If we would note use get on age, the position would be an \n
 * since it would take it as the end of the line.
 */

#include <iostream>

using namespace std;

const int max_line_length = 81;

int main() {
  char name[max_line_length];
  char address[max_line_length];
  int age;
  char position[max_line_length];

  cout << "Name: ";
  cin.getline(name, max_line_length);
  cout << "Address: ";
  cin.getline(address, max_line_length);
  cout << "Age: ";
  cin >> age;
  cin.get(); // Remove the new line \n
  cout << "Position: ";
  cin.getline(position, max_line_length);

  cout << name << endl
       << address << endl
       << age << endl
       << position << endl;
}
