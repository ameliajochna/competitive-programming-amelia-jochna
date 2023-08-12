#include <bits/stdc++.h>
#define nd second
#define st first
#define pll pair<ll, ll>
using namespace std;
typedef long long ll;
int const maxN = 5e5 + 10;
int n, l, lpath;
vector<int> G[maxN];

int dfs(int u, int prev) {
  vector<int> val;
  val.push_back(0);
  for (auto v : G[u])
    if (v != prev) val.push_back(dfs(v, u));
  int ind0 = 0, ind1 = 0, ans = 0;
  if (val.size() > 1) {
    for (int i = 0; i < val.size(); i++)
      if (val[i] > val[ind0]) ind0 = i;
    for (int i = 0; i < val.size(); i++)
      if (val[i] > val[ind1] && i != ind0) ind1 = i;
  }
  ans = val[ind0] + val[ind1];
  lpath = max(lpath, ans);
  return max(val[ind0], val[ind1]) + 1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  cin >> n >> l;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(1, 1);
  if (l >= lpath) {
    int cnt = lpath + 1;
    l -= lpath;
    cnt += (l / 2);
    cout << min(cnt, n) << '\n';
  } else
    cout << l + 1 << '\n';
}
