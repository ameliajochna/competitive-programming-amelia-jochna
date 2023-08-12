#include <bits/stdc++.h>
using namespace std;
#define fast                    \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
#define int long long
#define pb push_back
#define pii pair<int, int>

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  int prefsum = 0, minn = 0, maxx = 0;
  for (int i = 0; i < n; i++) {
    prefsum += v[i];
    maxx = max(prefsum, maxx);
    minn = min(prefsum, minn);
  }
  cout << maxx - minn << '\n';
}

int32_t main() {
  int t;
  cin >> t;
  while (t--) solve();
  fast;
}
