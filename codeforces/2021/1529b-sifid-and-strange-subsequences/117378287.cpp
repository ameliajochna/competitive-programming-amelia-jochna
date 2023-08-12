#include <bits/stdc++.h>
using namespace std;

void solution() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end());
  int cnt = 1, mindis = 1e9;
  for (int i = 1; i < n; i++) {
    if (abs(v[i] - v[i - 1]) < mindis) mindis = abs(v[i] - v[i - 1]);
    if (mindis >= v[i]) cnt++;
  }
  cout << cnt << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();
}
