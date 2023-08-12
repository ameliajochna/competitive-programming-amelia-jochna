#include <bits/stdc++.h>
using namespace std;
using lf = long double;
using ll = long long;
using cll = const ll;
using cint = const int;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

int const maxN = 5e4 + 10;
int n, k;
set<pii> s;
set<int> G[maxN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();

  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int sz;
    cin >> sz;
    s.insert({sz, i});
    for (int j = 0; j < sz; j++) {
      int u;
      cin >> u;
      G[i].insert(u);
    }
  }

  int ans = 0;
  while (!s.empty()) {
    pii top = *s.begin();
    // dbg(top);
    int cur = top.nd;
    s.erase(s.begin());
    vector<int> v;
    while (!G[cur].empty()) v.pb(*G[cur].begin()), G[cur].erase(G[cur].begin());
    // dbg(v);
    int k = ss(v);
    for (int bt = 0; bt < (1 << k); bt++) {
      vector<int> subs;
      for (int j = 0; j < k; j++)
        if ((bt >> j) & 1) subs.pb(v[j]);  // v[j] nalezy do zbioru
      // dbg(subs);
      bool flag = true;
      for (int i = 0; i < ss(subs); i++) {
        for (int j = i + 1; j < ss(subs); j++) {
          if (!flag) break;
          int u = subs[i], w = subs[j];
          if (G[u].find(w) == G[u].end() || G[w].find(u) == G[w].end())
            flag = false;
        }
      }

      if (flag) ans = max(ans, __builtin_popcount(bt) + 1);
    }
    // usun k
    for (int u : v) {
      int sz = ss(G[u]);
      G[u].erase(cur);
      s.erase({sz, u});
      if (sz - 1 > 0) s.insert({sz - 1, u});
    }
  }
  cout << ans;
}
