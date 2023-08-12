#include <bits/stdc++.h>
using namespace std;

void solution() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  int k = v[0], maxval = v[0];
  for (int i = 1; i < n; i++) k = __gcd(k, v[i]), maxval = max(maxval, v[i]);
  cout << maxval / k << '\n';
}

int main() {
  int t;
  cin >> t;
  while (t--) solution();
  return 0;
}
