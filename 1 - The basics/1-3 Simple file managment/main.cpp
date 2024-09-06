/*
 * A simple file reading c++ program that read a .dat
 * file sums up the total sum.
 */

#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
  const char filename[] = "numberFile.dat"; // File name
  ifstream file;
  file.open(filename); // Open the file
  if (!file) {
    cout << "Error opening file." << endl;
    exit(EXIT_FAILURE);
  }

  int number;
  int sum = 0;
  while (file >> number) { // Read until end of file.
    sum += number;
  }
  cout << "Total sum is: " << sum << endl;
  file.close();
}
