#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

void solve() {
  int n, k;
  cin >> n >> k;
  if ((n - (k - 1) * 2) % 2 == 0 && n >= (k)*2) {
    cout << "YES\n";
    for (int i = 0; i < k - 1; i++) {
      cout << 2 << " ";
      n -= 2;
    }
    cout << n << '\n';
  } else {
    if ((n - k - 1) % 2 == 1 || n == k) {
      cout << "YES\n";
      for (int i = 0; i < k - 1; i++) {
        cout << 1 << " ";
        n--;
      }
      cout << n << "\n";
    } else {
      cout << "NO\n";
    }
  }
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
