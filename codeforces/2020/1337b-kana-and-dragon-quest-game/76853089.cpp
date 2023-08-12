#include <bits/stdc++.h>
using namespace std;

void solution() {
  int x, n, m;
  cin >> x >> n >> m;
  while (n > 0 && x > 20) {
    n--;
    x = floor(x / 2) + 10;
  }
  x -= m * 10;
  if (x > 0)
    cout << "NO\n";
  else
    cout << "YES\n";
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
