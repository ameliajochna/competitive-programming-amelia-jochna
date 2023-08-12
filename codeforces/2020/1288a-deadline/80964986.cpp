#include <bits/stdc++.h>
using namespace std;

double f(double d, double x) { return x + ceil(d / (x + 1)); }

void solve() {
  int n, d;
  cin >> n >> d;
  double cs = sqrt(d) - 1;
  if (f(d, floor(cs)) <= n || f(d, ceil(cs)) <= n)
    cout << "YES\n";
  else
    cout << "NO\n";
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
