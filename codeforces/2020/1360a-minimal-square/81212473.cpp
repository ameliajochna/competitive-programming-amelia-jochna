#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
  int a, b;
  cin >> a >> b;
  int n = max(max(a, b), 2 * min(a, b));
  cout << ll(n * n) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solve();
}
