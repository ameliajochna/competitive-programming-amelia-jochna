#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) cin >> p[i];
  reverse(p.begin(), p.end());
  for (auto a : p) cout << a << " ";
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solve();
}
