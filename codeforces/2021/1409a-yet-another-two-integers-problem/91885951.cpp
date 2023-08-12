#include <bits/stdc++.h>
using namespace std;

void solve() {
  int a, b;
  cin >> a >> b;
  if (a < b) swap(a, b);
  if (a == b)
    cout << 0 << '\n';
  else
    cout << (a - b - 1) / 10 + 1 << '\n';
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
