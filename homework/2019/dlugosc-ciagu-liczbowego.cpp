#include <iostream>
using namespace std;
int a, l;

int main() {
  a = 1;
  l = 0;
  while (!(a == -1)) {
    cin >> a;
    l++;
  }
  l--;
  cout << l;
  return 0;
}
