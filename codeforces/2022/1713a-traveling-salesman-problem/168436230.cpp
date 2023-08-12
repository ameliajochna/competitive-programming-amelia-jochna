#include <bits/stdc++.h>
using namespace std;

void solution() {
  int n;
  cin >> n;
  int yn = 0, yp = 0, xn = 0, xp = 0;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if (x == 0) {
      if (y < 0) yn = max(yn, -y);
      if (y > 0) yp = max(yp, y);
    }
    if (y == 0) {
      if (x < 0) xn = max(xn, -x);
      if (x > 0) xp = max(xp, x);
    }
  }
  cout << 2 * (yn + yp + xn + xp) << '\n';
}

int main() {
  int t;
  cin >> t;
  while (t--) solution();
  return 0;
}
