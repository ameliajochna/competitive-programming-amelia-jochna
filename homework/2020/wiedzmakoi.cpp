#include <iostream>
#include <queue>
#include <vector>

const int inf = 1e9;
int n, m, p, k, extra[210];
int dis[(1 << 13) + 10][210];
bool vis[(1 << 13) + 10][210];

struct triplet {
  int monsters, weight, neighbor;
};

std::vector<triplet> edge[210];

void dijkstra(int s) {
  std::priority_queue<std::pair<int, std::pair<int, int> > > pq;
  int eq = extra[s];
  dis[eq][s] = 0;
  pq.push({0, {s, eq}});
  while (!pq.empty()) {
    eq = pq.top().second.second;
    int v = pq.top().second.first;
    int curdis = -pq.top().first;
    pq.pop();
    vis[eq][v] = true;
    for (int i = 0; i < edge[v].size(); i++) {
      int nextver = edge[v][i].neighbor;
      if (!vis[eq | extra[nextver]][nextver] &&
          (eq & edge[v][i].monsters) == edge[v][i].monsters &&
          curdis + edge[v][i].weight < dis[eq | extra[nextver]][nextver]) {
        dis[eq | extra[nextver]][nextver] = curdis + edge[v][i].weight;
        pq.push({-dis[eq | extra[nextver]][nextver],
                 {nextver, eq | extra[nextver]}});
      }
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n >> m >> p >> k;
  for (int i = 0; i < k; i++) {
    int city, q, cur = 0;
    std::cin >> city >> q;
    for (int j = 0; j < q; j++) {
      int tmp;
      std::cin >> tmp;
      cur |= (1 << (tmp - 1));
    }
    extra[city] = cur;
  }
  for (int i = 0; i < m; i++) {
    int v, w, t, s;
    std::cin >> v >> w >> t >> s;
    int mnstr = 0;
    for (int j = 0; j < s; j++) {
      int tmp;
      std::cin >> tmp;
      mnstr |= (1 << (tmp - 1));
    }
    edge[v].push_back({mnstr, t, w});
    edge[w].push_back({mnstr, t, v});
  }
  for (int i = 0; i <= (1 << 13); i++) {
    for (int j = 0; j <= 200; j++) dis[i][j] = inf;
  }
  dijkstra(1);
  int ans = inf;
  for (int i = 0; i <= (1 << 13); i++) ans = std::min(ans, dis[i][n]);
  std::cout << (ans != inf ? ans : -1) << '\n';
  return 0;
}
