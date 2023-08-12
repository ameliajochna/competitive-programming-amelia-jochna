#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;

int const maxN = (int)1e5 + 10, _log = 17;

set<int> G[maxN];
int sz[maxN], pa[maxN];

int dfs(int u, int p) {
  sz[u] = 1;
  for (auto v : G[u])
    if (v != p) {
      sz[u] += dfs(v, u);
    }
  return sz[u];
}

int centroid(int u, int p, int n) {
  for (auto v : G[u])
    if (v != p) {
      if (sz[v] > n / 2) return centroid(v, u, n);
    }
  return u;
}

void build(int u, int p) {
  int n = dfs(u, p);
  int c = centroid(u, p, n);
  if (p == -1) p = c;
  pa[c] = p;

  vector<int> tmp(G[c].begin(), G[c].end());
  for (auto v : tmp) {
    G[c].erase(v);
    G[v].erase(c);
    build(v, c);
  }
}

ll n, k, ord[2][maxN], anc[_log][maxN], dsum, lvl[maxN], mn, subtree[maxN],
    sum[maxN], valsum[maxN], cntsum[maxN];
vector<pii> T[maxN];
vector<ll> cenT[maxN], val[maxN], cnt[maxN];  //{wierzcholek, odleglosc}

void dfs2(int v, int u, int cost = 0) {
  anc[0][v] = u;
  ord[0][v] = dsum;
  lvl[v] = cost;
  for (auto p : T[v]) {
    if (p.st != u) {
      dsum++;
      dfs2(p.st, v, cost + p.nd);
    }
  }
  ord[1][v] = dsum;
}

bool isanc(int v, int u) {
  if (ord[0][v] <= ord[0][u] && ord[1][v] >= ord[1][u]) return true;
  return false;
}

int lca(int v, int u) {
  int l = _log - 1;
  while (l >= 0) {
    if (!isanc(anc[l][v], u)) v = anc[l][v];
    l--;
  }
  if (isanc(v, u)) return v;
  return anc[0][v];
}

int dist(int u, int v) {
  int lc = lca(u, v);
  return lvl[u] + lvl[v] - 2 * lvl[lc];
}

void dfs3(int u, int p) {
  int cn = 1;
  for (auto v : cenT[u]) {
    if (v != p) {
      subtree[v] = cn++;
      dfs3(v, u);
    }
  }
  val[u].resize(cn);
  cnt[u].resize(cn);
}

void update(int u) {  // postaw zamek
  cntsum[u]++;
  // cout<<u<<": "<<subtree[u]<<" "<<cnt[u].size()<<'\n';
  cnt[u][0]++;

  ll org = u, toadd = valsum[u], p = u;
  sum[u] += toadd;
  u = pa[u];

  while (u > 0) {
    ll d = dist(u, org);

    cntsum[u]++;
    cnt[u][subtree[p]]++;

    valsum[u] += d;
    val[u][subtree[p]] += d;

    ll curcnt = cntsum[u] - cnt[u][subtree[p]];
    ll a = valsum[u] - val[u][subtree[p]];  // niekoniecznie musi przechodzic
    ll cur = d * curcnt + a;

    toadd += cur;
    sum[u] += toadd;

    p = u;
    u = pa[u];
  }
}

void prepare() {
  dfs2(1, 1);
  for (int i = 1; i < _log; i++)
    for (int j = 1; j <= n; j++) anc[i][j] = anc[i - 1][anc[i - 1][j]];

  build(1, 0);

  for (int i = 1; i <= n; i++)
    if (pa[i] == 0) mn = i;

  for (int i = 1; i <= n; i++) {
    if (pa[i] == 0) continue;
    cenT[i].pb(pa[i]);
    cenT[pa[i]].pb(i);
  }
  dfs3(mn, mn);
}

void process() {
  update(1);
  for (int i = 0; i < k; i++) {
    int u;
    cin >> u;
    update(u);
    cout << 2 * sum[mn] << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  cin >> n >> k;
  for (int i = 0; i < n - 1; i++) {
    int u, v, cost;
    cin >> u >> v >> cost;
    G[u].insert(v);
    G[v].insert(u);
    T[u].pb({v, cost});
    T[v].pb({u, cost});
  }

  prepare();

  process();

  return 0;
}
