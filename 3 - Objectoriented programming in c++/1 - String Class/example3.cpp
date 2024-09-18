#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int main() {

  string word;

  cout << "Write a word, one for each line, exit with \"x\"" << endl;

  cin >> word;

  while (word != "x" && word != "X") {
    cout << word;
    for (size_t i = 0; i < word.length(); i++) {
      word[i] = toupper(word[i]);
    }

    cout << " Transformed: " << word << endl;

    cin >> word;
  }
}
