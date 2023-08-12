#include <bits/stdc++.h>

using namespace std;

int n, m, a, b, w, pocz, kon, dist[2][200001];  // 0 parzyste 1 nieparzyste
vector<pair<int, int> > graph[200001];
priority_queue<pair<int, int> > Q;
bool vis[2][200001];

void dijkstra(int s) {
  dist[0][s] = 0;
  dist[1][s] = 0;
  Q.push({-dist[1][s], s});
  while (!Q.empty()) {
    int l = -Q.top().first;
    int u = Q.top().second;
    vis[l % 2][u] = true;
    Q.pop();
    for (auto v : graph[u]) {
      int wg = v.second;
      int x = v.first;
      int mod = (l + wg) % 2;
      if (!vis[mod][x] && dist[mod][x] > l + wg) {
        dist[mod][x] = l + wg;
        Q.push({-dist[mod][x], x});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b >> w;
    graph[a].push_back({b, w});
    graph[b].push_back({a, w});
  }

  for (int i = 1; i <= n; ++i) {
    dist[0][i] = INT_MAX;
    dist[1][i] = INT_MAX;
  }

  dijkstra(1);
  if (dist[1][n] == INT_MAX)
    cout << 0;
  else
    cout << dist[1][n];
  return 0;
}
