#include <algorithm>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  int n;
  std::cin >> n;
  std::set<int> s;
  std::vector<bool> vis(n + 1), good(n + 1);
  s.insert(1);
  int par = 0;
  std::vector<std::pair<int, int> > ed;
  while (!s.empty()) {
    int cur = *s.begin();
    s.erase(s.begin());
    std::cout << "? " << cur << '\n';
    std::cout.flush();
    vis[cur] = true;
    std::vector<int> ans(n);
    for (int i = 0; i < n; i++) std::cin >> ans[i];
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
        if (v1 > v2) std::swap(v1, v2);
        ed.push_back({v1, v2});
      }
      if (good[i + 1] && !vis[i + 1]) s.insert(i + 1);
    }
  }
  std::sort(ed.begin(), ed.end());
  ed.erase(std::unique(ed.begin(), ed.end()), ed.end());
  std::cout << "!\n";
  for (auto p : ed) std::cout << p.first << " " << p.second << '\n';
}
