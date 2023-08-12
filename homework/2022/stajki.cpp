#include <iostream>
#include <vector>
using namespace std;
#define nd second
#define st first
#define pii pair<int, int>
#define pb push_back
typedef long long ll;
int const maxN = (int)5e5 + 10;  // 5e5

vector<int> G[maxN];
int cntactive[maxN], parent[maxN], n, q;
bool active[maxN];

void dfs(int u = 1, int prev = 1) {
  parent[u] = prev;
  for (auto v : G[u])
    if (v != prev) dfs(v, u);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();

  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    G[u].pb(v);
    G[v].pb(u);
  }

  dfs();
  for (int i = 1; i <= n; i++)
    active[i] = true, cntactive[i] = (int)G[i].size() - 1;

  cin >> q;
  int ans = 1;
  for (int i = 0; i < q; i++) {
    int u;
    cin >> u;
    if (u > 0) {
      if (u == 1) {
        ans += cntactive[u];
        active[u] = false;
      } else {
        ans += (cntactive[u] + active[parent[u]] - 1);
        active[u] = false;
        cntactive[parent[u]]--;
      }
    } else {
      u = -u;
      if (u == 1) {
        ans -= cntactive[u];
        active[u] = true;
      } else {
        ans -= (cntactive[u] + active[parent[u]] - 1);
        active[u] = true;
        cntactive[parent[u]]++;
      }
    }
    cout << ans << '\n';
  }
}
