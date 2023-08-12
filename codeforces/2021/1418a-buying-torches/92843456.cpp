#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solution() {
  int x, y, k;
  cin >> x >> y >> k;
  cout << (ll(y) * k + k - 2) / (x - 1) + k + 1 << '\n';
}

int main() {
  int t = 1;
  cin >> t;
  while (t--) solution();
}
