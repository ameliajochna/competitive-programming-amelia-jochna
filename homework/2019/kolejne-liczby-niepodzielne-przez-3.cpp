#include <iostream>
using namespace std;

int main(void) {
  int n = 1, a, l = 0;
  cin >> a;
  while (l < a) {
    if (n % 3 == 0) {
      n++;
    } else {
      cout << n << ' ';
      n++;
      l++;
    }
  }
  return 0;
}
