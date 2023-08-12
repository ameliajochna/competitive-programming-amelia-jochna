#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
#define sz(a) a.size()
using namespace std;
typedef long long ll;
ll const MOD = 1e9 + 7;

long long binpow(long long a, long long b) {
  if (b == 0) return 1;
  long long res = binpow(a, b / 2);
  res %= MOD;
  if (b % 2)
    return ((res * res) % MOD * a) % MOD;
  else
    return (res * res) % MOD;
}

void solution() {
  ll k;
  cin >> k;
  ll nodes = (1LL << (k)) - 2;
  cout << (ll(6) * binpow(4, nodes)) % MOD << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  solution();
}
