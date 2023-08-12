#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, len, z;
vector<ll> val;
vector<pair<ll, ll> > q;

struct nr {
  ll a, b;
};

void extend(nr &x, nr &y) {
  if (y.b < x.b) {
    y.a *= (x.b) / y.b;
    y.b = x.b;
  } else if (y.b > x.b) {
    x.a *= y.b / x.b;
    x.b = y.b;
  }
}

void reduce(nr &x) {
  ll gcd = __gcd(x.a, x.b);
  x.a /= gcd, x.b /= gcd;
}

bool operator<(nr &x, nr &y) {
  extend(x, y);
  return x.a < y.a;
}

nr operator-(nr &x, nr &y) {
  extend(x, y);
  nr ans;
  ans.a = x.a - y.a;
  ans.b = x.b;
  return ans;
}

nr operator+(nr &x, nr &y) {
  extend(x, y);
  nr ans;
  ans.a = x.a + y.a;
  ans.b = x.b;
  return ans;
}

struct place {
  nr dis, cur;
};

bool cmp(place a, place b) {
  if (b.dis < a.dis) return true;
  if (a.dis.a == b.dis.a && a.cur < b.cur) return true;
  return false;
}

void podz1() {
  int query;
  cin >> query;
  set<place, decltype(cmp) *> s(cmp);
  if (val[n - 1] != len) val.push_back(len);
  for (int i = 0; i < val.size() - 1; i++) {
    int cur = val[i], nextv = val[i + 1];
    place tmp;
    tmp.dis.a = nextv - cur;
    tmp.dis.b = 2;
    tmp.cur.a = 2 * cur + tmp.dis.a;
    tmp.cur.b = 2;
    s.insert(tmp);
  }
  for (int i = 1; i < query; i++) {
    place akt = *(s.begin());
    s.erase(akt);
    // lewa strona
    place l;
    l.dis.a = akt.dis.a;
    l.dis.b = akt.dis.b * 2;
    l.cur = akt.cur - l.dis;
    place r;
    r.dis.a = akt.dis.a;
    r.dis.b = akt.dis.b * 2;
    r.cur = akt.cur + r.dis;
    s.insert(l);
    s.insert(r);
  }
  place ans = *(s.begin());
  reduce(ans.cur);
  cout << ans.cur.a << "/" << ans.cur.b << '\n';
  s.clear();
}

void podz2() {
  for (ll i = 0; i < z; i++) {
    ll tmp;
    cin >> tmp;
    q.push_back({tmp, i});
  }
  ll x = val[0], y = val[1];
  sort(q.begin(), q.end());
  vector<pair<ll, ll> > ans(z);
  ll cnt = 1;
  for (ll i = 0; i < z; i++) {
    if (i > 0) q[i].first -= cnt / 2;
    while (q[i].first > cnt) {
      q[i].first -= cnt;
      cnt *= 2;
    }
    cnt *= 2;
    nr k;
    k.a = ll(x) * (cnt) + y - x + 2 * (y - x) * (q[i].first - 1), k.b = cnt;
    reduce(k);
    ans[q[i].second] = {k.a, k.b};
    cnt /= 2;
  }
  for (ll i = 0; i < z; i++) {
    cout << ans[i].first << "/" << ans[i].second << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  cin >> n >> len >> z;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    val.push_back(tmp);
  }
  if (n == 2)
    podz2();
  else if (z == 1)
    podz1();
  return 0;
}
