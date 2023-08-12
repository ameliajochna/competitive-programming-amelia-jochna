#include <bits/stdc++.h>
using namespace std;
#define nd second
#define st first
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int const maxN = 3e5 + 10, shift = (1 << 19), inf = INT_MAX;
pii segtree[2 * shift + 10];

void update(int u, pii val) {
  u += shift;
  segtree[u] = val;
  u /= 2;
  while (u) {
    segtree[u] = min(segtree[2 * u], segtree[2 * u + 1]);
    u /= 2;
  }
}

pii rmq(int l, int r) {
  l += shift, r += shift;
  pii ans = segtree[l];
  if (r == l) return ans;
  ans = min(ans, segtree[r]);
  while (r / 2 != l / 2) {
    if (l % 2 == 0) ans = min(ans, segtree[l + 1]);
    if (r % 2 == 1) ans = min(ans, segtree[r - 1]);
    l /= 2, r /= 2;
  }
  return ans;
}

void clear(int n) {
  for (int i = 0; i < n; i++) update(i, {inf, i});
}

void solve() {
  multiset<pii> s;
  int n, m;
  cin >> n >> m;
  vector<int> k(n), c(m);
  for (int i = 0; i < n; i++) cin >> k[i], k[i]--;

  for (int i = 0; i < m; i++) {
    cin >> c[i];
    update(i, {c[i], i});
  }

  for (int i = 0; i < n; i++) s.insert({c[k[i]], k[i]});

  ll sum = 0;

  for (auto i = s.rbegin(); i != s.rend(); i++) {
    pii cur = *i;
    pii rm = rmq(0, cur.nd);
    if (rm.st < cur.st) {
      sum += rm.st;
      update(rm.nd, {inf, rm.nd});
    } else
      sum += cur.st;
  }
  cout << sum << '\n';
  clear(n);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
