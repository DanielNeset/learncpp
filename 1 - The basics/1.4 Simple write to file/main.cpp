/*
 * A c++ program that write the power of 2 to a .dat file
 */

#include <climits>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {

  const char filename[] = "twoExponent.dat";
  ofstream file;
  file.open(filename);
  if (!file) {
    cout << "Feil ved åpningen av utfil" << endl;
    exit(EXIT_FAILURE);
  }

  long int product = 1L;
  int exponent = 0;
  while (product <= LONG_MAX / 2L) {
    exponent++;
    product *= 2L;
    file << "The power of 2 in " << setw(4) << exponent << " is " << product << endl;
  }

  file.close();
}
