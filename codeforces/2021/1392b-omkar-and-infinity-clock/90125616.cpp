#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solution() {
  ll n, k;
  cin >> n >> k;
  vector<int> v(n);
  int tmp = -INT_MAX;
  bool dif = false;
  for (int i = 0; i < n; i++) {
    cin >> v[i], tmp = max(tmp, v[i]);
    if (v[i] != v[0]) dif = true;
  }
  if (!dif) {
    for (int i = 0; i < n; i++) cout << 0 << " ";
    cout << '\n';
    return;
  }

  for (int i = 0; i < n; i++) v[i] = tmp - v[i];
  if (k % 2 == 1) {
    for (int i = 0; i < n; i++) cout << v[i] << " ";
    cout << '\n';
    return;
  }
  tmp = -INT_MAX;
  for (int i = 0; i < n; i++) tmp = max(tmp, v[i]);
  for (auto &e : v) e = tmp - e;
  for (auto e : v) cout << e << " ";
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();
}
