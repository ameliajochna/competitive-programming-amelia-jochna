#include <bits/stdc++.h>
using namespace std;
int const maxN = 2e5 + 5;
int a[maxN], dp[maxN];
map<int, int> ind;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    int v = a[i];
    dp[i] = max(dp[ind[v - 1]] + 1, dp[ind[v]]);
    ind[v] = i;
  }
  int ans = -INT_MAX, j;
  for (int i = 1; i <= n; i++)
    if (dp[i] > ans) ans = dp[i], j = i;

  int tf = a[j] - ans + 1;
  cout << ans << '\n';
  for (int i = 1; i <= n; i++)
    if (a[i] == tf) cout << i << " ", tf++;
}
