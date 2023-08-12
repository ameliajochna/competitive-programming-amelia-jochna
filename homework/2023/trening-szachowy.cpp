#include <bits/stdc++.h>
using namespace std;
using lf = long double;
using ll = long long;
using cll = const ll;
using cint = const int;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

int const maxN = 150;
bool vis[maxN], blck[maxN];
int prnt[maxN], n, m;
vector<int> G[maxN], T[maxN];

void dfs(int u, int prev) {
  vis[u] = true;
  prnt[u] = prev;
  for (auto v : G[u])
    if (!vis[v]) dfs(v, u);
}

pii ansdfs(int u, int prev) {  // st- nie wybrane, nd-wybrane
  int sumyes = 1, sumno = 0;
  for (auto v : T[u]) {
    if (v == prev) continue;
    pii ans = ansdfs(v, u);
    sumyes += ans.st;
    sumno += max(ans.st, ans.nd);
  }
  if (blck[u]) return {sumno, 0};
  return {sumno, sumyes};
}

int calcdp() {
  pii ans = ansdfs(1, 1);
  return max(ans.st, ans.nd);
}

int main() {
  fast cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    G[u].pb(v);
    G[v].pb(u);
  }
  dfs(1, 1);
  for (int i = 1; i <= n; i++) {
    T[i].pb(prnt[i]);
    T[prnt[i]].pb(i);
  }
  vector<pii> opp;
  for (int i = 1; i <= n; i++) {
    for (auto v : G[i]) {
      if (prnt[i] == v || prnt[v] == i) continue;
      if (i > v)
        opp.pb({v, i});
      else
        opp.pb({i, v});
    }
  }
  sort(all(opp));
  opp.erase(unique(all(opp)), opp.end());

  int s = opp.size(), ans = 0;
  for (int i = 0; i < (1 << s); i++) {
    for (int j = 0; j < s; j++) {
      int p1 = ((i >> j) & 1);
      if (p1 == 0)
        blck[opp[j].st] = true;
      else
        blck[opp[j].nd] = true;
    }
    ans = max(ans, calcdp());

    for (int j = 0; j < s; j++) {
      int p1 = ((i >> j) & 1);
      if (p1 == 0)
        blck[opp[j].st] = false;
      else
        blck[opp[j].nd] = false;
    }
  }
  cout << ans << '\n';
}
