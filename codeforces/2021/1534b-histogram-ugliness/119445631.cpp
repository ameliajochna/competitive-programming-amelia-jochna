#include <bits/stdc++.h>
#define nd second
#define st first
using namespace std;
typedef long long ll;

void solution() {
  ll n;
  cin >> n;
  vector<ll> a;
  for (int i = 0; i < n; i++) {
    ll tmp;
    cin >> tmp;
    a.push_back(tmp);
  }
  if (n == 1) {
    cout << a[0] << '\n';
    return;
  }
  ll op = 0;
  for (int i = 0; i < n; i++) {
    ll diff = 0;
    if (i == 0) {
      if (a[i] > a[i + 1]) diff = a[i] - a[i + 1];
    } else if (i == n - 1) {
      if (a[i] > a[i - 1]) diff = a[i] - a[i - 1];
    } else {
      if (a[i] > a[i + 1] && a[i] > a[i - 1]) {
        ll mval = max(a[i + 1], a[i - 1]);
        diff = a[i] - mval;
      }
    }
    op += diff;
    a[i] -= diff;
  }
  for (int i = 0; i < n - 1; i++) op += abs(a[i] - a[i + 1]);

  op += a[0] + a[n - 1];
  cout << op << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solution();
}
