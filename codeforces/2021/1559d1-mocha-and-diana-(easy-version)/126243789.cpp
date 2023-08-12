#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
using namespace std;
typedef long long ll;
int const maxN = 1e3 + 10;
int rep[2][maxN], sz[2][maxN];

int Find(int v, int const i) {
  if (v == rep[i][v]) return v;
  return rep[i][v] = Find(rep[i][v], i);
}

void Union(int u, int v, int const i) {
  u = Find(u, i);
  v = Find(v, i);
  if (sz[u] < sz[v])
    rep[i][u] = rep[i][v];
  else if (sz[u] > sz[v])
    rep[i][v] = rep[i][u];
  else {
    rep[i][v] = rep[i][u];
    sz[i][u]++;
  }
}

void solution() {
  int n, m[2];
  cin >> n >> m[0] >> m[1];

  for (int i = 1; i <= n; i++) rep[0][i] = i, rep[1][i] = i;

  for (int k = 0; k <= 1; k++)
    for (int i = 0; i < m[k]; i++) {
      int u, v;
      cin >> u >> v;
      Union(u, v, k);
    }

  vector<pii> ans;
  for (int u = 1; u <= n; u++)
    for (int v = 1; v <= n; v++) {
      int fu0 = Find(u, 0), fu1 = Find(u, 1), fv0 = Find(v, 0),
          fv1 = Find(v, 1);
      if (fu0 != fv0 && fu1 != fv1) {
        Union(u, v, 0);
        Union(u, v, 1);
        ans.push_back({u, v});
      }
    }

  cout << ans.size() << '\n';
  for (auto k : ans) {
    cout << k.st << " " << k.nd << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  // cin>>t;
  while (t--) solution();
}
