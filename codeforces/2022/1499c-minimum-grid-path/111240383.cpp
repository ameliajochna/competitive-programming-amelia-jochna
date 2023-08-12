#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solution() {
  int n;
  cin >> n;
  vector<ll> c(n + 1);
  for (int i = 1; i <= n; i++) cin >> c[i];
  long long osum = c[1], esum = 0, ocnt = 1, ecnt = 0, omin = c[1], emin = 1e18,
            bestans = 1e18;
  for (int i = 2; i <= n; i++) {
    if (i % 2 == 0) {
      esum += c[i];
      ecnt++;
      emin = min(emin, c[i]);
    }
    if (i % 2 == 1) {
      osum += c[i];
      ocnt++;
      omin = min(omin, c[i]);
    }
    ll ecost = esum + (n - ecnt) * emin, ocost = osum + (n - ocnt) * omin;
    // cout<<ecost<<" "<<ocost<<"\n";
    bestans = min(bestans, ecost + ocost);
  }
  cout << bestans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) solution();
}
