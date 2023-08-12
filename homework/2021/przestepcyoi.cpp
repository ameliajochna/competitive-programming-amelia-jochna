#include <algorithm>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

int const maxN = 1e6 + 10;
int c[maxN], lft[maxN], rght[maxN], lans[maxN], rans[maxN];
int n, k, last, m, l;
std::vector<int> pos[maxN];
std::set<std::pair<int, int> > s;

void calcleft() {
  for (int i = 0; i < n; i++) lans[i] = 1e9;
  for (int i = 0; i < n; i++) pos[c[i]].push_back(i);
  for (auto x : pos[lft[m - 1]]) lans[x] = x;
  for (int i = m - 2; i >= 0; i--) {
    for (int j = 0; j < pos[lft[i]].size(); j++) {
      std::vector<int> &nextv = pos[lft[i + 1]];
      std::vector<int> &cur = pos[lft[i]];
      auto ub = std::upper_bound(nextv.begin(), nextv.end(), cur[j]);
      if (ub == nextv.end()) continue;
      lans[cur[j]] = lans[*ub];
    }
  }

  int tmpmin = 1e9;
  for (int i = n - 1; i >= 0; i--) {
    if (c[i] == lft[0])
      tmpmin = std::min(tmpmin, lans[i]);
    else
      lans[i] = tmpmin;
  }
}

void calcright() {
  for (int i = 0; i < n; i++) rans[i] = -1;
  for (auto x : pos[rght[l - 1]]) rans[x] = x;
  for (int i = l - 2; i >= 0; i--) {
    for (int j = 0; j < pos[rght[i]].size(); j++) {
      std::vector<int> &nextv = pos[rght[i + 1]];
      std::vector<int> &cur = pos[rght[i]];
      auto lb = std::lower_bound(nextv.begin(), nextv.end(), cur[j]);
      if (lb == nextv.begin()) continue;
      lb--;
      rans[cur[j]] = rans[*lb];
    }
  }

  int tmpmax = -1;
  for (int i = 0; i < n; i++) {
    if (c[i] == rght[0])
      tmpmax = std::max(tmpmax, rans[i]);
    else
      rans[i] = tmpmax;
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> n >> k;
  for (int i = 0; i < n; i++) std::cin >> c[i];
  std::cin >> m >> l;
  for (int i = 0; i < m; i++) std::cin >> lft[i];
  for (int i = 0; i < l; i++) std::cin >> rght[i];
  last = lft[m - 1];
  calcleft();
  calcright();

  for (int i = 1; i <= k; i++) {
    if (pos[i].size() > 1) {
      int l = lans[pos[i][0] + 1], r = rans[pos[i][pos[i].size() - 1] - 1];
      if (l <= r) s.insert(std::make_pair(l, r));
    }
  }
  std::vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (c[i] == last && !s.empty()) {
      std::pair<int, int> np = std::make_pair(i, -1e9);
      auto ub = s.lower_bound(np);
      if (ub == s.end()) ub--;
      std::pair<int, int> tmp = std::make_pair(ub->first, ub->second);
      if (tmp.first <= i && i <= tmp.second)
        ans.push_back(i);
      else {
        if (ub != s.begin()) ub--;
        tmp = std::make_pair(ub->first, ub->second);
        if (tmp.first <= i && i <= tmp.second) ans.push_back(i);
      }
    }
  }
  std::cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); i++) std::cout << ans[i] + 1 << ' ';

  return 0;
}
