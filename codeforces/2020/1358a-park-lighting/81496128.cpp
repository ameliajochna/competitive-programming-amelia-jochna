#include <iostream>
using namespace std;
typedef long long ll;
void solve() {
  ll a, b;
  cin >> a >> b;
  ll ans = (ll(a) * (b - b % 2) / 2) + (ll((b % 2)) * a) / 2;
  if (a % 2 == 1 && b % 2 == 1) ans++;
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
