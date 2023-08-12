#include <bits/stdc++.h>
#define nd second
#define st first
#define pll pair<ll, ll>
using namespace std;
typedef long long ll;

void solve() {
  int n;
  cin >> n;
  int oddcnt = 0, evcnt = 0;
  for (int i = 0; i < 2 * n; i++) {
    int tmp;
    cin >> tmp;
    if (tmp % 2 == 0)
      evcnt++;
    else
      oddcnt++;
  }
  if (evcnt == oddcnt)
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
