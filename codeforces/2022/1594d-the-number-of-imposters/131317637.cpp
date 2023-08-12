#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
#define sz(a) a.size()
#define pb push_back
using namespace std;
typedef long long ll;
int const maxN = 2e5 + 10;
vector<pii> G[maxN];  //{vertex, weight}
bool vis[maxN], ok;
int setval[maxN], n, m, cursz, cnt;

void clear() {
  for (int i = 0; i <= n; i++) {
    vis[i] = 0;
    setval[i] = 0;
    G[i].clear();
  }
}

void dfs(int u) {
  vis[u] = true;
  cursz++;
  if (setval[u] == 1) cnt++;
  for (auto p : G[u]) {
    int v = p.st, edge = p.nd;
    int exval = setval[u] * edge;
    if (vis[v]) {
      if (exval != setval[v]) ok = false;
    } else {
      setval[v] = exval;
      dfs(v);
    }
  }
}

void solve() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int v, u, cost;
    string type;
    cin >> v >> u >> type;
    if (type[0] == 'i')
      cost = -1;
    else
      cost = 1;
    G[u].pb({v, cost});
    G[v].pb({u, cost});
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      cnt = 0, cursz = 0, ok = true;
      setval[i] = 1;
      dfs(i);
      if (!ok) {
        cout << "-1\n";
        clear();
        return;
      }
      ans += max(cnt, cursz - cnt);
    }
  }
  cout << ans << '\n';
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
