#include <bits/stdc++.h>
using namespace std;

void solution() {
  int n, k1, k2, w, b;
  cin >> n >> k1 >> k2 >> w >> b;
  int v1 = min(k1, k2);
  w -= v1;
  if (v1 != max(k1, k2)) {
    int v2 = max(k1, k2) - v1;
    if (v2 % 2 == 1) {
      v2--;
    }
    w -= (v2 / 2);
    b -= (v2 / 2);
  }
  int v3 = n - max(k1, k2);
  b -= (v3);
  if (w <= 0 && b <= 0)
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) solution();
}
