#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
using namespace std;
typedef long long ll;

int binsearch(ll val, vector<ll>& v) {
  int l = 0, r = v.size();
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (v[mid] > val)
      r = mid;
    else
      l = mid;
  }
  if (v[l] == val)
    return l;
  else if (v[r] == val)
    return r;
  else
    return l;
}

void solution() {
  int n;
  cin >> n;
  vector<ll> v(n);
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    sum += v[i];
  }

  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    ll x, y;
    cin >> x >> y;
    ll newy = sum - y;
    ll av = (x + newy) / 2;
    int ind = binsearch(av, v);
    vector<ll> pos = {v[ind]};
    if (ind + 1 < v.size()) pos.push_back(v[ind + 1]);
    ll mincost = LONG_LONG_MAX;
    for (auto k : pos) {
      ll curcost = 0;
      if (k < x) curcost += x - k;
      if (sum - k < y) curcost += (y - (sum - k));
      mincost = min(mincost, curcost);
    }
    cout << mincost << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  while (t--) solution();
}

/*

   100
   16 67 85 30 6 43 12 83 100 81 98 35 13 6 23 31 15 89 29 24 50 94 16 64 75 84
   32 46 38 84 31 18 88 52 24 18 21 93 17 67 44 74 50 52 34 62 99 38 63 58 98 51
   1 33 67 23 27 62 34 34 7 17 57 88 60 6 67 47 64 17 14 37 3 72 89 7 75 69 79
   75 70 33 26 15 100 81 5 19 6 21 59 95 3 52 82 71 59 42 13 22
   2
   30 1235
   40 9773
 */
