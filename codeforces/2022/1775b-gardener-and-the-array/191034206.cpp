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
  vector<vector<int> > inp(n);
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    inp[i].resize(k);
    for (int j = 0; j < k; j++) {
      cin >> inp[i][j];
      cnt[inp[i][j]]++;
    }
  }
  bool ans = false;
  for (int i = 0; i < n; i++) {
    bool ok = true;
    for (auto x : inp[i])
      if (cnt[x] == 1) ok = false;
    ans |= ok;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < inp[i].size(); j++) cnt[inp[i][j]]--;
  }
  if (ans)
    cout << "YES\n";
  else
    cout << "NO\n";
}

int32_t main() {
  int t;
  cin >> t;
  while (t--) solve();
  fast;
}
