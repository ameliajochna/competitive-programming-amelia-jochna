#include <bits/stdc++.h>
#define nd second
#define st first
#define pll pair<ll, ll>
using namespace std;
typedef long long ll;
typedef long double ld;
int const maxN = 4e5 + 10;
bool vis[maxN], imp[maxN], pos[maxN];
int n, m, cnt, ans[maxN], root[maxN];
vector<int> G[maxN], revG[maxN], sccG[maxN];
stack<int> s;

void dfs1(int u) {
  vis[u] = true;
  for (auto v : G[u])
    if (!vis[v]) dfs1(v);
  s.push(u);
}

void dfs2(int u, bool spec) {
  vis[u] = true;
  for (auto v : revG[u]) {
    if (v == u) imp[cnt] = 1;
    if (!vis[v]) {
      dfs2(v, 1);
      imp[cnt] = 1;
    }
  }
  root[u] = cnt;
}

void scc_graph() {
  for (int i = 1; i <= n; i++)
    for (auto v : G[i]) {
      int ri = root[i], rv = root[v];
      if (ri != rv) sccG[ri].push_back(rv);
    }
}

void scc_divide() {
  for (int i = 1; i <= n; i++)
    if (!vis[i]) dfs1(i);

  for (int i = 1; i <= n; i++) vis[i] = false;

  while (!s.empty()) {
    int u = s.top();
    s.pop();
    if (!vis[u]) cnt++, dfs2(u, 0);
  }
}

void dfs0(int u) {
  vis[u] = true;
  imp[u] = true;
  for (auto v : sccG[u]) {
    if (pos[v] && v != root[1] && !vis[v]) dfs0(v);
  }
}

void dfs4(int u) {
  pos[u] = true;
  for (auto v : sccG[u]) {
    if (!pos[v]) dfs4(v);
  }
}

void prep() {
  dfs4(root[1]);

  for (int i = 1; i <= cnt; i++) vis[i] = false;
  for (int i = 1; i <= cnt; i++)
    if (pos[i] && imp[i] && !vis[i]) dfs0(i);

  vector<int> incnt(cnt + 1);
  queue<int> q;
  for (int i = 1; i <= cnt; i++)
    for (auto u : sccG[i]) incnt[u]++;

  for (int i = 1; i <= cnt; i++)
    if (incnt[i] == 0) q.push(i);

  ans[root[1]] = 1;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (auto u : sccG[cur]) {
      ans[u] += ans[cur];
      if (ans[u] > 2) ans[u] = 2;
      incnt[u]--;
      if (incnt[u] == 0) q.push(u);
    }
  }

  for (int i = 1; i <= cnt; i++) {
    if (!pos[i])
      ans[i] = 0;
    else if (imp[i])
      ans[i] = -1;
    else if (ans[i] > 1)
      ans[i] = 2;
    else if (pos[i])
      ans[i] = 1;
  }
}

void clear() {
  for (int i = 1; i <= n; i++) {
    vis[i] = false;
    imp[i] = false;
    pos[i] = false;
    ans[i] = 0;
    G[i].clear();
    revG[i].clear();
    sccG[i].clear();
  }
  cnt = 0;
}

void solve() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    revG[v].push_back(u);
  }
  scc_divide();
  scc_graph();
  prep();
  for (int i = 1; i <= n; i++) cout << ans[root[i]] << " ";
  cout << '\n';
  clear();
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solve();
}
