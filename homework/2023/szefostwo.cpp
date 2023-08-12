#include <bits/stdc++.h>
using namespace std;
using lf = long double;
using ll = long long;
using cll = const ll;
using cint = const int;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

int const maxN = (int)5e3 + 10;
vector<int> pospar[maxN], G[maxN];
int n, prnt[maxN], dpth[maxN];

int bfs(int root) {
  queue<int> q;
  q.push(root);
  prnt[root] = root;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto nxt : pospar[u]) {
      if (!prnt[nxt]) {
        prnt[nxt] = u;
        dpth[nxt] = dpth[u] + 1;
        q.push(nxt);
      }
    }
  }
  int sum = n;
  for (int i = 1; i <= n; i++) sum += dpth[i];
  return sum;
}

pii calcans(int u, int prev) {  //{suma dzieci, suma poddrzewa}
  int child = 0, sum = 0;
  for (auto v : G[u]) {
    if (v != prev) {
      pii tmp = calcans(v, u);
      child += tmp.st;
      sum += tmp.nd;
    }
  }
  return {child + 1, sum + child + 1};
}

int root(int u) {  // odpowiedz jezeli u jest rootem
  for (int i = 1; i <= n; i++) prnt[i] = 0, dpth[i] = 0;
  int ans = bfs(u);
  for (int i = 2; i <= n; i++)
    if (prnt[i] == 0) return 1e9;

  return ans;
}

int main() {
  fast cin >> n;
  for (int i = 1; i <= n; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int v;
      cin >> v;
      pospar[v].push_back(i);
    }
  }
  int minans = 1e9;
  for (int i = 1; i <= n; i++) {
    minans = min(minans, root(i));
  }
  cout << minans << '\n';
}
