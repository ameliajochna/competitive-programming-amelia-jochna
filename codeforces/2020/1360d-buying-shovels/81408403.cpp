#include <bits/stdc++.h>
using namespace std;

void solution() {
  int n, k;
  cin >> n >> k;
  int ans = 1e9;
  for (int i = 1; i * i <= n; i++)
    if (n % i == 0) {
      if (i <= k) ans = min(ans, n / i);
      if (n / i <= k) ans = min(ans, i);
    }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();
  return 0;
}
