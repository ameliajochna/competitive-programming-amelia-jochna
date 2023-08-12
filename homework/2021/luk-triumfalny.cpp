#include <bits/stdc++.h>
using namespace std;
#define st first
#define nd second
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;

int const maxN = 3e5 + 10;
int n, lft;
vector<int> g[maxN];

int dfs(int cnt, int u = 1, int prev = 1) {
  int sons = g[u].size() - 1, sum = 0;
  for (auto v : g[u])
    if (v != prev) sum += dfs(cnt, v, u);
  return max(0, sum + sons - cnt);
}

bool check(int cnt) {
  if (dfs(cnt) == 0) return true;
  return false;
}

int binsearch() {
  int l = 0, r = n;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    (check(mid) ? r : l) = mid;
  }
  if (check(l)) return l;
  return r;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  cin >> n;
  g[1].pb(1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v), g[v].pb(u);
  }

  cout << binsearch();
  return 0;
}
