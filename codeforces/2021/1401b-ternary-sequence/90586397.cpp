#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solution() {
  int x1, y1, z1, x2, y2, z2;
  ll sum = 0;
  cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
  int p = min(z1, y2);
  z1 -= p, y2 -= p;
  sum += 2 * p;
  p = min(z1, z2);
  z2 -= p, z1 -= p;
  p = min(z1, x2);
  z1 -= p, x2 -= p;
  p = min(x1, z2);
  x1 -= p, z2 -= p;
  p = min(y1, z2);
  y1 -= p, z2 -= p;
  sum -= 2 * p;
  // cout<<x1<<" "<<y1<<" "<<z1<<" "<<x2<<" "<<y2<<" "<<z2<<'\n';
  cout << sum << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();
}
