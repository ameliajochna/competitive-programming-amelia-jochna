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

int const maxN = (int)2e5 + 10;
vector<int> revG[maxN], G[maxN];
bool vis[maxN], winy[maxN], onpth[maxN];
int abv[maxN], pth[maxN], n;

void dfswin(int u, int prev) {
  pth[u] = prev;
  winy[u] = true;
  for (auto x : revG[u])
    if (!winy[x]) dfswin(x, u), abv[u] += abv[x] + 1;
}

void dfs(int u) {
  vis[u] = true;
  for (auto v : G[u])
    if (!vis[v]) dfs(v);
}

void rmv() {
  for (int i = 0; i <= n; i++)
    vis[i] = 0, revG[i].clear(), G[i].clear(), winy[i] = 0, onpth[i] = 0,
    abv[i] = 0, pth[i] = 0;
}

void solve() {
  cin >> n;
  vector<int> v(n + 1);
  for (int i = 1; i <= n; i++) cin >> v[i];
  for (int i = 1; i <= n; i++) {
    int u = i, ver = i + v[i];
    if (u == ver) continue;
    if (ver < 1 || n < ver) ver = 0;
    revG[ver].pb(u);
    G[u].pb(ver);
  }

  dfswin(0, 0);
  int wig = 0;
  for (int i = 1; i <= n; i++)
    if (winy[i]) wig++;

  dfs(1);
  int ans = 0;
  if (!winy[1]) {
    for (int i = 1; i <= n; i++) {
      // dbg(i, vis[i]);
      if (vis[i]) ans += n + 1 + wig;
    }
  } else {
    int u = 1;
    onpth[u] = true;
    while (u != pth[u]) {
      // dbg(u);
      onpth[u] = true;
      u = pth[u];
    }

    for (int i = 1; i <= n; i++) {
      int cnt = 0;
      if (onpth[i])
        cnt = n + 1 + wig - winy[i] - abv[i];
      else if (winy[1])
        cnt = 2 * n + 1;
      ans += cnt;
    }
  }
  rmv();
  cout << ans << '\n';
}

int32_t main() {
  int t;
  cin >> t;
  while (t--) solve();
  fast;
}
