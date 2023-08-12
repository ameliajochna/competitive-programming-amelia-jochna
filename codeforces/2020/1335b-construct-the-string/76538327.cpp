#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 * 2;

void solution() {
  int n, a, b;
  cin >> n >> a >> b;
  int ct = 0;
  for (int i = 0; i < n; i++) {
    if (ct % a == 0) ct = 0;
    cout << char('a' + ct % b);
    ct++;
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();

  return 0;
}
