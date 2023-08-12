#include <bits/stdc++.h>
using namespace std;
using lf = long double;
using ll = long long;
using cll = const ll;
using cint = const int;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
#define int long long

int const maxN = (int)1e6 + 10, MOD = (int)1e9 + 7;
int m, ind, szz[maxN], clr[maxN], cnt;
bool vis[maxN];
string s;
vector<int> G[maxN];
vector<int> Br[maxN];
set<int> sum;

void build(int sz) {
  if (ind == s.size()) return;
  int cur = ind;
  szz[cur] = sz;
  if (s[ind] == '4') {
    for (int i = 0; i < 4; i++) {
      ind++;
      G[cur].pb(ind);
      build(sz - 1);
    }
  } else if (s[ind] == '0')
    clr[cur] = -1;
  else if (s[ind] == '1')
    clr[cur] = 1;
}

void veredge(int u, int v) {  // u na gorze, v na dole
  // dbg("ver", u, v, clr[u], clr[v]);
  if (clr[u] == -1 || clr[v] == -1) return;
  if (clr[u] == 1 && clr[v] == 1) {
    //    dbg(u, v);
    Br[u].push_back(v);
    Br[v].push_back(u);
  }

  if (G[u].size() == 4 && G[v].size() == 4) {
    veredge(G[u][2], G[v][0]);
    veredge(G[u][3], G[v][1]);
  } else if (G[u].size() == 4) {
    veredge(G[u][2], v);
    veredge(G[u][3], v);
  } else if (G[v].size() == 4) {
    veredge(u, G[v][0]);
    veredge(u, G[v][1]);
  }
}

void horedge(int u, int v) {  // u po lewej, v po prawej
  // dbg("hor", u, v, clr[u], clr[v]);
  if (clr[u] == -1 || clr[v] == -1) return;
  if (clr[u] == 1 && clr[v] == 1) {
    // dbg(u, v);
    Br[u].push_back(v);
    Br[v].push_back(u);
  }

  if (G[u].size() == 4 && G[v].size() == 4) {
    horedge(G[u][1], G[v][0]);
    horedge(G[u][3], G[v][2]);
  } else if (G[u].size() == 4) {
    horedge(G[u][1], v);
    horedge(G[u][3], v);
  } else if (G[v].size() == 4) {
    horedge(u, G[v][0]);
    horedge(u, G[v][2]);
  }
}

void edges(int u) {
  if (G[u].size() == 4) {
    veredge(G[u][0], G[u][2]);
    veredge(G[u][1], G[u][3]);
    horedge(G[u][0], G[u][1]);
    horedge(G[u][2], G[u][3]);
    for (int i = 0; i < 4; i++) edges(G[u][i]);
  }
}

void dfs(int u) {
  vis[u] = true;
  if (!G[u].size()) {
    int cursz = 2 * szz[u];
    while (sum.count(cursz)) {
      sum.erase(sum.find(cursz));
      cursz++;
    }
    sum.insert(cursz);
  }
  for (auto v : Br[u])
    if (!vis[v]) dfs(v);
}

ll pwr(ll a, ll b) {  //(a^b)%MOD
  if (b == 0) return 1;

  if (b % 2 == 0) {
    ll ans1 = pwr(a, b / 2);
    return (ans1 * ans1 + MOD) % MOD;
  }

  if (b % 2 == 1) return (a * pwr(a, b - 1) + MOD) % MOD;
}

int32_t main() {
  fast;
  cin >> m >> s;
  ind = 0;
  build(m);
  edges(0);
  vector<int> vecmax;
  for (int i = 0; i <= ind; i++) {
    if (clr[i] != 1 || vis[i]) continue;
    sum.clear();
    dfs(i);
    cnt++;
    vector<int> curv;
    for (auto x : sum) curv.pb(x);
    reverse(all(curv));
    if (curv > vecmax) vecmax = curv;
  }

  ll ans = 0;
  for (auto q : vecmax) {
    ans += pwr(2, q);
    ans %= MOD;
    ans += MOD;
    ans %= MOD;
  }
  cout << cnt << '\n' << ans << '\n';
}
