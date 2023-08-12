#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define nd second
#define st first
int const maxN = 1e5 + 10, maxM = 15e4 + 10;
int n, m, z;
vector<pair<int, int> > g[maxN];
pair<int, int> coord[2 * maxN];
int diff[maxN], cnt[maxM], cntsize;

void dfs(int u = 1, int prev = 1) {
  diff[u] = cntsize;
  for (auto v : g[u]) {
    if (v.st == prev) continue;
    if (cnt[v.nd] == 0) cntsize++;
    cnt[v.nd]++;
    dfs(v.st, u);
    cnt[v.nd]--;
    if (cnt[v.nd] == 0) cntsize--;
  }
}

int main() {
  cin >> n >> m >> z;
  int crd = 1;
  for (int i = 1; i <= n - 1; i++) {
    int u, v, tp;
    cin >> u >> v >> tp;
    g[u].pb({v, tp});
    g[v].pb({u, tp});
    coord[crd] = {u, g[u].size() - 1};
    crd++;
    coord[crd] = {v, g[v].size() - 1};
    crd++;
  }
  dfs();
  for (int i = 0; i < z; i++) {
    char tp;
    cin >> tp;
    if (tp == 'Z') {
      int u;
      cin >> u;
      cout << diff[u] << '\n';
    } else if (tp == 'B') {
      int j, c;
      cin >> j >> c;
      pair<int, int> tmp;
      tmp = coord[2 * j - 1];
      g[tmp.st][tmp.nd] = {g[tmp.st][tmp.nd].st, c};
      tmp = coord[2 * j];
      g[tmp.st][tmp.nd] = {g[tmp.st][tmp.nd].st, c};
      dfs();
    }
  }
}
