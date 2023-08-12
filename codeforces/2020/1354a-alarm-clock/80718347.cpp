#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
void solution() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a <= b)
    cout << b << '\n';
  else if (c <= d) {
    cout << -1 << '\n';
  } else if (c != d && a != b) {
    a -= b;
    cout << ll(b) + (ll(a - 1) / (c - d) + 1) * c << '\n';
  }
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
