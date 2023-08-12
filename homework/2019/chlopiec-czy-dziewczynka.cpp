#include <stdio.h>

#include <iostream>
#define SUP       \
  cin.tie(NULL);  \
  cout.tie(NULL); \
  ios_base::sync_with_stdio(0)
using namespace std;
string imie;
int main() {
  cin >> imie;
  if (imie[imie.length() - 1] == 'a')
    cout << "dziewczynka";
  else
    cout << "chlopiec";
  return 0;
}
