#include <bits/stdc++.h>
using namespace std;
using lf = long double;
using ll = long long;
using cll = const ll;
using cint = const int;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

int const maxN = 2020, maxM = 1e5 + 20;
pair<pii, int> circ[maxN];
vector<pair<pii, int> > per;
int n, m, w, h, sz[maxN], rep[maxN], out[maxM];

double dist(int i, int j) {
  ll x1 = circ[i].st.st, y1 = circ[i].st.nd;
  ll x2 = circ[j].st.st, y2 = circ[j].st.nd;
  ll dx = x1 - x2, dy = y1 - y2;
  return sqrt(dx * dx + dy * dy);
}

bool cmp(pair<pii, int> &p1, pair<pii, int> &p2) { return p1.st.st < p2.st.st; }

int Find(int u) {
  if (rep[u] == u) return u;
  return rep[u] = Find(rep[u]);
}

void Union(int u, int v) {
  u = Find(u), v = Find(v);
  if (sz[u] == sz[v]) {
    rep[u] = rep[v];
    sz[v]++;
  } else {
    if (sz[u] > sz[v]) swap(u, v);
    rep[u] = rep[v];
  }
}

int main() {
  fast for (int i = 1; i < maxN; i++) rep[i] = i, sz[i] = 1;

  cin >> n >> m;
  cin >> w >> h;
  for (int i = 0; i < n; i++)
    cin >> circ[i].st.st >> circ[i].st.nd >> circ[i].nd;
  per.resize(m);
  for (int i = 0; i < m; i++)
    cin >> per[i].st.st >> per[i].st.nd, per[i].nd = i;

  vector<pair<double, pii> > s;
  for (int i = 0; i < n; i++) {
    int x = circ[i].st.st, y = circ[i].st.nd, cr = i + 5, r = circ[i].nd;
    int d1 = x - r, d2 = y - r, d3 = w - x - r, d4 = h - y - r;
    s.pb({d1, {1, cr}});
    s.pb({d2, {2, cr}});
    s.pb({d3, {3, cr}});
    s.pb({d4, {4, cr}});
    // dbg(i, d1, d2, d3, d4);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      double d = dist(i, j) - circ[i].nd - circ[j].nd;
      s.pb({d, {i + 5, j + 5}});
    }
  }
  // dbg(s);
  sort(all(s));
  sort(all(per), cmp);
  // dbg(per);
  int pt = 0;
  for (int i = 0; i < m; i++) {
    ll d = 2 * per[i].st.st;
    // dbg(i);
    while (pt < ss(s) && (s[pt]).st < d) {
      auto top = s[pt];
      pt++;
      int u = top.nd.st, v = top.nd.nd;
      if (Find(u) != Find(v)) Union(u, v);
    }

    int f1 = Find(1), f2 = Find(2), f3 = Find(3), f4 = Find(4);
    bool c12 = (f1 == f2);
    bool c13 = (f1 == f3);
    bool c14 = (f1 == f4);
    bool c23 = (f2 == f3);
    bool c24 = (f2 == f4);
    bool c34 = (f3 == f4);

    int cor = per[i].st.nd;
    vector<int> ans = {cor};
    // dbg(ans);
    if (cor == 1 && !c12) {
      if (!c23 && !c24) ans.pb(2);
      if (!c13 && !c34 && !c24) ans.pb(3);
      if (!c14 && !c13) ans.pb(4);
    }
    if (cor == 2 && !c23) {
      if (!c13 && !c24 && !c14) ans.pb(4);
      if (!c12 && !c24) ans.pb(1);
      if (!c13 && !c34) ans.pb(3);
    }
    if (cor == 3 && !c34) {
      if (!c23 && !c13) ans.pb(2);
      if (!c14 && !c24) ans.pb(4);
      if (!c13 && !c12 && !c24) ans.pb(1);
    }
    if (cor == 4 && !c14) {
      if (!c12 && !c13) ans.pb(1);
      if (!c13 && !c24 && !c23) ans.pb(2);
      if (!c24 && !c34) ans.pb(3);
    }

    sort(all(ans));
    reverse(all(ans));
    int pow = 1, sum = 0;
    for (auto x : ans) {
      sum += x * pow;
      pow *= 10;
    }
    out[per[i].nd] = sum;
  }
  for (int i = 0; i < m; i++) cout << out[i] << "\n";
}
