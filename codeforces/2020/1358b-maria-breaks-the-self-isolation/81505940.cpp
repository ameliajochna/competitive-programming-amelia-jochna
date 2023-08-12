#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
  int n;
  cin >> n;
  map<int, int> ocur;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    ocur[tmp]++;
  }
  int cur = 1, ans = 1;
  for (auto m : ocur) {
    if (cur + m.second - 1 >= m.first) ans = cur + m.second;
    cur += m.second;
  }
  cout << ans << '\n';
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
