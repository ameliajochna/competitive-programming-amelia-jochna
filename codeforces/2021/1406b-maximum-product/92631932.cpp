#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solution() {
  ll n;
  cin >> n;
  vector<ll> neg, pos;
  ll zerocnt = 0;
  for (ll i = 0; i < n; i++) {
    ll a;
    cin >> a;
    if (a < 0)
      neg.push_back(a);
    else if (a > 0)
      pos.push_back(a);
    else
      zerocnt++;
  }
  sort(neg.begin(), neg.end());
  sort(pos.begin(), pos.end());
  reverse(pos.begin(), pos.end());
  ll maxans = -LONG_LONG_MAX;
  for (ll i = 0; i <= 5; i++) {
    ll negcnt = i, poscnt = 5 - i, curans = 1;
    for (ll j = 0; j < neg.size() && negcnt > 0; j++, negcnt--) {
      curans *= neg[j];
    }
    for (ll j = 0; j < pos.size() && poscnt > 0; j++, poscnt--) {
      curans *= pos[j];
    }
    if (poscnt == 0 && negcnt == 0) {
      if (curans < 0 && zerocnt > 0) curans = 0;
      maxans = max(curans, maxans);
    }
  }
  if (maxans < 0) {
    reverse(neg.begin(), neg.end());
    reverse(pos.begin(), pos.end());
    for (ll i = 0; i <= 5; i++) {
      ll negcnt = i, poscnt = 5 - i, curans = 1;
      for (ll j = 0; j < neg.size() && negcnt > 0; j++, negcnt--) {
        curans *= neg[j];
      }
      for (ll j = 0; j < pos.size() && poscnt > 0; j++, poscnt--) {
        curans *= pos[j];
      }
      if (poscnt == 0 && negcnt == 0) {
        if (curans < 0 && zerocnt > 0) curans = 0;
        maxans = max(curans, maxans);
      }
    }
  }
  if (maxans == -LONG_LONG_MAX) maxans = 0;
  cout << maxans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) solution();
}
