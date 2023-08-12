#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second
typedef long long ll;
int const maxN = 15e3 + 10;
int dp[2][maxN], n, m, rem[maxN], a[maxN], b[maxN], preva[2 * maxN],
    prevb[2 * maxN];
map<int, int> mp;

int lcs() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i - 1] == b[j - 1] && preva[a[i - 1]] > 0 && prevb[b[j - 1]] > 0)
        dp[i % 2][j] = rem[prevb[b[j - 1]]] + 2;
      dp[i % 2][j] = max({dp[i % 2][j], dp[(i - 1) % 2][j], dp[i % 2][j - 1]});
      prevb[b[j - 1]] = j;
    }

    for (int j = 1; j <= m; j++)
      if (a[i - 1] == b[j - 1]) rem[j] = dp[(i - 1) % 2][j - 1];

    for (int j = 1; j <= m; j++) prevb[b[j - 1]] = 0;

    preva[a[i - 1]] = i;
  }
  return dp[n % 2][m];
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]), mp[a[i]] = 0;
  for (int i = 0; i < m; i++) scanf("%d", &b[i]), mp[b[i]] = 0;

  int cnt = 0;
  for (auto &x : mp) x.second = cnt++;

  for (int i = 0; i < n; i++) a[i] = mp[a[i]];
  for (int i = 0; i < m; i++) b[i] = mp[b[i]];

  cout << lcs();
  return 0;
}
