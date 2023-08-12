#include <iostream>
#include <utility>
#include <vector>

const int maxN = 650;
std::vector<int> G[maxN];
int mat[maxN], vis[maxN], incnt[maxN];
std::pair<int, int> coord[maxN], sched[maxN];
int n;

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

int matching() {
  int out = 0;
  for (int i = 1; i <= n; i++) {
    if (dfs(i, i) == true) {
      out++;
    }
  }
  return n - out;
}

void print(int u) {
  std::cout << u << " ";
  for (auto v : G[u]) {
    print(v);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    int s, e, x, y;
    std::cin >> s >> e >> x >> y;
    sched[i] = {s, e};
    coord[i] = {x, y};
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      std::pair<int, int> c1 = coord[i], c2 = coord[j];
      int dx = c1.first - c2.first, dy = c1.second - c2.second;
      int dist = dx * dx + dy * dy;
      if (sched[i].second + dist <= sched[j].first) {
        G[i].push_back(j + n);
      }
    }
  }

  std::cout << matching() << '\n';

  for (int i = 1; i <= 2 * n; i++) {
    G[i].clear();
  }

  for (int i = n + 1; i <= 2 * n; i++) {
    if (mat[i] != 0) {
      G[mat[i]].push_back(i - n);
      incnt[i - n]++;
    }
  }

  for (int i = 1; i <= n; i++) {
    if (incnt[i] == 0) {
      print(i);
      std::cout << '\n';
    }
  }

  return 0;
}
