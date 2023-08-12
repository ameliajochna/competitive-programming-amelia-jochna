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
  int n, s;
  cin >> n >> s;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];

  vector<vector<pii> > pos(n);
  vector<vector<int> > dp(n);

  for (int i = 1; i < n - 1; i++) {
    pii p1 = {0, v[i]};
    if ((p1.st - s) * (p1.nd - s) >= 0) {
      pos[i].pb(p1);
      swap(p1.st, p1.nd);
      pos[i].pb(p1);
    }
    p1 = {(v[i] + 1) / 2, v[i] / 2};
    if ((p1.st - s) * (p1.nd - s) >= 0) {
      pos[i].pb(p1);
      swap(p1.st, p1.nd);
      pos[i].pb(p1);
    }
    if (s < v[i]) {
      p1 = {s, v[i] - s};
      if ((p1.st - s) * (p1.nd - s) >= 0) {
        pos[i].pb(p1);
        swap(p1.st, p1.nd);
        pos[i].pb(p1);
      }
    }
    erase_duplicates(pos[i]);
    // dbg(i, pos[i]);
  }
  pos[0].pb({0, v[0]});
  dp[0].pb(0);

  pos[n - 1].pb({v[n - 1], 0});

  for (int i = 1; i < n; i++) {
    dp[i].resize(pos[i].size());
    for (int j = 0; j < pos[i].size(); j++) {
      int mindp = 1e18;
      for (int k = 0; k < pos[i - 1].size(); k++)
        mindp = min(mindp, dp[i - 1][k] + pos[i - 1][k].nd * pos[i][j].st);
      dp[i][j] = mindp;
      // dbg(i, j, pos[j], mindp);
    }
  }
  cout << dp[n - 1][0] << '\n';
}

int32_t main() {
  int t;
  cin >> t;
  while (t--) solve();
  fast;
}
