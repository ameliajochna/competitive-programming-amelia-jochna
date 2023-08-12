#include <bits/stdc++.h>
using namespace std;
using lf = long double;
using ll = long long;
using cll = const ll;
using cint = const int;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
#define int long long

int const maxN = (int)3e5 + 10, MOD = 1e9 + 7;
int n, a[maxN], q;

struct matrix {
  ll a, b, c, d;
  matrix(ll a = 0, ll b = 0, ll c = 0, ll d = 0) : a(a), b(b), c(c), d(d) {}
};

matrix const operator*(matrix m1,
                       matrix m2) {  // m2 to ta z prawej (wczesniejsza)
  ll a1 = (m1.a * m2.a % MOD + m1.b * m2.c % MOD + MOD) % MOD;
  ll b1 = (m1.a * m2.b % MOD + m1.b * m2.d % MOD + MOD) % MOD;
  ll c1 = (m2.a * m1.c % MOD + m2.c * m1.d % MOD + MOD) % MOD;
  ll d1 = (m1.c * m2.b % MOD + m1.d * m2.d % MOD + MOD) % MOD;
  matrix ans(a1, b1, c1, d1);
  return ans;
}

matrix suf[maxN], revsuf[maxN];

void preprocess() {
  suf[n - 1] = matrix(a[n - 1], 1, 1, 0);
  revsuf[n - 1] = matrix(0, 1, 1, -a[n - 1]);
  for (int i = n - 2; i >= 0; i--) {
    matrix cur(a[i], 1, 1, 0);
    matrix rev(0, 1, 1, -a[i]);
    suf[i] = cur * suf[i + 1];
    revsuf[i] = revsuf[i + 1] * rev;
    // dbg(i, suf[i].a, suf[i].b, suf[i].c, suf[i].d);
    // dbg(i, revsuf[i].a, revsuf[i].b, revsuf[i].c, revsuf[i].d);
  }
}

int32_t main() {
  fast;
  cin >> n >> q;
  for (int i = 0; i < n; i++) cin >> a[i];
  preprocess();
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    if (r == n - 1) {
      cout << suf[l].a << " " << suf[l].c << '\n';
      continue;
    }

    matrix m1 = suf[l], m2 = revsuf[r + 1];
    matrix ans = m1 * m2;
    cout << ans.a << " " << ans.c << '\n';
  }
}
