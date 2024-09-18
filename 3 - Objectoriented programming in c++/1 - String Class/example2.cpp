#include <iostream>

using namespace std;

int main() {
  string first_name = "Daniel";
  string middle_name = "Ove";
  string last_name = "Neset";

  string name = first_name + " " + middle_name + " " + last_name;
  cout << name << endl;

  name += ", NTNU Ålesund, Rom nr";
  cout << name << endl;
}
