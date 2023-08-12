#include <bits/stdc++.h>
#define nd second
#define st first
#define pll pair<ll, ll>
using namespace std;
typedef long long ll;
typedef long double ld;
int const MOD = 998244353;

ll inv(ll val) {
  if (val == 1) return 1;
  return inv(MOD % val) * (MOD - MOD / val) % MOD;
}

ll fact(ll n) {
  if (n == 0) return 1;
  return (n * fact(n - 1)) % MOD;
}

ll binom(ll n, ll k) {
  ll fn = fact(n), fk = fact(k), fnk = fact(n - k);
  // cout<<fn<<" "<<inv(fk)<<" "<<inv(fnk)<<'\n';
  return fn % MOD * inv(fk) % MOD * inv(fnk) % MOD;
}

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int cnt1 = 0, cnt0 = 0;
  for (auto a : s)
    if (a == '0') cnt0++;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1' && i + 1 < n && s[i + 1] == '1') {
      i++;
      cnt1++;
    }
  }
  cout << binom(cnt0 + cnt1, cnt0) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solve();
}
