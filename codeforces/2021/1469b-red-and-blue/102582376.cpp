#include <bits/stdc++.h>
using namespace std;
#define st first
#define nd second
typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  int n, m;
  cin >> n;
  vector<int> rpsum(n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    sum += tmp;
    rpsum[i] = sum;
  }
  sum = 0;
  cin >> m;
  vector<int> bpsum(m);
  for (int i = 0; i < m; i++) {
    int tmp;
    cin >> tmp;
    sum += tmp;
    bpsum[i] = sum;
  }
  int ans = 0, maxp1 = rpsum[0], maxp2 = bpsum[0];
  for (int i = 0; i < n; i++) maxp1 = max(maxp1, rpsum[i]);

  for (int i = 0; i < m; i++) maxp2 = max(maxp2, bpsum[i]);

  ans += max(0, maxp2) + max(0, maxp1);
  cout << ans << '\n';
}

int main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
