#include <bits/stdc++.h>
using namespace std;
int const N = 1e5 + 10;
int a[N];

void solution() {
  int n, x;
  cin >> n >> x;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  reverse(a + 1, a + n + 1);
  long long sum = 0;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    sum += a[i] - x;
    if (sum >= 0) ans = i;
  }
  cout << ans << '\n';
}

int main() {
  int t;
  cin >> t;
  while (t--) solution();
  return 0;
}
