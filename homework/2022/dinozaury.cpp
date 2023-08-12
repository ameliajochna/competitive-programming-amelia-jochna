#include <bits/stdc++.h>
using namespace std;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
#define int long long

int const maxN = (int)2e5 + 10, shift = (1 << 18);
vector<int> T[2][maxN];
vector<pii> edge[maxN];
vector<pii> qry[maxN];
ll preo[maxN], posto[maxN], segTree[2 * shift + 10], outpt[maxN];
int n, m, tmer;

void dfs1(int u, int v) {
  tmer++;
  preo[u] = tmer;
  for (auto x : T[1][u])
    if (x != v) dfs1(x, u);
  posto[u] = tmer;
}

void add(int l, int r, int val) {
  l += shift, r += shift;
  segTree[l] += val;
  if (l == r) return;
  segTree[r] += val;
  while (l / 2 != r / 2) {
    if (l % 2 == 0) segTree[l + 1] += val;
    if (r % 2 == 1) segTree[r - 1] += val;
    l /= 2, r /= 2;
  }
}

ll check(int pt) {
  pt += shift;
  ll ans = 0;
  while (pt) {
    ans += segTree[pt];
    pt /= 2;
  }
  return ans;
}

void dfs2(int u, int prev) {
  for (auto x : edge[u]) {  // dodaj
    int v = x.st, sz = x.nd;
    add(preo[v], posto[v], sz);
  }

  for (auto x : qry[u]) {
    int v = x.st, ind = x.nd;
    outpt[ind] = check(preo[v]);
  }

  for (auto v : T[0][u]) {
    if (v != prev) dfs2(v, u);
  }

  for (auto x : edge[u]) {  // dodaj
    int v = x.st, sz = x.nd;
    add(preo[v], posto[v], -sz);
  }
  // usun z drzewa
}

int32_t main() {
  fast;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u;
    cin >> u;
    T[0][i + 1].pb(u);
    T[0][u].pb(i + 1);
  }
  cin >> m;
  for (int i = 1; i < m; i++) {
    int u;
    cin >> u;
    T[1][i + 1].pb(u);
    T[1][u].pb(i + 1);
  }

  int e;
  cin >> e;
  for (int i = 0; i < e; i++) {
    int u, v, ss;
    cin >> u >> v >> ss;
    edge[u].pb({v, ss});
  }

  dfs1(1, 1);

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    qry[a].pb({b, i});
  }

  dfs2(1, 1);
  for (int i = 0; i < q; i++) cout << outpt[i] << '\n';
}
