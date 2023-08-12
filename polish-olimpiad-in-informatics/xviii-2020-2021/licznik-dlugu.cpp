#include <bits/stdc++.h>
using namespace std;
#define st first
#define nd second
#define pii pair<int, int>
int const shift = (1 << 17);
vector<int> s1, s2;
int n = INT_MAX, z, timecnt = 1;
pair<int, int> Tree[2 * shift + 5];  // first->value, second->time
map<int, int> nine, zero;            // przedzialy i, nine[i]; i, zero[i];

void addsegment(int l, int r, map<int, int> &m) {
  if (l < 0 || r > n || l > r || (l == 0 && r == 0)) return;
  if (l == 0) l++;
  bool flag = false;
  auto p1 = --m.upper_bound(l);
  pii start = *p1;
  auto p2 = m.upper_bound(l);
  pii end = *p2;
  if (start.nd == l - 1) {
    m[start.st] = r;
    l = start.st;
    flag = true;
  }
  if (end.st == r + 1) {
    m.erase(p2);
    m[l] = end.nd;
    flag = true;
  }
  if (!flag) m[l] = r;
}

void chsgmt(int l, int r, int value) {
  if (value == 9)
    addsegment(l, r, nine);
  else if (value == 0)
    addsegment(l, r, zero);
}

void splitting(int u, map<int, int> &m) {
  if (u <= 0) return;
  auto pt = --m.upper_bound(u);
  pii seg = *pt;
  if (seg.st == -INT_MAX) return;
  if (seg.st == u) {
    m.erase(pt);
    if (seg.nd != u) m[u + 1] = seg.nd;
    return;
  }
  if (u != 0) m[seg.st] = u - 1;
  if (seg.nd != u) m[u + 1] = seg.nd;
}

void splitsg(int u, int val) {
  if (val == 9)
    splitting(u, nine);
  else if (val == 0)
    splitting(u, zero);
}

void updateTree(int l, int r, int value) {
  if (l < 0 || r > 2 * shift || l > r) return;
  if (value == 0 || value == 9) chsgmt(l, r, value);
  l += shift, r += shift;
  pii cur = {value, timecnt};
  Tree[l] = cur;
  if (l == r) return;
  Tree[r] = cur;
  while (l / 2 != r / 2) {
    if (l % 2 == 0) Tree[l + 1] = cur;
    if (r % 2 == 1) Tree[r - 1] = cur;
    l /= 2, r /= 2;
  }
}

int valueTree(int u) {
  u += shift;
  pii ans = {0, 0};
  while (u) {
    if (ans.nd <= Tree[u].nd) ans = Tree[u];
    u /= 2;
  }
  return ans.st;
}

void calcsum() {
  int left = 0;
  for (int i = n - 1; i >= 0; i--) {
    int v1 = s1[i], v2 = s2[i];
    updateTree(i, i, ((v1 + v2) + left) % 10);
    left = (v1 + v2 + left) / 10;
  }
}

void decrease(int diff, int u) {
  int sumpnt = valueTree(u);
  if (sumpnt == 0 || sumpnt == 9) splitsg(u, sumpnt);

  if (sumpnt - diff < 0) {
    updateTree(u, u, sumpnt - diff + 10);
    auto pt = --zero.upper_bound(u);
    pii seg = *pt;
    int lpnt = u - 1;
    if (seg.nd == u - 1) {
      zero.erase(pt);
      updateTree(seg.st, seg.nd, 9);
      lpnt = seg.st - 1;
    }
    int leftval = valueTree(lpnt);
    if (leftval == 9) splitsg(lpnt, 9);
    updateTree(lpnt, lpnt, leftval - 1);
  } else
    updateTree(u, u, sumpnt - diff);
}

void increase(int diff, int u) {
  int sumpnt = valueTree(u);
  if (sumpnt == 0 || sumpnt == 9) splitsg(u, sumpnt);
  if (sumpnt + diff >= 10) {
    updateTree(u, u, sumpnt + diff - 10);
    auto pt = --nine.upper_bound(u);
    pii seg = *pt;
    int lpnt = u - 1;
    if (seg.nd == u - 1) {
      nine.erase(pt);
      updateTree(seg.st, seg.nd, 0);
      lpnt = seg.st - 1;
    }
    int leftval = valueTree(lpnt);
    if (leftval == 0) splitsg(lpnt, 0);
    updateTree(lpnt, lpnt, leftval + 1);
  } else
    updateTree(u, u, sumpnt + diff);
}

void change(int u, int val, vector<int> &s) {
  int cur = s[u];
  s[u] = val;
  if (val == cur)
    return;
  else if (val < cur)
    decrease(cur - val, u);
  else if (val > cur)
    increase(val - cur, u);
}

void queries() {
  for (int i = 0; i < z; i++) {
    timecnt++;
    char type;
    cin >> type;
    if (type == 'W') {
      int u, val;
      cin >> u >> val;
      change(n - u, val, s1);
    } else if (type == 'Z') {
      int u, val;
      cin >> u >> val;
      change(n - u, val, s2);
    } else if (type == 'S') {
      int u;
      cin >> u;
      cout << valueTree(n - u) << '\n';
    }
  }
}

void convinp() {
  s1.resize(n);
  s2.resize(n);
  s1[0] = 0;
  for (int i = 0; i < n - 1; i++) {
    char a;
    cin >> a;
    s1[i + 1] = a - '0';
  }
  s2[0] = 0;
  for (int i = 0; i < n - 1; i++) {
    char a;
    cin >> a;
    s2[i + 1] = a - '0';
  }
}

int main() {
  nine[-INT_MAX] = -INT_MAX;
  nine[INT_MAX] = INT_MAX;
  zero[-INT_MAX] = -INT_MAX;
  zero[INT_MAX] = INT_MAX;
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  cin >> n >> z;
  convinp();
  calcsum();
  queries();
}
