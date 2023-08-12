#include <bits/stdc++.h>
using namespace std;
#define st first
#define nd second
#define pb push_back
#define all(x) x.begin(), x.end()
#define ss(x) ((int)((x).size()))
#define fast                    \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
using lf = long double;
using ll = long long;
using cll = const ll;
using cint = const int;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

int const p = 29, MOD = (int)1e9 + 7, maxN = (int)5e5 + 10;
int n, pwr[maxN], suf[maxN], dvs[maxN];
string s;

void preprocess() {
  pwr[0] = 1;
  for (int i = 1; i <= n; i++) pwr[i] = ((ll)pwr[i - 1] * p) % MOD;

  for (int i = n - 1; i >= 0; i--)
    suf[i] = ((ll)suf[i + 1] * p + (s[i] - 'a' + 1)) % MOD;

  for (int i = 2; i < maxN; i++) {
    if (dvs[i] == 0) {
      dvs[i] = i;
      for (ll j = i; i * j < maxN; j++)
        if (dvs[i * j] == 0) dvs[i * j] = i;
    }
  }
}

int seg(int i, int j) {
  return ((ll)suf[i] - ((ll)suf[j + 1] * pwr[j - i + 1]) % MOD + MOD) % MOD;
}

bool check(int l, int r, int k) { return (seg(l, r - k) == seg(l + k, r)); }

int mincycle(int l, int r) {
  int len = (r - l + 1), mult = 1;
  while (len != mult) {
    int prm = dvs[len / mult], prmpow = 1;
    int tmp = len / mult;
    while (tmp % prm == 0) {
      tmp /= prm;
      prmpow *= prm;
    }
    if (check(l, r, len / prm))
      len /= prm, r = l + len - 1;
    else
      mult *= prmpow;
  }
  return len;
}

int main() {
  fast;
  cin >> n;
  cin >> s;
  preprocess();
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    cout << mincycle(l, r) << '\n';
  }
}
