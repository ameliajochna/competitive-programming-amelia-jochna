#include <bits/stdc++.h>
#define nd second
#define st first
#define pll pair<ll, ll>
using namespace std;
typedef long long ll;
typedef long double ld;
ld exval, v, eps = (1e-15);

void allposs(ld a, ld b, ld c, ld curexval) {
  exval += curexval;
  if (a >= eps) {
    int cnt = (b > eps) + (c > eps);
    if (a <= v + eps) {
      ld addb = (b >= eps ? a / ld(cnt) : 0.0);
      ld addc = (c >= eps ? a / ld(cnt) : 0.0);
      allposs(0.0, b + addb, c + addc, curexval * a);
    } else {
      ld addb = (b >= eps ? v / ld(cnt) : 0.0);
      ld addc = (c >= eps ? v / ld(cnt) : 0.0);
      allposs(a - v, b + addb, c + addc, curexval * a);
    }
  }
  if (b >= eps) {
    int cnt = (a > eps) + (c > eps);
    if (b <= v + eps) {
      ld adda = (a >= eps ? b / ld(cnt) : 0.0);
      ld addc = (c >= eps ? b / ld(cnt) : 0.0);
      allposs(a + adda, 0.0, c + addc, curexval * b);
    } else {
      ld adda = (a >= eps ? v / ld(cnt) : 0.0);
      ld addc = (c >= eps ? v / ld(cnt) : 0.0);
      allposs(a + adda, b - v, c + addc, curexval * b);
    }
  }
  if (c >= eps) {
    exval += (curexval * c);
  }
}

void solution() {
  ld c, m, p;
  cin >> c >> m >> p >> v;
  exval = 0;
  allposs(c, m, p, 1.0);
  cout << fixed << setprecision(12) << (exval - 1.0) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();
}
/*
   1
   0.4 0.2 0.4 0.8


 */
