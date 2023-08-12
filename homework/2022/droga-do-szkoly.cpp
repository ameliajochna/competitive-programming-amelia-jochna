#include <bits/stdc++.h>
using namespace std;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
#define int long long

int const maxN = (int)4e4 + 10;
int n, m, dist[2][maxN];
vector<int> G[maxN];

void bfs(int start) {
  queue<int> q;
  vector<bool> vis(n + 1);
  q.push(start);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    vis[cur] = true;
    for (auto u : G[cur])
      if (!vis[u]) {
        vis[u] = true;
        q.push(u);
        dist[start - 1][u] = dist[start - 1][cur] + 1;
      }
  }
}

int32_t main() {
  fast;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    G[u].pb(v);
    G[v].pb(u);
  }
  bfs(1);
  bfs(2);

  vector<int> w(6);

  int cnt = 0;
  for (int i = 3; i <= n; i++) {
    if (dist[0][i] == 1)
      w[1]++;
    else if (dist[0][i] == 2)
      w[2]++;
    else if (dist[1][i] == 1)
      w[4]++;
    else if (dist[1][i] == 2)
      w[3]++;
    else
      cnt++;
  }

  w[0] = 1, w[5] = 1;

  if (w[1] > w[4])
    w[2] += cnt;
  else
    w[3] += cnt;

  ll ans = 0;
  for (int i = 0; i < 5; i++) {
    ans += (w[i] * w[i + 1]);
    ans += ((w[i] * (w[i] - 1)) / 2);
  }
  ans -= m;
  cout << ans << '\n';
}
