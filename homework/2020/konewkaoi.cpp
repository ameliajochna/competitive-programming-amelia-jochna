#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
int const shift = (1 << 19);
std::pair<int, int> maxTree[2 * shift];  // maxTree : wartosc, indeks
int cntTree[2 * shift];
int n, k, q, lazy[2 * shift];

void propagate(int u) {
  maxTree[u].first += lazy[u];
  if (u < shift) {
    lazy[2 * u] += lazy[u];
    lazy[2 * u + 1] += lazy[u];
  }
  lazy[u] = 0;
}

void updateMax(int u, int v) {
  maxTree[u + shift] = {v, u};
  u += shift;
  while (u /= 2) {
    propagate(u);
    propagate(2 * u);
    propagate(2 * u + 1);
    maxTree[u] = std::max(maxTree[2 * u], maxTree[2 * u + 1]);
  }
}

std::pair<int, int> findMax() {
  propagate(1);
  return maxTree[1];
}

void add(int l, int r, int u = 1, int start = 0, int end = shift - 1) {
  propagate(u);
  if (r < start || l > end) return;
  if (l <= start && end <= r) {
    lazy[u]++;
    propagate(u);
    return;
  }
  int mid = (start + end) / 2;
  add(l, r, 2 * u, start, mid);
  add(l, r, 2 * u + 1, mid + 1, end);
  maxTree[u] = std::max(maxTree[2 * u], maxTree[2 * u + 1]);
}

void eraseMax(int u) { updateMax(u, -std::numeric_limits<int>::max()); }

void updateCntTree(int u) {
  u += shift;
  while (u) {
    cntTree[u]++;
    u /= 2;
  }
}

void checkTree() {
  std::pair<int, int> maxonseg = findMax();
  while (maxonseg.first >= k) {
    eraseMax(maxonseg.second);
    updateCntTree(maxonseg.second);
    maxonseg = findMax();
  }
}

int queries(int l, int r, int u = 1, int start = 0, int end = shift - 1) {
  if (r < start || l > end) return 0;
  if (l <= start && end <= r) {
    checkTree();
    return cntTree[u];
  }
  int mid = (start + end) / 2;
  int q1 = queries(l, r, 2 * u, start, mid);
  int q2 = queries(l, r, 2 * u + 1, mid + 1, end);
  return q1 + q2;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::cin >> n >> k >> q;
  for (int i = 0; i < n; i++) {
    int a;
    std::cin >> a;
    updateMax(i, a);
  }
  int prevans = 0;
  for (int i = 0; i < q; i++) {
    int type;
    std::cin >> type;
    if (type == 0) {
      int l, r;
      std::cin >> l >> r;
      add(l, r);
    } else {
      int l1, r1, l2, r2;
      std::cin >> l1 >> r1 >> l2 >> r2;
      if (prevans % 2 == 0)
        prevans = queries(l1, r1);
      else
        prevans = queries(l2, r2);
      std::cout << prevans << '\n';
    }
  }
}
