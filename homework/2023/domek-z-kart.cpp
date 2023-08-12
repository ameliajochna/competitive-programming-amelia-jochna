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
#define lowb(v, x) (lower_bound(all(v), (x)) - v.begin())
#define uppb(v, x) (upper_bound(all(v), (x)) - v.begin())
#define erase_duplicates(x)               \
  {                                       \
    sort(all(x));                         \
    x.resize(unique(all(x)) - x.begin()); \
  }
template <class p, class q>
pair<p, q> operator-(pair<p, q> a, pair<p, q> b) {
  return mp(a.f - b.f, a.s - b.s);
}
template <class p, class q>
pair<p, q> operator+(pair<p, q> a, pair<p, q> b) {
  return mp(a.f + b.f, a.s + b.s);
}
template <class p, class q>
void umin(p &a, const q &b) {
  if (a > b) a = b;
}
template <class p, class q>
void umax(p &a, const q &b) {
  if (a < b) a = b;
}
using lf = long double;
using ll = long long;
using cll = const ll;
using cint = const int;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

int const maxN = (int)(1 << 17) + 10, maxK = 24;
int n, k, m;
ll dp[maxN][maxK];  // ile maksymalnie moge zarobic w podrzewach jezeli wezme
                    // ten wierzcholek i K z jego dzieci
ll val[maxN];

void calc(int x) {
  dp[x][0] = 0;
  for (int i = 0; i < maxK; i++)
    for (int j = 0; i + j < maxK; j++) {
      if (2 * x + 1 < maxN && dp[2 * x][i] != -1e18 &&
          dp[2 * x + 1][j] != -1e18) {
        ll l = dp[2 * x][i], r = dp[2 * x + 1][j];
        dp[x][i + j] = max(dp[x][i + j], l + r);
      }
    }

  for (int i = maxK - 1; i >= 1; i--) {
    if (dp[x][i - 1] == -1e18) continue;
    dp[x][i] = dp[x][i - 1] + val[x];
  }
}

int main() {
  fast;
  cin >> n >> k;
  k /= 2;
  m = (1 << n);
  for (int i = 1; i < m; i++) {
    int l, r;
    cin >> l >> r;
    val[i] = l + r;
  }
  for (int i = (1 << n) - 1; i > 0; i--) {
    for (int j = 0; j < maxK; j++) dp[i][j] = -1e18;
  }
  for (int i = (1 << n) - 1; i > 0; i--) {
    for (int j = 0; j < maxK; j++) dp[i][j] = -1e18;
    calc(i);
  }

  ll maxans = 0;
  for (int i = 0; i <= k; i++) maxans = max((ll)maxans, dp[1][i]);

  cout << maxans << '\n';
}
