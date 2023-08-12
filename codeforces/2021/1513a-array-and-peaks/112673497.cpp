#include <bits/stdc++.h>
using namespace std;

void solution() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  if (2 * k >= n) {
    cout << "-1\n";
    return;
  }
  int cur = n;
  for (int i = 0; i < k; i++) {
    v[i * 2 + 1] = cur--;
  }
  cur = 1;
  for (int i = 0; i < n; i++) {
    if (v[i] == 0) v[i] = cur++;
  }
  for (int i = 0; i < n; i++) cout << v[i] << " ";
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
