#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
#define sz(a) a.size()
#define pb push_back
using namespace std;
typedef long long ll;

void solve() {
  ll n;
  cin >> n;
  map<pii, ll> paircnt;
  map<ll, ll> stcnt, ndcnt;
  ll ans = (n * (n - 1) * (n - 2)) / 6;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    paircnt[{a, b}]++;
    stcnt[a]++;
    ndcnt[b]++;
  }
  for (auto x : paircnt) {
    pii cur = x.st;
    ll curcnt = x.nd;
    ll comb = curcnt * (ndcnt[cur.nd] - curcnt) * (stcnt[cur.st] - curcnt);
    ans -= comb;
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solve();
}
