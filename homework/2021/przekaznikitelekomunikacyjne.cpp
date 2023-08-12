#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

typedef long long ll;
const int shift = (1 << 19);
ll tree[2 * shift + 10];
std::pair<ll, ll> lazy[2 * shift + 10];  // a1, r
std::map<int, std::pair<int, int> > m;   // x, {s, a};

std::pair<ll, ll> operator+(std::pair<ll, ll> a, std::pair<ll, ll> b) {
  return {a.first + b.first, a.second + b.second};
}

void propagate(int u, int x, int y) {
  if (u > 2 * shift) return;
  ll a1 = lazy[u].first, r = lazy[u].second;
  int len = (y - x + 1);
  ll segsum = ((2 * a1 + (len - 1) * r) * len) / 2;
  tree[u] += segsum;

  if (u < shift) {
    lazy[2 * u] = lazy[2 * u] + lazy[u];
    lazy[2 * u + 1] =
        lazy[2 * u + 1] + std::make_pair(a1 + r * (y - x + 1) / 2, r);
  }
  lazy[u] = {0, 0};
}

void add(int x, int y, ll a1, ll r, int u = 1, int a = 0,
         int b = shift - 1) {  //(a,b) - aktualne, (x,y) - docelowe
  propagate(u, a, b);
  if (u > 2 * shift || y < a || b < x) return;
  if (x <= a && b <= y) {
    lazy[u] = lazy[u] + std::make_pair(a1 + (a - x) * r, r);
    propagate(u, a, b);
    return;
  }
  int mid = (a + b) / 2;
  add(x, y, a1, r, 2 * u, a, mid);
  add(x, y, a1, r, 2 * u + 1, mid + 1, b);
  propagate(u, a, b);
  if (u < shift) tree[u] = tree[2 * u] + tree[2 * u + 1];
}

ll sum(int x, int y, int u = 1, int a = 0,
       int b = shift - 1) {  //(x,y) - docelowe, (a,b)- akt
  propagate(u, a, b);
  if (u > 2 * shift || y < a || b < x || a > b) return 0LL;
  if (x <= a && b <= y) return tree[u];
  int mid = (a + b) / 2;
  ll L = sum(x, y, 2 * u, a, mid), R = sum(x, y, 2 * u + 1, mid + 1, b);
  return L + R;
}

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n, q;
  std::cin >> n >> q;
  for (int i = 0; i < q; i++) {
    char c;
    std::cin >> c;
    if (c == 'P') {  // postaw maszt
      int x, s, a;
      std::cin >> x >> s >> a;
      int l1 = std::max(1, x - (s / a));
      add(l1 - 1, x - 1, s - a * (x - l1), a);
      int l2 = std::min(n, x + (s / a));
      if (x <= l2 - 1) add(x, l2 - 1, s - a, -a);
      m[x] = {s, a};
    } else if (c == 'Z') {  // zapytaj o średnia
      int l, r;
      std::cin >> l >> r;
      ll segsum = sum(l - 1, r - 1);
      std::cout << segsum / (r - l + 1) << '\n';
    } else {  // usun maszt
      int x;
      std::cin >> x;
      int s = m[x].first, a = m[x].second;
      int l1 = std::max(1, x - (s / a));
      add(l1 - 1, x - 1, -s + a * (x - l1), -a);
      int l2 = std::min(n, x + (s / a));
      if (x <= l2 - 1) add(x, l2 - 1, -s + a, a);
    }
  }
}
