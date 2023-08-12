#include <bits/stdc++.h>
using namespace std;
#define st first
#define nd second
#define pb push_back
#define all(x) x.begin(), x.end()
#define ss(x) ((int)((x).size()))
using lf = long double;
using ll = long long;
using cll = const ll;
using cint = const int;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

int const maxN = 88;
ll fib[maxN];

int binsearch(ll k) {
  int l = 0, r = maxN - 1;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (fib[mid] > k)
      r = mid;
    else
      l = mid;
  }
  if (fib[l] > k) return l;
  return r;
}

int fiblen(ll k) {
  int ans = 0, pt = -1;
  while (k > 0) {
    if (pt == -1) pt = binsearch(k);

    while (fib[pt - 1] > k) pt--;
    if (fib[pt - 1] == k) {
      ans++;
      return ans;
    }

    k = min(fib[pt] - k, k - fib[pt - 1]);
    ans++;
  }
  return ans;
}

int main() {
  fast;

  fib[0] = 1;
  fib[1] = 1;
  for (int i = 2; i < maxN; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }

  int p;
  cin >> p;
  while (p--) {
    ll k;
    cin >> k;
    cout << fiblen(k) << '\n';
  }
}
