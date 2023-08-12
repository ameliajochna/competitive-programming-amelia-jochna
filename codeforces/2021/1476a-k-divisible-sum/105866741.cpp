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
  if (k >= n)
    cout << k / n + (k % n > 0) << '\n';
  else {
    k = n - n % k + (k * ((n % k) > 0));
    cout << k / n + (k % n > 0) << '\n';
  }
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
