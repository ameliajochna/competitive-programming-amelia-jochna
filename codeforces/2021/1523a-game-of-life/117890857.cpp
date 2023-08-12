#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solution() {
  int n, m;
  cin >> n >> m;
  string v, v2;
  cin >> v;
  v = '0' + v;
  for (int i = 0; i <= n; i++) v2.push_back('0');
  int prev;
  for (int i = 1; i <= n; i++) {
    if (v[i] == '1') {
      int cnt = 0;
      while (cnt <= m && i - cnt > 0) {
        v2[i - cnt] = '1';
        cnt++;
      }
      prev = i;
      break;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (v[i] == '1') {
      if (i == prev) continue;
      // przedzial prev - continue
      int s = prev, e = i;
      int cnt = m;
      while (cnt >= 0 && s < e) {
        v2[s] = '1';
        v2[e] = '1';
        s++, e--;
        cnt--;
      }
      prev = i;
    }
  }
  for (int i = prev; i <= n; i++) {
    if (v[i] == '1') {
      int cnt = 0;
      while (cnt <= m && i + cnt <= n) {
        v2[i + cnt] = '1';
        cnt++;
      }
      break;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << v2[i];
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solution();
}
