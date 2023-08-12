#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int j = 1;
  while (a[j] >= 0 && j <= n) j++;
  for (int i = min(0, j - 1); i < n - 1; i++) {
    if (a[i] > 0) {
      while (a[i] != 0 && j < n) {
        // cout<<i<<" "<<j<<'\n';
        if (j > i) {
          // cout<<a[i]<<" "<<a[j]<<'\n';
          if (abs(a[j]) < a[i]) {
            a[i] += a[j];
            a[j] = 0;
          } else {
            a[j] += a[i];
            a[i] = 0;
          }
        }
        while ((a[j] >= 0 || j <= i) && j < n) j++;
      }
    }
  }
  ll ans = 0;
  for (int i = 0; i < n; i++)
    if (a[i] > 0) ans += a[i];
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solve();
}
