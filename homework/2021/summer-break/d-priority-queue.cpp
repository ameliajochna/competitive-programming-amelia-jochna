#include <algorithm>
#include <iostream>

typedef long long ll;
const int maxN = 510, MOD = 998244353;

ll dp[maxN][maxN], a[maxN], n;

void add(ll &a, ll b) {
  a += b;
  a %= MOD;
}

ll cnt(ll ind) {
  for (ll i = 0; i <= n; i++)
    for (ll j = 0; j <= n; j++) dp[i][j] = 0;

  ll val = a[ind];
  dp[0][0] = 1;
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < n; j++) {
      add(dp[i + 1][j], dp[i][j]);
      if (ind == i + 1)
        continue;
      else if (a[i + 1] > 0) {
        bool diff = (a[i + 1] < val || (a[i + 1] == val && i > ind - 1));
        add(dp[i + 1][j + diff], dp[i][j]);
      } else {
        if (i < ind - 1)
          add(dp[i + 1][std::max(j - 1, 0LL)], dp[i][j]);
        else if (i > ind - 1 && j > 0)
          add(dp[i + 1][j - 1], dp[i][j]);
      }
    }
  }
  ll sum = 0;
  for (ll i = 0; i < n; i++) {
    add(sum, dp[n][i]);
  }
  return sum;
}

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n;
  for (ll i = 1; i <= n; i++) {
    char c;
    std::cin >> c;
    if (c == '-')
      a[i] = -1;
    else {
      ll tmp;
      std::cin >> tmp;
      a[i] = tmp;
    }
  }
  ll ans = 0;
  for (ll pt = 1; pt <= n; pt++) {
    if (a[pt] > 0) {
      add(ans, (cnt(pt) * a[pt]) % MOD);
    }
  }
  std::cout << ans << '\n';
}
