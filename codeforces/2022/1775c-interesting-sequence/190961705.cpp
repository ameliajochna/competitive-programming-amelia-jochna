#include <bits/stdc++.h>
using namespace std;
#define fast                    \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
#define int long long

bool ok(int n, int m, int x) {
  // cout<<n<<" "<<m<<" "<<x<<'\n';
  int nw = n;
  for (int i = 0; i < 63; i++) {
    int bt1 = (n >> i) & 1, bt2 = (x >> i) & 1;
    int nwbt = (nw >> i) & 1;
    // cout<<i<<" "<<nwbt<<'\n';
    if (nwbt == 1) nw ^= (1LL << i);

    int fst1, fst0;
    if (bt1) {
      fst1 = n;
      fst0 = nw + (1LL << (i + 1));
    }
    if (!bt1) {
      fst0 = n;
      fst1 = nw + (1LL << i);
    }
    // cout<<i<<" "<<fst0<<" "<<fst1<<" "<<nw<<'\n';
    if (bt1 && bt2 && fst0 <= m)
      return false;
    else if (bt1 && !bt2 && fst0 > m)
      return false;
  }
  return true;
}

void solve() {
  int n, x;
  cin >> n >> x;
  int lst = x;
  for (int i = 0; i < 64; i++) {
    int bt1 = (n >> i) & 1, bt2 = (x >> i) & 1;
    if (bt2 && !bt1) {
      cout << -1 << '\n';
      return;
    }
  }
  if (n <= lst) {
    cout << lst << '\n';
    return;
  }
  for (int i = 0; i < 64; i++) {
    int cur = lst;
    if (!((cur >> i) & 1)) {
      cur |= (1LL << i);
      if (n <= cur && ok(n, cur, x)) {
        cout << cur << '\n';
        return;
      }
    }
  }
  cout << "-1\n";
}

int32_t main() {
  fast;
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
