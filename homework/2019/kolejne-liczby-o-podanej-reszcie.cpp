#include <iostream>
using namespace std;

int n, m, r, a, l;
int main() {
  cin >> n;
  cin >> m;
  cin >> r;
  l = 0;
  a = l * m + r;
  while (a <= n) {
    cout << a << " ";
    l++;
    a = l * m + r;
  }
  return 0;
}
