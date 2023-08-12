#include <bits/stdc++.h>
using namespace std;
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define cst const
int const maxN = 1e5 + 10;
int n, x, z, newnum = 1, last;
vector<pii> seg[maxN];  //{{poczatek, koniec}, nr wierz}
vector<vector<pii> > g;
vector<bool> vis;
vector<int> dis;

void input() {  // dziala
  cin >> n >> x >> z;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int h;
      cin >> h;
      seg[i].pb({h - 1, newnum++});
    }
    seg[i].pb({x + 1, newnum++});
  }
}

void addrevpath(int v, int u, int cost) {  // dziala
  g[u].pb({v, cost});
}

void onelvl(int u) {  // dziala jeszcze jak
  for (int i = 0; i < int(seg[u].size()) - 1; i++)
    addrevpath(seg[u][i].nd, seg[u][i + 1].nd, 1);
  if (seg[u].size() > 0) addrevpath(seg[u][seg[u].size() - 1].nd, last, 0);
}

void pthupdw(int u) {  // dziala
  int pt = 0;
  for (int i = 0; i < int(seg[u].size()) - 1; i++) {
    cst pii cur = seg[u][i];
    while (pt < int(seg[u + 1].size()) && seg[u + 1][pt].st < cur.st) pt++;
    if (pt < int(seg[u + 1].size()) && seg[u + 1][pt].st > cur.st) {
      addrevpath(cur.nd, seg[u + 1][pt].nd, 0);
      addrevpath(seg[u + 1][pt].nd, seg[u][i + 1].nd, 1);
    }
  }
}

void build() {  // dziala
  g.resize(newnum + 1);
  last = newnum;
  for (int i = 0; i < n - 1; i++) {
    onelvl(i);
    pthupdw(i);
  }
  onelvl(n - 1);
}

void bfs() {  // dziala
  dis.resize(newnum + 1);
  vis.resize(newnum + 1);
  deque<pair<int, pair<int, int> > > q;  // dokad, skad, za ile
  q.push_back({newnum, {newnum, 0}});
  while (!q.empty()) {
    auto cur = q.front();
    q.pop_front();
    int u = cur.st;
    if (vis[u]) continue;
    vis[u] = true;
    dis[u] = dis[cur.nd.st] + cur.nd.nd;
    for (int i = 0; i < int(g[u].size()); i++) {
      pii tmp = g[u][i];
      if (!vis[tmp.st]) {
        if (tmp.nd == 0)
          q.push_front({tmp.st, {u, tmp.nd}});
        else if (tmp.nd == 1)
          q.push_back({tmp.st, {u, tmp.nd}});
      }
    }
  }
}

void queries() {
  for (int i = 0; i < z; i++) {
    int q;
    cin >> q;
    cout << dis[seg[q - 1][0].nd] << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  input();
  build();
  bfs();
  queries();
}
