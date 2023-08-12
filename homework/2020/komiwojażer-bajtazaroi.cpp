#include <iostream>
#include <queue>
#include <vector>

const int maxN = 3e4 + 10;
const int _log = 16;
typedef long long ll;

std::vector<int> g[maxN];
int dsum, ord[2][maxN], anc[_log][maxN], lvl[maxN];  //[0]-pre, [1]-post

void dfs(int v, int u) {
  anc[0][v] = u;
  ord[0][v] = dsum;
  for (auto p : g[v]) {
    if (p != u) {
      dsum++;
      dfs(p, v);
    }
  }
  ord[1][v] = dsum;
}

void bfs() {
  std::queue<std::pair<int, int> > q;
  for (auto u : g[1]) q.push({u, 1});
  while (!q.empty()) {
    int cur = q.front().first, prev = q.front().second;
    q.pop();
    lvl[cur] = lvl[prev] + 1;
    for (auto n : g[cur])
      if (n != prev) q.push({n, cur});
  }
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

int main() {
  std::cin.tie(0);
  std::cout.tie(0);

  int n;
  std::cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    std::cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 1);
  bfs();
  for (int i = 1; i < _log; i++) {
    for (int j = 1; j <= n; j++) anc[i][j] = anc[i - 1][anc[i - 1][j]];
  }
  int m;
  std::cin >> m;
  int prev = 1;
  ll ov = 0;
  for (int i = 0; i < m; i++) {
    int u;
    std::cin >> u;
    int lcav = lca(u, prev);
    ov += ll(lvl[prev]) + lvl[u] - 2 * lvl[lcav];
    prev = u;
  }
  std::cout << ov << '\n';
  return 0;
}
