#include <bits/stdc++.h>
using namespace std;
#define st first
#define nd second
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;

int const shift = (1 << 16), inf = 1e9;
int n, m, z, segtree[2 * shift + 10], lazy[2 * shift + 10];

void propagate(int u) {
  if (u > 2 * shift) return;
  segtree[u] += lazy[u];
  if (u < shift) {
    lazy[2 * u] += lazy[u];
    lazy[2 * u + 1] += lazy[u];
  }
  lazy[u] = 0;
}

void update(int l, int r, int val, int u = 1, int a = 0, int b = shift - 1) {
  propagate(u);
  if (u > 2 * shift || a > b || r < a || b < l) return;
  if (l <= a && b <= r) {
    lazy[u] += val;
    propagate(u);
    propagate(2 * u);
    propagate(2 * u + 1);
    if (u < shift) segtree[u] = min(segtree[2 * u], segtree[2 * u + 1]);
    return;
  }
  int mid = (a + b) / 2;
  update(l, r, val, 2 * u, a, mid);
  update(l, r, val, 2 * u + 1, mid + 1, b);
  if (u < shift) segtree[u] = min(segtree[2 * u], segtree[2 * u + 1]);
}

int query(int l, int r, int u = 1, int a = 0,
          int b = shift - 1) {  // l,r->przedzial ktorego szukamy
  propagate(u);                 // a,b->przedzial obejmowany przez wierzcholek u
  if (u > 2 * shift || a > b || r < a || b < l) return inf;
  if (l <= a && b <= r) return segtree[u];
  int mid = (a + b) / 2;
  int leftans = query(l, r, 2 * u, a, mid),
      rightans = query(l, r, 2 * u + 1, mid + 1, b);
  return min(leftans, rightans);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  scanf("%d%d%d", &n, &m, &z);
  update(0, n - 1, m);
  for (int i = 0; i < z; i++) {
    int l, r, val;
    scanf("%d%d%d", &l, &r, &val);
    l--, r -= 2;
    if (query(l, r) >= val) {
      update(l, r, -val);
      printf("T\n");
    } else
      printf("N\n");
  }
  return 0;
}
