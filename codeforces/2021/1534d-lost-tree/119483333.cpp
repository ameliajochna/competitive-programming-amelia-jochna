#include <bits/stdc++.h>
#define nd second
#define st first
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  set<int> s;
  vector<bool> vis(n + 1), good(n + 1);
  s.insert(1);
  int par = 0;
  vector<pair<int, int> > ed;
  while (!s.empty()) {
    int cur = *s.begin();
    s.erase(s.begin());
    cout << "? " << cur << '\n';
    cout.flush();
    vis[cur] = true;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) cin >> ans[i];
    if (cur == 1) {
      int cnt[2] = {0, 0};
      for (auto dis : ans) cnt[dis % 2]++;
      if (cnt[0] <= cnt[1])
        par = 0;
      else
        par = 1;
      for (int i = 0; i < n; i++) {
        if (ans[i] % 2 == par) {
          good[i + 1] = true;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      int k = ans[i];
      if (k == 1) {
        int v1 = i + 1, v2 = cur;
        if (v1 > v2) swap(v1, v2);
        ed.push_back({v1, v2});
      }
      if (good[i + 1] && !vis[i + 1]) s.insert(i + 1);
    }
  }
  sort(ed.begin(), ed.end());
  ed.erase(unique(ed.begin(), ed.end()), ed.end());
  cout << "!\n";
  for (auto p : ed) cout << p.first << " " << p.second << '\n';
}
