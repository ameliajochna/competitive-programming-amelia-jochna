#include <bits/stdc++.h>
#define nd second
#define st first
#define pll pair<ll, ll>
using namespace std;
typedef long long ll;

void solve() {
  ll n;
  cin >> n;
  ll curlcm = 1, cnt = 0, MOD = 1e9 + 7;
  for (ll i = 2; i < 100; i++) {
    ll nextlcm = (curlcm * i) / __gcd(curlcm, ll(i));
    cnt += i * (ll(n / curlcm - n / nextlcm));
    cnt %= MOD;
    curlcm = nextlcm;
  }
  cout << cnt << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
