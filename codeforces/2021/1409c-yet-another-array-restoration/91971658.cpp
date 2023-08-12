#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, x, y;
  cin >> n >> x >> y;
  int diff = y - x;
  for (int i = n - 2; i >= 0; i--) {
    // cout<<diff<<" "<<i<<'\n';
    if (diff % (i + 1) == 0) {
      int cnst = diff / (i + 1), cnt = n - i - 2, cur = x;
      while (cur - cnst > 0 && cnt > 0) {
        cout << cur - cnst << " ";
        cur -= cnst;
        cnt--;
      }
      cur = x;
      cnt = i + 2 + cnt;
      while (cnt > 0) {
        cout << cur << " ";
        cur += cnst;
        cnt--;
      }
      cout << '\n';
      return;
    }
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
