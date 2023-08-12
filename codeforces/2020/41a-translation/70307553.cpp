#include <bits/stdc++.h>

#include <iostream>
using namespace std;
string word, translation;

string revrerse(string word) {
  for (int i = 0; i <= (word.length()) / 2; i++)
    swap(word[i], word[word.length() - i - 1]);
  if (word.length() % 2 == 0)
    swap(word[word.length() / 2 - 1], word[word.length() / 2]);
  return word;
}

int main() {
  cin >> word;
  cin >> translation;
  if (revrerse(word) == translation)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
