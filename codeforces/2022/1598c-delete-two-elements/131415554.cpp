#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
#define sz(a) a.size()
#define pb push_back
using namespace std;
typedef long long ll;

void solve() {
  int n;
  cin >> n;
  map<ll, ll> m;
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    ll tmp;
    cin >> tmp;
    m[n * tmp]++;
    sum += tmp;
  }
  ll ans = 0;
  for (auto x : m) {
    ll ex = 2 * sum - x.st;
    if (m.find(ex) != m.end()) {
      ans += (x.nd * m[ex]);
      if (ex == x.st) ans -= x.nd;
    }
  }
  cout << ans / 2 << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solve();
}
