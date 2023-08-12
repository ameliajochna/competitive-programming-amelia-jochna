#include <bits/stdc++.h>
using namespace std;
#define nd second
#define st first
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
typedef long long ll;

int const maxN = (int)210, maxP = 14;

int ver[maxN], dis[maxN][(1 << maxP)], n, m, p,
    k;  // maska mieczy jakie dostaje w wierzcholku
bool vis[maxN][(1 << maxP)];
vector<pair<int, pii> > G[maxN];  // wierzcholek, {koszt, potrzebne miecze}

void calcdis() {
  priority_queue<pair<int, pii> > pq;
  pq.push({0, {1, 0}});
  while (!pq.empty()) {
    pair<int, pii> top = pq.top();
    pq.pop();
    int cost = -top.st, curver = top.nd.st, kniv = top.nd.nd;
    kniv |= ver[curver];
    for (auto &x : G[curver]) {
      int need = x.nd.nd;
      if ((need & kniv) != need) continue;  // czy mam te co trzbea zeby przejsc
      int newcost = cost + x.nd.st, u = x.st;
      if (!vis[u][kniv] || dis[u][kniv] > newcost) {
        dis[u][kniv] = newcost;
        vis[u][kniv] = true;
        pq.push({-newcost, {u, kniv}});
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> p >> k;
  for (int i = 0; i < k; i++) {
    int w, q, bt = 0;
    cin >> w >> q;
    for (int j = 0; j < q; j++) {
      int r;
      cin >> r;
      bt |= (1 << r);
    }
    ver[w] |= bt;
  }

  for (int i = 0; i < m; i++) {
    int v, w, t, s, bt = 0;
    cin >> v >> w >> t >> s;
    for (int j = 0; j < s; j++) {
      int u;
      cin >> u;
      bt |= (1 << u);
    }
    G[v].pb({w, {t, bt}});
    G[w].pb({v, {t, bt}});
  }

  calcdis();
  int minans = __INT_MAX__;
  for (int i = 0; i < (1 << maxP); i++)
    if (vis[n][i]) minans = min(minans, dis[n][i]);
  if (n == 1)
    cout << "0\n";
  else if (minans == __INT_MAX__)
    cout << "-1\n";
  else
    cout << minans << '\n';

  return 0;
}
