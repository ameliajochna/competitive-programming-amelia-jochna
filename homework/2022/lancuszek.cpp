#include <bits/stdc++.h>
using namespace std;
using lf = long double;
using ll = long long;
using cll = const ll;
using cint = const int;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

int const maxLOG = 18;
int n, m;
string s;
unordered_map<ll, int> sdq[maxLOG];

int conv(deque<int> &dq) {
  ll ans = 0;
  for (ll i = 0; i < dq.size(); i++) ans += (dq[i] * (1LL << i));
  return ans;
}

void build(int k) {
  deque<int> cur;
  for (int i = 0; i < k; i++) {
    cur.pb(s[i] - '0');
  }
  sdq[k][conv(cur)]++;
  for (int i = k; i < n; i++) {
    cur.pop_front();
    cur.push_back(s[i] - '0');
    sdq[k][conv(cur)]++;
  }
}

void add(int k, int val) {
  // dodaj wszystkie ktore zawieraja pozycje k
  for (int i = 1; i < maxLOG; i++) {
    deque<int> dq;
    bool start = true;
    for (int j = max(k - i + 1, 0); j <= k && j + i - 1 < n; j++) {
      int l = j, r = j + i - 1;
      if (r - l + 1 != i) continue;
      if (start) {
        for (int q = l; q <= r; q++) dq.push_back(s[q] - '0');
        start = false;
      } else {
        dq.pop_front();
        dq.push_back(s[r] - '0');
      }
      ll ky = conv(dq);
      sdq[i][ky] += val;
      if (sdq[i][ky] == 0) sdq[i].erase(ky);
    }
  }
}

int missing() {
  for (int i = 1; i < maxLOG; i++) {
    if (sdq[i].size() != (1 << i)) return i;
  }
}

int32_t main() {
  fast;
  cin >> n >> m;
  cin >> s;

  for (int i = 1; i < maxLOG; i++) build(i);

  cout << missing() << '\n';
  for (int i = 0; i < m; i++) {
    int j;
    cin >> j;
    j--;
    add(j, -1);
    if (s[j] == '0')
      s[j] = '1';
    else
      s[j] = '0';
    add(j, 1);
    cout << missing() << '\n';
  }
}
