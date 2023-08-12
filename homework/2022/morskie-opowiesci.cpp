#include <bits/stdc++.h>
using namespace std;
#define nd second
#define st first
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
typedef long long ll;

int const maxN = (int)5010, maxQ = (int)1e6 + 10;

int dis[maxN][2], n, m, d;
bool ans[maxQ];
pair<pii, int> query[maxQ];
vector<int> G[maxN], outque[maxN];

void preprocess() {
  for (int i = 1; i <= n; i++) {
    if (!G[i].size()) continue;

    for (int j = 1; j <= n; j++) dis[j][0] = -1, dis[j][1] = -1;

    queue<pii> q;
    q.push({0, i});
    dis[i][0] = 0;
    while (!q.empty()) {
      pii cur = q.front();
      q.pop();
      int cost = cur.st + 1, v = cur.nd;
      for (auto x : G[v]) {
        int &disval = dis[x][cost % 2];
        if (disval == -1 || disval > cost) {
          disval = cost;
          q.push({cost, x});
        }
      }
    }

    for (auto x : outque[i]) {
      pair<pii, int> cur = query[x];
      int curdis = dis[cur.st.nd][cur.nd % 2];
      if (curdis != -1 && curdis <= cur.nd) ans[x] = true;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> d;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    G[u].pb(v);
    G[v].pb(u);
  }

  for (int i = 0; i < d; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    query[i] = {{u, v}, c};
    outque[u].pb(i);
  }

  preprocess();
  for (int i = 0; i < d; i++) cout << (ans[i] ? "TAK\n" : "NIE\n");
  return 0;
}
