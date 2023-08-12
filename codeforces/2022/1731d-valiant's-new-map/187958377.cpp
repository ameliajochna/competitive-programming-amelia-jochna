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
auto spk(c* a) -> decltype(cerr << *a, 0);
struct stream {
  ~stream() { cerr << endl; }
  template <class c>
  typename enable_if<sizeof spk<c>(0) != 1, stream&>::type operator<<(c i) {
    cerr << boolalpha << i;
    return *this;
  }
  template <class c>
  typename enable_if<sizeof spk<c>(0) == 1, stream&>::type operator<<(c i) {
    return *this << range(begin(i), end(i));
  }
  template <class a, class b>
  stream& operator<<(pair<a, b> p) {
    return *this << "(" << p.first << ", " << p.second << ")";
  }
  template <class c>
  stream& operator<<(rge<c> d) {
    *this << "[";
    for (auto it = d.b; it != d.e; it++) *this << ", " + 2 * (it == d.b) << *it;
    return *this << "]";
  }
  stream& _dbg(const string& s, int i, int b) { return *this; }
  template <class c, class... cs>
  stream& _dbg(const string& s, int i, int b, c arg, cs... args) {
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
void umin(p& a, const q& b) {
  if (a > b) a = b;
}
template <class p, class q>
void umax(p& a, const q& b) {
  if (a < b) a = b;
}
using lf = long double;
using ll = long long;
using cll = const ll;
using cint = const int;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

int n, m;

bool check(vector<vector<int> > const& v, int l) {
  vector<vector<int> > lft(n), up(n), sqr(n);
  // cout<<"SPRAWDZ: "<<l<<'\n';
  for (int i = 0; i < n; i++) {
    lft[i].resize(m), up[i].resize(m);
    for (int j = 0; j < m; j++) {
      if (v[i][j] < l)
        lft[i][j] = 0, up[i][j] = 0;
      else {
        lft[i][j] = (i == 0 ? 1 : lft[i - 1][j] + 1);
        up[i][j] = (j == 0 ? 1 : up[i][j - 1] + 1);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    sqr[i].resize(m);
    for (int j = 0; j < m; j++) {
      if (up[i][j] == 0) continue;

      if (i == 0 || j == 0)
        sqr[i][j] = 1;
      else if (min(up[i][j], lft[i][j]) > sqr[i - 1][j - 1])
        sqr[i][j] = sqr[i - 1][j - 1] + 1;
      else
        sqr[i][j] = min(up[i][j], lft[i][j]);
      // dbg(i, j, sqr[i][j], lft[i][j], up[i][j]);
      if (sqr[i][j] >= l) return true;
    }
  }

  return false;
}

int binsearch(vector<vector<int> > const& v) {
  int l = 1, r = min(n, m);
  while (r - l > 1) {
    int mid = (l + r) / 2;
    // dbg(l, r, mid);
    if (check(v, mid))
      l = mid;
    else
      r = mid;
  }
  // dbg(l, r);
  if (check(v, r))
    return r;
  else
    return l;
}

void solve() {
  cin >> n >> m;
  vector<vector<int> > v(n);

  for (int i = 0; i < n; i++) {
    v[i].resize(m);
    for (int j = 0; j < m; j++) cin >> v[i][j];
  }
  cout << binsearch(v) << '\n';
}

int main() {
  fast int t;
  cin >> t;
  while (t--) solve();
}
