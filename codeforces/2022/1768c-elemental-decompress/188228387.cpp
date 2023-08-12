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

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  vector<int> p1(n), p2(n);
  vector<int> used(n + 1);
  set<int> lftp1, lftp2;
  for (int i = 1; i <= n; i++) lftp1.insert(i), lftp2.insert(i);
  for (int i = 0; i < n; i++) {
    if (used[v[i]] > 1) {
      cout << "NO\n";
      return;
    } else if (used[v[i]])
      p2[i] = v[i], lftp2.erase(v[i]);
    else {
      p1[i] = v[i];
      lftp1.erase(v[i]);
    }
    used[v[i]]++;
  }
  for (int i = 0; i < n; i++) {  // naprawiamy p1
    if (p1[i] != 0) continue;
    auto pt = lftp1.upper_bound(v[i]);
    if (pt == lftp1.begin()) {
      cout << "NO\n";
      return;
    }
    pt--;
    p1[i] = *pt;
    lftp1.erase(pt);
  }
  for (int i = 0; i < n; i++) {
    if (p2[i] != 0) continue;
    auto pt = lftp2.upper_bound(v[i]);
    if (pt == lftp2.begin()) {
      cout << "NO\n";
      return;
    }
    pt--;
    p2[i] = *pt;
    lftp2.erase(pt);
  }

  for (int i = 0; i < n; i++) {
    if (max(p1[i], p2[i]) != v[i]) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
  for (int i = 0; i < n; i++) cout << p1[i] << " ";
  cout << '\n';
  for (int i = 0; i < n; i++) cout << p2[i] << " ";
  cout << '\n';
}

int main() {
  fast int t;
  cin >> t;
  while (t--) solve();
}
