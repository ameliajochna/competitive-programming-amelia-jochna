#include <climits>
#include <iostream>
#include <queue>
#include <vector>

int const maxN = 1e6 + 10, shift = (1 << 21);
std::vector<int> g[maxN];
int ap[maxN], tmp = 0, segtree[2 * shift], depth[maxN];

void dfs(int u = 1, int p = 1) {
  if (ap[u] == 0) ap[u] = tmp;
  segtree[tmp + shift] = u;
  tmp++;
  for (auto n : g[u])
    if (n != p) {
      dfs(n, u);
      segtree[tmp + shift] = u;
      tmp++;
    }
}

void bfs() {
  depth[0] = INT_MAX;
  std::queue<std::pair<int, int> > q;
  q.push({1, 1});
  while (!q.empty()) {
    int u = q.front().first, p = q.front().second;
    depth[u] = depth[p] + 1;
    q.pop();
    for (auto v : g[u]) {
      if (v != p) q.push({v, u});
    }
  }
}

void build() {
  for (int i = shift - 1; i > 0; i--) {
    int left = segtree[2 * i], right = segtree[2 * i + 1];
    if (depth[left] < depth[right])
      segtree[i] = left;
    else
      segtree[i] = right;
  }
}

int anscalc(int l, int r) {
  l += shift, r += shift;
  int ans = segtree[l];
  if (l != r) {
    if (depth[segtree[r]] < depth[ans]) ans = segtree[r];
  }
  while (l / 2 != r / 2) {
    if (l % 2 == 0) {
      if (depth[segtree[l + 1]] < depth[ans]) ans = segtree[l + 1];
    }
    if (r % 2 == 1) {
      if (depth[segtree[r - 1]] < depth[ans]) ans = segtree[r - 1];
    }
    l /= 2, r /= 2;
  }
  return ans;
}

int main() {
  int n;
  std::cin >> n;
  for (int i = 2; i <= n; i++) {
    int u;
    std::cin >> u;
    g[u].push_back(i);
    g[i].push_back(u);
  }
  dfs();
  bfs();
  build();
  int q;
  std::cin >> q;
  for (int i = 0; i < q; i++) {
    int u, v;
    std::cin >> u >> v;
    std::cout << anscalc(std::min(ap[u], ap[v]), std::max(ap[u], ap[v]))
              << '\n';
  }
  return 0;
}
