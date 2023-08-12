#include <bits/stdc++.h>
#define nd second
#define st first
#define pll pair<ll, ll>
using namespace std;
typedef long long ll;
int const maxN = 510, MOD = 998244353;
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
          add(dp[i + 1][max(j - 1, 0LL)], dp[i][j]);
        else if (i > ind - 1 && j > 0)
          add(dp[i + 1][j - 1], dp[i][j]);
      }
    }
  }
  ll sum = 0;
  for (ll i = 0; i < n; i++) {
    sum += dp[n][i];
    sum %= MOD;
  }
  return sum;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  cin >> n;
  for (ll i = 1; i <= n; i++) {
    char c;
    cin >> c;
    if (c == '-')
      a[i] = -1;
    else {
      ll tmp;
      cin >> tmp;
      a[i] = tmp;
    }
  }
  ll ans = 0;
  for (ll pt = 1; pt <= n; pt++)
    if (a[pt] > 0) {
      ans += ((cnt(pt) * a[pt]) % MOD);
      ans %= MOD;
    }
  cout << ans << '\n';
}
