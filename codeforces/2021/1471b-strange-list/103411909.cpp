#include <bits/stdc++.h>
using namespace std;
#define nd second
#define st first
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve() {
  int n, x;
  cin >> n >> x;
  vector<pll> v(n);  // val, cnt
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i].st;
    v[i].nd = 1;
    sum += v[i].st;
  }

  bool flag = true;
  while (flag) {
    for (int i = 0; i < n; i++) {
      if (v[i].st % x != 0) {
        flag = false;
        break;
      }

      v[i] = {v[i].st / x, v[i].nd * x};
      sum += (v[i].st) * v[i].nd;
      // cout<<v[i].st<<" "<<v[i].nd<<'\n';
    }
  }
  cout << sum << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
