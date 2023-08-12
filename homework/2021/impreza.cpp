#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second
#define ll long long
int const maxN = 3e3 + 10;
bool g[maxN][maxN], ans[maxN];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u][v] = true;
    g[v][u] = true;
  }
  for (int i = 1; i <= n; i++) ans[i] = true;

  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (!g[i][j] && ans[i] && ans[j]) {
        ans[i] = false;
        ans[j] = false;
      }
    }
  }
  int cnt = n / 3;
  for (int i = 1; i <= n; i++) {
    if (ans[i] && cnt > 0) cout << i << " ", cnt--;
  }
  return 0;
}
