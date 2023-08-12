#include <bits/stdc++.h>
using namespace std;

void solution() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  vector<bool> ans(n);
  int cnt = 0;
  for (int i = n - 1; i >= 0; i--) {
    cnt = max(v[i], cnt - 1);
    if (cnt > 0) ans[i] = 1;
  }
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;

  while (t--) solution();
}
