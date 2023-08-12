#include <bits/stdc++.h>
using namespace std;
int const maxN = 2e5 + 10, inf = 1e9;
int dp[maxN][4];
typedef long long ll;
void clean() {
  for (int i = 0; i < maxN; i++) {
    for (int j = 0; j < 4; j++) dp[i][j] = 0;
  }
}
void solution() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  dp[0][0] = a[0], dp[0][1] = inf, dp[0][2] = inf, dp[0][3] = inf;
  for (int i = 1; i < n; i++) {
    dp[i][0] = min({dp[i - 1][2] + a[i], dp[i - 1][3] + a[i], inf});
    dp[i][1] = min(dp[i - 1][0] + a[i], inf);
    dp[i][2] = min({dp[i - 1][0], dp[i - 1][1], inf});
    dp[i][3] = dp[i - 1][2];
  }
  cout << min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2], dp[n - 1][3]}) << '\n';
}

int main() {
  int t = 1;
  cin >> t;
  while (t--) solution();
}
