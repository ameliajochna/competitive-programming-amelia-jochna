#include <bits/stdc++.h>
#define nd second
#define st first
using namespace std;
typedef long long ll;
int const maxN = 4e5 + 10, MOD = 1e9 + 7;
vector<int> G[maxN];
bool vis[maxN];

void dfs(int u, int prev) {
  vis[u] = true;
  for (auto x : G[u]) {
    if (x != prev && !vis[x]) dfs(x, u);
  }
}

void solution() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];

  for (int i = 0; i < n; i++) {
    G[a[i]].push_back(b[i]);
    G[b[i]].push_back(a[i]);
  }

  ll cnt = 1;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      cnt *= 2;
      cnt %= MOD;
      dfs(i, i);
    }
  }
  cout << cnt << "\n";

  for (int i = 0; i <= n; i++) {
    G[i].clear();
    vis[i] = false;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solution();
}
