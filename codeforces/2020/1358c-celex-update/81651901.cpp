#include <bits/stdc++.h>
using namespace std;
int const mod = 1000000007;
typedef long long ll;

void solution() {
  ll x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  cout << (x2 - x1) * (y2 - y1) + 1 << '\n';
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
