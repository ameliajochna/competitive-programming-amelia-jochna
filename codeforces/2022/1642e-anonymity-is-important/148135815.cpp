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

int const shift = (1 << 18);
int n, q, Qtree[2 * shift + 10];
set<int> potill;

void addQ(int lq, int rq) {
  lq += shift - 1;
  Qtree[lq] = min(Qtree[lq], rq);
  lq /= 2;
  while (lq) {
    Qtree[lq] = min(Qtree[2 * lq], Qtree[2 * lq + 1]);
    lq /= 2;
  }
}

int seglb(int l, int r) {
  l += shift - 1, r += shift - 1;
  int ans = min(Qtree[l], Qtree[r]);
  while (l / 2 != r / 2) {
    if (l % 2 == 0) ans = min(ans, Qtree[l + 1]);
    if (r % 2 == 1) ans = min(ans, Qtree[r - 1]);
    l /= 2, r /= 2;
  }
  return ans;
}

int main() {
  fast;

  for (int i = 0; i <= 2 * shift; i++) Qtree[i] = __INT_MAX__;

  cin >> n >> q;
  for (int i = 0; i <= n + 1; i++) potill.insert(i);

  while (q--) {
    int t;
    cin >> t;
    if (t == 0) {
      int l, r, x;
      cin >> l >> r >> x;
      if (x == 0) {
        auto tmp = potill.lower_bound(l);
        while (tmp != potill.end() && *tmp <= r) {
          potill.erase(tmp);
          tmp = potill.lower_bound(l);
        }
      } else if (x == 1)  // dziala
        addQ(l, r);

    } else {
      int j;
      cin >> j;
      if (!potill.count(j))
        cout << "NO\n";
      else {
        auto l = *(--potill.lower_bound(j));
        auto r = *(++potill.lower_bound(j));
        int ans = seglb(l + 1, j);
        if (ans < r)
          cout << "YES\n";
        else
          cout << "N/A\n";
      }
    }
  }
}
/*

   5 4
   0 4 4 0
   0 1 5 1
   0 1 3 0
   1 5
 */
