#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
using namespace std;
typedef long long ll;

void solution() {
  int n, k;
  cin >> n >> k;
  vector<ll> ac(n + 2), pos(k);
  for (int i = 0; i < k; i++) cin >> pos[i];

  for (int i = 0; i < k; i++) cin >> ac[pos[i]];

  vector<ll> ans(n + 2);
  set<ll> s;
  s.insert(1e18);
  for (ll i = 1; i <= n; i++) {
    if (ac[i] > 0) s.insert(ac[i] - i);
    ans[i] = (*s.begin()) + i;
  }
  s.clear();
  s.insert(1e18);
  for (ll i = n; i >= 1; i--) {
    if (ac[i] > 0) s.insert(ac[i] - n + i);
    ans[i] = min(ans[i], (*s.begin()) + (n - i));
  }
  for (ll i = 1; i <= n; i++) cout << ans[i] << " ";
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();
}
