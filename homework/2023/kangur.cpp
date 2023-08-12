#include <bits/stdc++.h>
using namespace std;
using lf = long double;
using ll = long long;
using cll = const ll;
using cint = const int;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

int const maxN = 2e3 + 10, MOD = 1e9 + 7;
ll dp[maxN][maxN];

int main() {
  fast int n, a, b;
  cin >> n >> a >> b;
  dp[1][1] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == a || i == b)
        dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % MOD;
      else
        dp[i][j] = (dp[i - 1][j + 1] * j +
                    (j != 1) * dp[i - 1][j - 1] * (j - (i > a) - (i > b))) %
                   MOD;
    }
  }
  cout << dp[n][1] << '\n';
}
