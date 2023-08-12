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

int const maxN = (int)2e5 + 10;
vector<int> G[maxN];
int dp[2][maxN], grp[maxN], n,
    cost[2][maxN];  // ile zapalonych w poddrzewie jesli dp[1][u] - u zapalony
                    // dp[0][u] - u zgaszony

void dfs(int u, int prev) {
  for (auto v : G[u]) {
    if (v != prev) {
      dfs(v, u);
      dp[1][u] += dp[0][v];
      cost[1][u] += cost[0][v];

      if (dp[1][v] > dp[0][v])
        dp[0][u] += dp[1][v], cost[0][u] += cost[1][v];
      else if (dp[1][v] < dp[0][v])
        dp[0][u] += dp[0][v], cost[0][u] += cost[0][v];
      else if (dp[1][v] == dp[0][v])
        dp[0][u] += dp[0][v], cost[0][u] += min(cost[0][v], cost[1][v]);
    }
  }
  dp[1][u]++;
  cost[1][u] += (ss(G[u]));
  cost[0][u]++;
}

void setval(int u, int prev, int cur) {
  // dbg(u, cur);
  grp[u] = cur;
  for (auto v : G[u])
    if (v != prev) {
      if (cur == 1)
        setval(v, u, 0);
      else {
        if (dp[1][v] > dp[0][v])
          setval(v, u, 1);
        else if (dp[1][v] < dp[0][v])
          setval(v, u, 0);
        else if (dp[1][v] == dp[0][v]) {
          if (cost[1][v] < cost[0][v])
            setval(v, u, 1);
          else
            setval(v, u, 0);
        }
      }
    }
}

int main() {
  fast;
  cin >> n;

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    G[u].pb(v);
    G[v].pb(u);
  }

  dfs(1, 1);

  // for(int i=1; i<=n; i++)
  //     dbg(i, dp[0][i], dp[1][i], cost[0][i], cost[1][i]);

  if (dp[1][1] == dp[0][1]) {
    if (cost[1][1] < cost[0][1])
      setval(1, 1, 1);
    else
      setval(1, 1, 0);
  } else if (dp[1][1] > dp[0][1])
    setval(1, 1, 1);
  else
    setval(1, 1, 0);

  for (int i = 1; i <= n; i++) {
    if (grp[i] == 0)
      grp[i] = 1;
    else
      grp[i] = ss(G[i]);
  }

  ll sum = 0, cnt = 0;
  for (int i = 1; i <= n; i++) sum += grp[i];

  for (int i = 1; i <= n; i++) {
    ll s1 = 0;
    for (auto v : G[i]) s1 += grp[v];
    if (grp[i] == s1) cnt++;
  }
  cout << cnt << " " << sum << '\n';
  for (int i = 1; i <= n; i++) cout << grp[i] << " ";
}

/*

 */
