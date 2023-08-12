#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second
#define ll long long

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  ll sum = a[0], inc = 0;
  for (int i = 1; i < n; i++) {
    ll diff = max(((ll)(100) * a[i] - 1) / k - sum + 1, (ll)(0));
    sum += diff;
    inc += diff;

    sum += a[i];
  }
  cout << inc << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
