#include <iostream>
#include <sstream>

using namespace std;

string intToString(int number) {
  ostringstream oss;
  oss << number;
  return oss.str();
}

int main() {
  istringstream iss;
  int int_number;
  double double_number;

  iss.str("10 10.25");
  iss >> int_number;
  iss >> double_number;

  cout << "int_number: " << int_number << " double_number: " << double_number << endl;
  cout << "int_number as a string: " << intToString(int_number) << endl;
}
