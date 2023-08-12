#include <bits/stdc++.h>
using namespace std;
using lf = long double;
using ll = long long;
using cll = const ll;
using cint = const int;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

int const maxN = (int)1e5 + 10, maxS = (int)2e6 + 10;
int n, lst = 1, cnt;
vector<string> s;
int rep[maxS], sz[maxS], trie[maxS][26];
vector<int> pos[maxS];

int Find(int u) {
  if (u == rep[u]) return u;
  return rep[u] = Find(rep[u]);
}

void Union(int a, int b) {
  a = Find(a), b = Find(b);
  if (a == b) return;
  cnt--;
  if (sz[a] < sz[b])
    rep[a] = b;
  else if (sz[a] > sz[b])
    rep[b] = a;
  else {
    rep[b] = a;
    sz[a]++;
  }
}

void add(int k) {
  int cur = 0;
  for (int i = 0; i < s[k].size(); i++) {
    int j = s[k][i] - 'a';
    if (trie[cur][j] == 0) trie[cur][j] = lst++;
    // dbg(k, s[k][i], trie[{cur,j}]);
    cur = trie[cur][j];
    pos[cur].pb(k);
  }
}

void check(int k) {
  int cur = 0;
  cnt++;
  for (int i = 0; i < s[k].size(); i++) {
    int j = s[k][i] - 'a';
    cur = trie[cur][j];
    if (pos[cur].back() <= k) {
      for (auto x : pos[cur]) Union(x, k);
    }
  }
}

int main() {
  fast;
  for (int i = 0; i < maxS; i++) rep[i] = i, sz[i] = 1;
  cin >> n;
  s.resize(n);
  for (int i = 0; i < n; i++) cin >> s[i], add(i);
  for (int i = 0; i < n; i++) {
    check(i);
    cout << cnt << '\n';
  }
}
