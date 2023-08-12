#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>
#include <utility>
#include <vector>

const int maxN = 5e5 + 10;
const int shift = (1 << 19);

int incnt[maxN], newnum[maxN], n, m;
std::vector<int> g[maxN], tg[maxN];
int lstart[maxN], laft[maxN], lend[maxN], lbef[maxN], segTree[2 * shift + 10];

void topsort() {
  for (int i = 1; i <= n; i++)
    for (int v : g[i]) incnt[v]++;
  std::stack<int> s;
  for (int i = 1; i <= n; i++)
    if (incnt[i] == 0) s.push(i);

  int cnt = 1;
  while (!s.empty()) {
    int cur = s.top();
    s.pop();
    newnum[cur] = cnt++;
    for (int v : g[cur]) {
      incnt[v]--;
      if (incnt[v] == 0) s.push(v);
    }
  }
}

void update(int l, int r, int val) {
  l += shift - 1, r += shift - 1;
  segTree[l] = std::max(segTree[l], val);
  segTree[r] = std::max(segTree[r], val);
  while (r / 2 != l / 2) {
    if (l % 2 == 0) segTree[l + 1] = std::max(segTree[l + 1], val);
    if (r % 2 == 1) segTree[r - 1] = std::max(segTree[r - 1], val);
    l /= 2, r /= 2;
  }
}

int query(int u) {
  u += shift - 1;
  int ans = 0;
  while (u) {
    ans = std::max(ans, segTree[u]);
    u /= 2;
  }
  return ans;
}

void calc() {
  for (int i = 1; i <= n; i++)
    for (int v : tg[i]) lend[v] = std::max(lend[v], lend[i] + 1);

  for (int i = 1; i <= n; i++) lbef[i] = std::max(lbef[i - 1], lend[i]);

  std::vector<int> revtg[n + 2];
  for (int i = 1; i <= n; i++)
    for (int v : tg[i]) revtg[v].push_back(i);

  for (int i = n; i > 0; i--)
    for (int v : revtg[i]) lstart[v] = std::max(lstart[v], lstart[i] + 1);

  for (int i = n; i > 0; i--) laft[i] = std::max(laft[i + 1], lstart[i]);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::memset(segTree, 0, sizeof(segTree));
  std::cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    std::cin >> u >> v;
    g[u].push_back(v);
  }
  topsort();
  for (int i = 1; i <= n; i++) {
    int u = newnum[i];
    for (int v : g[i]) tg[u].push_back(newnum[v]);
  }
  calc();
  for (int i = 1; i <= n; i++) {
    for (int v : tg[i]) {
      int l = i + 1, r = v - 1;
      if (l > r) continue;
      update(i + 1, v - 1, lend[i] + lstart[v] + 1);
    }
  }
  std::pair<int, int> ans = {1e9, 1e9};
  for (int i = 1; i <= n; i++) {
    int maxval = std::max({lbef[i - 1], query(i), laft[i + 1]});
    ans = std::min(ans, std::make_pair(maxval, i));
  }
  for (int i = 1; i <= n; i++)
    if (newnum[i] == ans.second) std::cout << i << " ";
  std::cout << ans.first << '\n';
  return 0;
}
