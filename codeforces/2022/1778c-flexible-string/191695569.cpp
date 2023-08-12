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
#define all(x) x.begin(), x.end()
#define erase_duplicates(x)               \
  {                                       \
    sort(all(x));                         \
    x.resize(unique(all(x)) - x.begin()); \
  }
#define fast                    \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
#define int long long
#define pb push_back
#define nd second
#define st first
#define pii pair<int, int>

void solve() {
  int n, k;
  cin >> n >> k;
  string a, b;
  cin >> a >> b;
  string diff = a;
  erase_duplicates(diff);
  int mxans = 0;
  int cnt = diff.size();
  // dbg(diff);
  for (int i = 0; i < (1 << cnt); i++) {
    if (__builtin_popcount(i) > k) continue;
    // sprawdz odpa
    // dbg(i);

    vector<bool> ok(27);
    for (int j = 0; j < cnt; j++)
      if ((i >> j) & 1) ok[diff[j] - 'a'] = true;

    int l = -1, ans = 0;
    for (int j = 0; j < n; j++) {
      int e1 = a[j], e2 = b[j];
      if (ok[e1 - 'a']) e1 = e2;
      // dbg(l, j, a1[j], b[j]);
      if (l == -1 && e1 == e2)
        l = j;
      else if (l != -1 && e1 != e2) {
        int len = j - l;
        ans += ((len * (len + 1)) / 2);
        l = -1;
      }
    }
    if (l != -1) {
      int len = n - l;
      ans += ((len * (len + 1)) / 2);
    }
    // dbg(ans);
    mxans = max(mxans, ans);
  }
  cout << mxans << '\n';
}

int32_t main() {
  int t;
  cin >> t;
  while (t--) solve();
  fast;
}
