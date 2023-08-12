#include <bits/stdc++.h>
using namespace std;
#define fast                    \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
#define int long long
#define pb push_back

int const maxN = 3e5 + 10;
int n, a[maxN], pv[maxN];
vector<int> f[maxN], sing[maxN], pth;
bool used[maxN], vis[maxN];

void fact() {
  for (int i = 1; i <= n; i++) {
    int cur = a[i];
    for (int j = 2; j * j <= cur; j++) {
      if (cur % j == 0) f[i].pb(j), sing[j].pb(i);
      while (cur % j == 0) cur /= j;
    }
    if (cur != 1) f[i].pb(cur), sing[cur].pb(i);
  }
}

void bfs(int st) {
  queue<int> q;
  q.push(st);
  vis[st] = true;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    // cout<<cur<<'\n';
    for (auto val : f[cur]) {
      if (used[val]) continue;
      for (auto ver : sing[val])
        if (!vis[ver]) {
          q.push(ver);
          vis[ver] = true;
          pv[ver] = cur;
        }
      used[val] = true;
    }
  }
}

void bct(int v) {
  pth.pb(v);
  if (pv[v] != 0) bct(pv[v]);
}

int32_t main() {
  fast;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int s, t;
  cin >> s >> t;
  fact();
  bfs(s);
  bct(t);

  reverse(pth.begin(), pth.end());

  if (pth[0] != s) {
    cout << "-1";
    return 0;
  }

  cout << pth.size() << '\n';
  for (auto x : pth) cout << x << " ";
}
