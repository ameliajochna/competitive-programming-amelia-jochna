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
  return make_pair(a.st + b.st, a.nd + b.nd);
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

int const maxN = (int)2e5 + 10;

map<pii, int> pt;
pii a[maxN], ans[maxN];
queue<int> q;
vector<pii> nb = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool vis[maxN];

int main() {
  fast;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    pt[{x, y}] = i;
    a[i] = {x, y};
  }

  for (int i = 0; i < n; i++) {
    for (auto x : nb) {
      pii nxt = {x.st + a[i].st, x.nd + a[i].nd};
      if (!pt.count(nxt)) {
        q.push(i);
        ans[i] = nxt;
        vis[i] = true;
        break;
      }
    }
  }

  while (!q.empty()) {
    int i = q.front();
    q.pop();
    pii cur = a[i];
    // dbg(cur.st, cur.nd);
    for (auto x : nb) {
      pii nxt = {x.st + cur.st, x.nd + cur.nd};
      if (pt.count(nxt) && !vis[pt[nxt]]) {
        int ind = pt[nxt];
        q.push(ind);
        ans[ind] = ans[i];
        vis[ind] = true;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i].st << " " << ans[i].nd << '\n';
  }
}
/*

   13
   2 3
   3 2
   3 3
   3 4
   4 1
   4 2
   4 3
   4 4
   4 5
   5 2
   5 3
   5 4
   6 3

 */
