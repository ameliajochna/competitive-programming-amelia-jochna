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

int opt(int sum) {  // dla danej sumy ile trzeba doplacic zeby miec ladnego loga
  if (sum == 0) return 1;
  int log = 31 - __builtin_clz(sum);
  // dbg(log);
  if ((1 << log) == sum) return 0;
  return ((1 << (log + 1)) - sum);
}

void solve() {
  int n;
  cin >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    w[--tmp]++;
  }

  int sum = 0;
  for (auto x : w) sum += x;
  // dbg(w);
  vector<int> logsum(
      32);  // logsum[i] : maksymalna suma s na prefiksie taka ze s<=2^i

  int cursum = 0, curlog = 0, minans = 1e9;
  for (int pt = 0; pt < n; pt++) {
    cursum += w[pt];
    while ((1 << curlog) < cursum) curlog++;
    logsum[curlog] = cursum;
    // dbg(curlog, cursum, logsum);

    for (int l = 0; l < 32; l++) {
      // 2^l to dlugosc przedzialu a
      int a = opt(logsum[l]), b = opt(cursum - logsum[l]),
          c = opt(sum - cursum);
      // dbg(l, logsum[l], cursum-logsum[l], sum-cursum, a, b, c);
      minans = min(minans, a + b + c);
    }
  }
  cout << minans << '\n';
}

int main() {
  fast;
  int t;
  // t=1;
  cin >> t;
  while (t--) solve();
}

/*

   1
   3
   4 7 8
   3 3 6


 */
