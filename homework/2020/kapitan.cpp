#include <bits/stdc++.h>
#define st first
#define nd second
using namespace std;
int const maxN = 2e5 + 10;
int n;
vector<pair<int, int> > G[maxN];  // sasiad, waga

long long dijkstra(int s) {
  vector<bool> vis(n + 1);
  vector<long long> dis(n + 1);
  for (int i = 0; i <= n; i++) dis[i] = INT_MAX;
  priority_queue<pair<int, int> > pq;  //-waga krawedzi, nr wierzcholka
  pq.push({0, s});
  dis[s] = 0;
  while (!pq.empty()) {
    int u = pq.top().nd;
    pq.pop();
    if (!vis[u]) {
      vis[u] = true;
      for (auto v : G[u]) {
        if (!vis[v.st] && dis[v.st] > dis[u] + v.nd) {
          dis[v.st] = dis[u] + v.nd;
          pq.push({-dis[v.st], v.st});
        }
      }
    }
  }
  return dis[n];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();

  cin >> n;
  vector<pair<int, int> > dx(n + 1);  // wartosc x, indeks
  vector<pair<int, int> > dy(n + 1);  // wartosc y, indeks
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    dx[i] = {x, i};
    dy[i] = {y, i};
  }
  sort(dx.begin(), dx.end());
  sort(dy.begin(), dy.end());
  G[dx[1].nd].push_back({dx[2].second, dx[2].first - dx[1].first});
  G[dy[1].nd].push_back({dy[2].second, dy[2].first - dy[1].first});
  for (int i = 2; i < n; i++) {
    G[dx[i].nd].push_back({dx[i - 1].second, dx[i].first - dx[i - 1].first});
    G[dy[i].nd].push_back({dy[i - 1].second, dy[i].first - dy[i - 1].first});
    G[dx[i].nd].push_back({dx[i + 1].nd, dx[i + 1].first - dx[i].first});
    G[dy[i].nd].push_back({dy[i + 1].nd, dy[i + 1].st - dy[i].st});
  }
  G[dx[n].nd].push_back({dx[n - 1].second, dx[n].first - dx[n - 1].first});
  G[dy[n].nd].push_back({dy[n - 1].second, dy[n].first - dy[n - 1].first});
  cout << dijkstra(1);
  return 0;
}
