#include <iostream>

typedef long long ll;

int const shift = (1 << 20);
int n;

struct node {
  ll leftb, rightb, sum, best;
  node(ll val = 0) {
    leftb = val;
    rightb = val;
    sum = val;
    best = val;
  }
};

node segtree[2 * shift];

node add(node l, node r) {
  node ans;
  ans.leftb = std::max(l.leftb, l.sum + r.leftb);
  ans.rightb = std::max(r.rightb, r.sum + l.rightb);
  ans.sum = l.sum + r.sum;
  ans.best = std::max({l.rightb + r.leftb, l.best, r.best});
  return ans;
}

void change(int i, ll val) {
  i += shift - 1;
  segtree[i] = node(val);
  i /= 2;
  while (i) {
    segtree[i] = add(segtree[2 * i], segtree[2 * i + 1]);
    i /= 2;
  }
}

node query(int l, int r, int u = 1, int start = 0, int end = shift - 1) {
  if (l > end || start > end || r < start) return node();
  if (start >= l && end <= r) return segtree[u];
  int av = (start + end) / 2;
  node L = query(l, r, 2 * u, start, av);
  node R = query(l, r, 2 * u + 1, av + 1, end);
  return add(L, R);
}

ll ans(int a, int b) { return std::max(query(a - 1, b - 1).best, 0LL); }

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    ll e;
    std::cin >> e;
    change(i, e);
  }
  int q;
  std::cin >> q;
  for (int i = 0; i < q; i++) {
    char type;
    std::cin >> type;
    int a, b;
    std::cin >> a >> b;
    if (type == 'Q')
      std::cout << ans(a, b) << '\n';
    else
      change(a, b);
  }
  return 0;
}
