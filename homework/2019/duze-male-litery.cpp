#include <iostream>

using namespace std;

int main() {
  int small, big, w;
  string word;
  small = 0;
  big = 0;
  cin >> word;
  for (int i = 0; i < word.length(); i++) {
    w = word[i];
    if (w > 90)
      small++;
    else
      big++;
  }
  cout << small << " " << big;
  return 0;
}
