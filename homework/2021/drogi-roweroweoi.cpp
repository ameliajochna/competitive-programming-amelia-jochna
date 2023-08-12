#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

int const maxN = 5e4 + 10;
int n, m, vis[maxN], scc[maxN], incnt[maxN], dp[maxN], cnt, sccsize[maxN];
std::vector<int> G[maxN], revG[maxN], sccG[maxN];
std::stack<int> s;

void dfs1(int u) {
  vis[u] = true;
  for (int i = 0; i < G[u].size(); i++) {
    if (!vis[G[u][i]]) dfs1(G[u][i]);
  }
  s.push(u);
}

void dfs2(int u, int const nr) {
  vis[u] = true;
  scc[u] = nr;
  for (int i = 0; i < revG[u].size(); i++)
    if (!vis[revG[u][i]]) dfs2(revG[u][i], nr);
}

void sccgraph() {
  for (int i = 1; i <= n; i++)
    if (!vis[i]) dfs1(i);
  for (int i = 1; i <= n; i++) vis[i] = false;
  while (!s.empty()) {
    int u = s.top();
    s.pop();
    if (!vis[u]) cnt++, dfs2(u, cnt);
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < revG[i].size(); j++) {
      int ind1 = scc[i], ind2 = scc[revG[i][j]];
      if (ind1 != ind2) sccG[ind1].push_back(ind2);
    }
  }

  for (int i = 1; i <= cnt; i++) {
    if (!sccG[i].empty()) {
      std::sort(sccG[i].begin(), sccG[i].end());
      sccG[i].erase(std::unique(sccG[i].begin(), sccG[i].end()), sccG[i].end());
      for (auto u : sccG[i]) incnt[u]++;
    }
  }

  for (int i = 1; i <= n; i++) sccsize[scc[i]]++;
}

void topsort() {
  std::stack<int> q;
  for (int i = 1; i <= cnt; i++)
    if (incnt[i] == 0) q.push(i);
  while (!q.empty()) {
    int v = q.top();
    q.pop();
    dp[v] += sccsize[v];
    for (int i = 0; i < sccG[v].size(); i++) {
      incnt[sccG[v][i]]--;
      dp[sccG[v][i]] += dp[v];
      if (incnt[sccG[v][i]] == 0) q.push(sccG[v][i]);
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    std::cin >> u >> v;
    G[u].push_back(v);
    revG[v].push_back(u);
  }
  sccgraph();
  for (int i = 1; i <= cnt; i++) vis[i] = false;
  topsort();
  for (int i = 1; i <= n; i++) std::cout << dp[scc[i]] - 1 << "\n";
  return 0;
}
