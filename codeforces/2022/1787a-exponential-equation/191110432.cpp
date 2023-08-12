#include <bits/stdc++.h>
using namespace std;
#define fast                    \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
#define int long long
#define pb push_back
#define pii pair<int, int>
int const maxN = (int)2e5 + 10;
int cnt[maxN];

void solve() {
  int n;
  cin >> n;
  if (n & 1)
    cout << "-1\n";
  else
    cout << 1 << " " << n / 2 << '\n';
}

int32_t main() {
  int t;
  cin >> t;
  while (t--) solve();
  fast;
}
