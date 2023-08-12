#include <bits/stdc++.h>
using namespace std;

void solution() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];

  for (int i = 0; i < n - 1; i++) {
    int cur = min(v[i], k);
    v[n - 1] += cur;
    v[i] -= cur;
    k -= cur;
  }
  for (int i = 0; i < n; i++) cout << v[i] << " ";
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio();
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) solution();
}
