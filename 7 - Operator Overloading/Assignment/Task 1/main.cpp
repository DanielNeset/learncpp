#include "fraction.hpp"
#include <iostream>
#include <string>

using namespace std;

void print(const string &text, const Fraction &fraction) {
  cout << text << fraction.numerator << " / " << fraction.denominator << endl;
}

int main() {
  Fraction fraction1(10, 20);
  Fraction fraction2(5, 3);

  cout << "Fraction1 is 10/20 and Fraction2 is 5/3" << endl;

  print("Fraction1 + 10 = ", fraction1 + 10);
  print("10 + Fraction1 = ", 10 + fraction1);
  print("Fraction1 - 5 = ", fraction1 - 5);
  print("5 -Fraction1 = ", 5 - fraction1);

  /// ----- Theory -----
  /// How does this get interpreted
  cout << endl
       << "How this handle: 5 - 3 - fraction1 - 7 - fraction2" << endl;
  cout << "First takes 5 - 3 witch is = 2" << endl;
  print("Then takes 2 - fraction1(1/2) = ", 5 - 3 - fraction1);
  print("Then takes result(3/2) - 7 = ", 5 - 3 - fraction1 - 7);
  print("Then takes result(-11/2) - fraction2(5/3) = ", 5 - 3 - fraction1 - 7 - fraction2);

  /// In my understanding:
  /// First takes 5 - 3 = 2
  /// Then takes 2 - fraction1(1/2) = 3/2 || operator-(int, const fraction) -> integer - fraction
  /// Then takes result(3/2) - 7 = -11/2 || operation-(int) -> fraction - integer
  /// Then takes result(-11/2) - fraction2(5/3) = || operation-(fraction) -> result - fraction
}
