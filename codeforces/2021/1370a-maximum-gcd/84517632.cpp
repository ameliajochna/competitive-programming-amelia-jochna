#include <bits/stdc++.h>
using namespace std;
int const maxN = 1e6 + 10;
void solution() {
  int n;
  cin >> n;
  for (int i = n / 2 + 2; i > 0; i--) {
    if (2 * i <= n) {
      cout << i << '\n';
      return;
    }
  }
  cout << 1 << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) solution();
  return 0;
}
