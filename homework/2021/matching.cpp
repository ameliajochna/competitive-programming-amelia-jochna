#include <iostream>
#include <vector>

int const maxN = 6e4 + 10;
std::vector<int> G[2 * maxN];
int mat[maxN];
int vis[maxN];

bool dfs(int u, int col) {
  vis[u] = col;
  for (int v : G[u]) {
    if (mat[v] == 0) {
      mat[v] = u;
      return true;
    }
  }

  for (int v : G[u]) {
    if (vis[mat[v]] != col && dfs(mat[v], col) == true) {
      mat[v] = u;
      return true;
    }
  }

  return false;
}

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int q;
  std::cin >> q;
  while (q--) {
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < m; i++) {
      int u, v;
      std::cin >> u >> v;
      G[u].push_back(v + n);
    }
    // szukanie matchingu
    int out = 0;
    for (int i = 1; i <= 2 * n + 1; i++) {
      if (dfs(i, i) == true) {
        out++;
      }
    }
    // cout<<out<<'\n';
    if (n == out) {
      std::cout << "TAK\n";
    } else {
      std::cout << "NIE\n";
    }
    // Clearing arrays for the next test case
    for (int i = 1; i <= 2 * n + 1; i++) {
      G[i].clear();
      vis[i] = 0;
      mat[i] = 0;
    }
  }
}
