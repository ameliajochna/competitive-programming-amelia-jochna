#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solution() {
  int n, k;
  cin >> n >> k;
  int minv = INT_MAX, ind = 0, maxv = -INT_MAX;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] < minv) minv = a[i], ind = i;
    maxv = max(maxv, a[i]);
  }
  if (maxv > k) {
    cout << "0\n";
    return;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (i != ind) {
      ans += (k - a[i]) / minv;
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) solution();
}
