#include <cctype>   //Char utilities
#include <cstring>  //String utilities
#include <iostream> //Reading and Writing

using namespace std;

int main() {
  char text[5];             // String with max length of 5
  cout << "Write a word: "; // Write to terminal
  cin >> text;              // Read the user value

  for (int i = 0; i < strlen(text); i++) {
    text[i] = toupper(text[i]); // Convert to big letters
  }

  cout << "Only big letters: " << text << endl;

  for (int i = 0; i < strlen(text); i++) {
    text[i] = tolower(text[i]); // Convert to small letters
  }

  cout << "Only low letters: " << text << endl;
}

/*
 * Will get an error since we are comparing size_t to int, can avoid by
 * using size_t instead of int i in the for loop.
 */
