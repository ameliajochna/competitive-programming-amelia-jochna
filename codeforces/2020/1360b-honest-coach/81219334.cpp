#include <bits/stdc++.h>
using namespace std;
int const inf = 1e9;
typedef long long ll;
void solve() {
  int n;
  cin >> n;
  vector<int> s(n);
  for (int i = 0; i < n; i++) cin >> s[i];
  sort(s.begin(), s.end());
  int mindiff = inf;
  for (int i = 1; i < n; i++) {
    mindiff = min(mindiff, s[i] - s[i - 1]);
  }
  cout << mindiff << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solve();
}
