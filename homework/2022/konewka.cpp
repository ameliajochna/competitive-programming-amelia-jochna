#include <bits/stdc++.h>
using namespace std;
int const shift = (1 << 19);
pair<int, int> maxTree[2 * shift];  // maxTree : wartosc, indeks
int cntTree[2 * shift];
int nn, kk, lazy[2 * shift];

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
    maxTree[u] = max(maxTree[2 * u], maxTree[2 * u + 1]);
  }
}

pair<int, int> findMax() {
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
  maxTree[u] = max(maxTree[2 * u], maxTree[2 * u + 1]);
}

void eraseMax(int u) { updateMax(u, -INT_MAX); }

void updateCntTree(int u) {
  u += shift;
  while (u) {
    cntTree[u]++;
    u /= 2;
  }
}

void checkTree() {
  pair<int, int> maxonseg = findMax();
  while (maxonseg.first >= kk) {
    eraseMax(maxonseg.second);
    updateCntTree(maxonseg.second);
    maxonseg = findMax();
  }
}

int queries(int l, int r, int u = 1, int start = 0, int end = shift - 1) {
  propagate(u);
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

void inicjuj(int n, int k, int *D) {
  kk = k;
  nn = n;
  for (int i = 0; i < n; i++) updateMax(i, D[i]);
}

void podlej(int a, int b) { add(a, b); }

int dojrzale(int a, int b) { return queries(a, b); }
