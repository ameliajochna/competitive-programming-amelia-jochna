#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
using namespace std;
typedef long long ll;

int costofchange(ll a, ll ex) {
  string res, cur;
  while (a) {
    cur.push_back((a % 10 + '0'));
    a /= 10;
  }
  while (ex) {
    res.push_back((ex % 10 + '0'));
    ex /= 10;
  }
  reverse(cur.begin(), cur.end());
  reverse(res.begin(), res.end());
  // cout<<cur<<" "<<res<<'\n';
  int p1 = 0, p2 = 0, cnt = 0;
  while (p1 != cur.size()) {
    if (cur[p1] == res[p2])
      p1++, p2++;
    else {
      cnt++;
      p1++;
    }
  }
  cnt += res.size() - p2;
  return cnt;
}

void solution() {
  ll n;
  cin >> n;
  ll prev = 1;
  int ans = costofchange(n, prev);
  for (int i = 1; i < 64; i++) {
    prev *= 2;
    ans = min(ans, costofchange(n, prev));
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) solution();
}
