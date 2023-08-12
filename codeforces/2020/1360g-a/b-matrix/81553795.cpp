#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  if (n * a != m * b) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  int d = 0;
  for (int i = 1; i < m; i++)
    if ((i * n) % m == 0) {
      d = i;
      break;
    }
  string first;
  for (int i = 0; i < a; i++) cout << 1, first.push_back('1');
  for (int i = a; i < m; i++) cout << 0, first.push_back('0');
  cout << '\n';
  for (int i = 1; i < n; i++) {
    string tmp = first;
    for (int j = 0; j < m; j++) {
      first[j] = tmp[((j + d) % m)];
    }
    cout << first << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
