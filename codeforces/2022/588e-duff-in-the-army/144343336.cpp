#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
namespace debug {
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
char spk(...);
template <class c>
auto spk(c *a) -> decltype(cerr << *a, 0);
struct stream {
  ~stream() { cerr << endl; }
  template <class c>
  typename enable_if<sizeof spk<c>(0) != 1, stream &>::type operator<<(c i) {
    cerr << boolalpha << i;
    return *this;
  }
  template <class c>
  typename enable_if<sizeof spk<c>(0) == 1, stream &>::type operator<<(c i) {
    return *this << range(begin(i), end(i));
  }
  template <class a, class b>
  stream &operator<<(pair<a, b> p) {
    return *this << "(" << p.first << ", " << p.second << ")";
  }
  template <class c>
  stream &operator<<(rge<c> d) {
    *this << "[";
    for (auto it = d.b; it != d.e; it++) *this << ", " + 2 * (it == d.b) << *it;
    return *this << "]";
  }
  stream &_dbg(const string &s, int i, int b) { return *this; }
  template <class c, class... cs>
  stream &_dbg(const string &s, int i, int b, c arg, cs... args) {
    if (i == (int)(s.size())) return (*this << ": " << arg);
    b += (s[i] == '(') + (s[i] == '[') + (s[i] == '{') - (s[i] == ')') -
         (s[i] == ']') - (s[i] == '}');
    return (s[i] == ',' && b == 0)
               ? (*this << ": " << arg << "     ")._dbg(s, i + 1, b, args...)
               : (s[i] == ' ' ? *this : *this << s[i])
                     ._dbg(s, i + 1, b, arg, args...);
  }
};
}  // namespace debug
#define dout debug::stream()
#define dbg(...) ((dout << ">> ")._dbg(#__VA_ARGS__, 0, 0, __VA_ARGS__))
#define st first
#define nd second
#define pb push_back
#define all(x) x.begin(), x.end()
#define ss(x) ((int)((x).size()))
#define upgrade                 \
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

int const LOG = 17, maxN = (int)1e5 + 10, maxK = 10;
pair<int, vector<int> > anc[LOG][maxN];
int n, m, q, pre[maxN], post[maxN], t;
vector<int> G[maxN], ans, val[maxN];

void merge(vector<int> const &a, vector<int> const &b) {
  ans.clear();
  int pta = 0, ptb = 0;
  while (pta < ss(a) && ptb < ss(b) && ss(ans) < maxK) {
    int minab = min(a[pta], b[ptb]);
    if (minab == a[pta])
      ans.pb(a[pta]), pta++;
    else
      ans.pb(b[ptb]), ptb++;
  }
  while (pta < ss(a) && ss(ans) < maxK) ans.pb(a[pta]), pta++;
  while (ptb < ss(b) && ss(ans) < maxK) ans.pb(b[ptb]), ptb++;
}

void dfs(int const &u, int const &prev) {
  anc[0][u].st = prev;
  if (ss(val[u])) anc[0][u].nd = val[u];
  pre[u] = ++t;
  for (auto v : G[u])
    if (v != prev) dfs(v, u);
  post[u] = t;
}

inline bool isanc(int const &u, int const &v) {  // czy u jest przodkiem v
  return (pre[u] <= pre[v] && post[u] >= post[v]);
}

vector<int> minans;

int lcaans(int v, int const &u) {  // przesuwam v
  int l = LOG - 1;
  while (l >= 0) {
    if (!isanc(anc[l][v].st, u)) {
      merge(minans, anc[l][v].nd);
      swap(minans, ans);
      v = anc[l][v].st;
    }
    l--;
  }
  if (isanc(v, u))
    return v;
  else {
    merge(minans, anc[0][v].nd);
    swap(minans, ans);
    return anc[0][v].st;
  }
}

int main() {
  upgrade;
  cin >> n >> m >> q;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    G[u].pb(v);
    G[v].pb(u);
  }
  for (int i = 1; i <= m; i++) {
    int id;
    cin >> id;
    val[id].pb(i);
  }
  for (int i = 1; i <= n; i++) {
    sort(all(val[i]));
    while (ss(val[i]) > maxK) val[i].pop_back();
  }
  dfs(1, 1);
  for (int i = 1; i < LOG; i++) {
    for (int u = 1; u <= n; u++) {
      auto &mid = anc[i - 1][u];
      anc[i][u].st = anc[i - 1][mid.st].st;
      merge(anc[i - 1][u].nd, anc[i - 1][mid.st].nd);
      anc[i][u].nd = ans;
    }
  }

  for (int i = 0; i < q; i++) {
    minans.clear();
    int u, v, a;
    cin >> u >> v >> a;
    int lca = lcaans(u, v);
    lcaans(v, u);
    merge(minans, anc[0][lca].nd);
    swap(minans, ans);
    cout << min(ss(minans), a) << ' ';
    for (int j = 0; j < min(ss(minans), a); j++) cout << minans[j] << " ";
    cout << '\n';
  }
}
