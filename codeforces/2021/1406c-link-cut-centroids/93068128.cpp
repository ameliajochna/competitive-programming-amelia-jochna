#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int const maxN = 1e5 + 10;
vector<int> g[maxN];
int subtree[maxN], n, minall, c1, c2;

void clear() {
  for (int i = 0; i < maxN; i++) {
    subtree[i] = maxN;
    g[i].clear();
  }
  minall = 1e9;
  c1 = -1;
  c2 = -1;
}

void dfs(int u, int p) {
  int maxstree = -1;
  subtree[u] = 1;
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
      subtree[u] += subtree[v];
      maxstree = max(maxstree, subtree[v]);
    }
  }
  maxstree = max(maxstree, n - subtree[u]);
  if (maxstree < minall)
    c1 = u, minall = maxstree, c2 = -1;
  else if (maxstree == minall)
    c2 = u;
}

void leaf(int u, int p, vector<bool>& c1stree) {
  c1stree[u] = true;
  for (auto v : g[u]) {
    if (v != p && v != c2) leaf(v, u, c1stree);
  }
}

void solution() {
  clear();
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 1);
  if (c2 == -1) {
    cout << c1 << " " << g[c1][0] << '\n';
    cout << c1 << " " << g[c1][0] << '\n';
    return;
  }
  vector<bool> c1stree(n + 1);
  leaf(c1, c1, c1stree);
  int toremove = 0;
  for (int i = 1; i <= n; i++) {
    if (g[i].size() == 1 && c1stree[i]) toremove = i;
  }
  cout << toremove << " " << g[toremove][0] << '\n';
  cout << toremove << " " << c2 << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();
  exit(0);
}
