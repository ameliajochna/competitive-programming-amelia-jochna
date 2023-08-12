#include <bits/stdc++.h>
#define nd second
#define st first
#define pll pair<ll, ll>
using namespace std;
typedef long long ll;

void solve() {
  ll n, a, b;
  cin >> n >> a >> b;
  ll cur = 1;
  if (a == 1) {
    if ((n - 1) % b == 0)
      cout << "Yes\n";
    else
      cout << "No\n";
    return;
  }
  bool flag = false;
  while (cur <= n) {
    if ((n - cur) % b == 0) {
      flag = true;
      break;
    }
    cur *= a;
  }
  if (flag)
    cout << "Yes\n";
  else
    cout << "No\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
