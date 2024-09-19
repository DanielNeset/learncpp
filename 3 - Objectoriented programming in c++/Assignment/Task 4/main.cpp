#include <iostream>
#include <string>

using namespace std;

int main() {
  // Part a
  string word1, word2, word3;
  cout << "Enter three words: ";
  cin >> word1 >> word2 >> word3;

  // Part b
  string sentence = word1 + " " + word2 + " " + word3 + ".";
  cout << "Sentence: " << sentence << endl;

  // Part c
  cout << "Length of word1: " << word1.length() << endl;
  cout << "Length of word2: " << word2.length() << endl;
  cout << "Length of word3: " << word3.length() << endl;
  cout << "Length of sentence: " << sentence.length() << endl;

  // Part d
  string sentence2 = sentence;

  // Part e
  if (sentence2.length() > 11) {
    sentence2.replace(9, 3, "xxx");
  }
  cout << "Original sentence: " << sentence << endl;
  cout << "Modified sentence: " << sentence2 << endl;

  // Part f
  string sentence_start;
  if (sentence.length() >= 5) {
    sentence_start = sentence.substr(0, 5);
  }
  cout << "First 5 characters of the sentence: " << sentence_start << endl;

  // Part g
  size_t found = sentence.find("hallo");
  if (found != string::npos) {
    cout << "'hallo' found in sentence." << endl;
  } else {
    cout << "'hallo' not found in sentence." << endl;
  }

  // Part h
  size_t pos = 0;
  int amount = 0;
  cout << "Occurrences of 'er' location: ";
  while ((pos = sentence.find("er", pos)) != string::npos) {
    cout << " " << pos;
    pos++;
    amount++;
  }
  cout << endl;
  cout << "'er' found: " << amount << "." << endl;

  return 0;
}
