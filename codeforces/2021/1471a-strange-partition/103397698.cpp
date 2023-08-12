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
  ll minsum = 0, maxsum = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    minsum += a;
    maxsum += ((a + x - 1) / x);
  }
  cout << (minsum + x - 1) / x << " " << maxsum << '\n';
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
