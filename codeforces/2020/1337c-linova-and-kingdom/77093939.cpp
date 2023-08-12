#include <bits/stdc++.h>
using namespace std;
int const maxN = 2e5 + 10;
vector<int> edge[maxN];
int n, k, dis[maxN], sts[maxN], delta[maxN];

bool comp(int a, int b) { return a > b; }

int dfs(int u, int v) {
  dis[u] = dis[v] + 1;
  sts[u] = 1;
  for (int i = 0; i < edge[u].size(); i++) {
    int nxt = edge[u][i];
    if (nxt != v) sts[u] += dfs(nxt, u);
  }
  delta[u] = sts[u] - dis[u];
  return sts[u];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  cin >> n >> k;
  for (int i = 0; i < n - 1; i++) {
    int v1, v2;
    cin >> v1 >> v2;
    edge[v1].push_back(v2);
    edge[v2].push_back(v1);
  }
  dfs(1, 1);
  sort(delta + 1, delta + n + 1, comp);
  long long sum = 0;
  for (int i = 1; i <= n - k; i++) {
    sum += delta[i];
  }
  cout << sum << '\n';
  return 0;
}
