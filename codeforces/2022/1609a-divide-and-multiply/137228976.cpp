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
  vector<ll> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int cnt = 0;
  for (int i = 0; i < n; i++)
    while (v[i] % 2 == 0) v[i] /= 2, cnt++;

  sort(v.begin(), v.end());
  v[n - 1] *= (1LL << cnt);

  ll sum = 0;
  for (int i = 0; i < n; i++) sum += v[i];
  cout << sum << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solve();
}
