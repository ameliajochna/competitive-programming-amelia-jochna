#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

void solve() {
  ll n, k;
  cin >> n >> k;
  ll ans = (n * k) / (n - 1);
  if ((n * k) % (n - 1) == 0) ans--;
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solve();

  return 0;
}
