#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> val(n + 1);
  map<int, int> cnt;
  int maxval = 0, diff = 0;
  for (int i = 0; i < n; i++) {
    cin >> val[i];
    if (val[i] > maxval) maxval = val[i];
    if (cnt[val[i]] == 0) diff++;
    cnt[val[i]]++;
  }
  if (diff > k)
    cout << -1;
  else {
    vector<int> key;
    for (auto i : cnt) {
      key.push_back(i.first);
    }
    while (key.size() < k) key.push_back(key[0]);
    vector<int> ans;
    int j = 0, e = 0;
    while (j < n) {
      if (key[e] == val[j]) j++;
      ans.push_back(key[e]);
      e++;
      e = e % k;
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  }
  cout << '\n';
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
