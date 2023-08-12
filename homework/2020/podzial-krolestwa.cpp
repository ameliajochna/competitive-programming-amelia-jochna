#include <bits/stdc++.h>
using namespace std;
#define st first
#define nd second
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
int n, m, g[26][26], deg[26];
int ansmsk, cnt, curmsk, best = INT_MAX;
int cur[26];

void cost(int a, int b) {  // zmienia sie bit w punkcie a i punkcie b
  for (int i = 0; i < 2; i++) {
    curmsk ^= (1 << a);
    cur[a] ^= 1;
    int s = cur[a];
    for (int j = 0; j < deg[a]; j++) {
      int v = g[a][j];
      if (cur[v] == s)
        cnt--;
      else
        cnt++;
    }
    a = b;
  }
  if (best > cnt && (curmsk & 1)) {
    best = cnt;
    ansmsk = curmsk;
  }
}

void gen(int k, int l) {
  if (k == 0 || l == 0) return;

  int op = cur[k + l - 1] ^ 1;
  if (op)
    gen(k - 1, l);
  else
    gen(k, l - 1);

  int last;
  for (last = 0; last < k + l; last++) {
    if (cur[last] == op) break;
  }
  cost(last, k + l - 1);
  if (op)
    gen(k, l - 1);
  else
    gen(k - 1, l);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[v][deg[v]++] = u;
    g[u][deg[u]++] = v;
  }
  curmsk = (1 << (n / 2)) - 1;
  for (int i = 0; i < n; i++) cur[i] = (i < n / 2 ? 1 : 0);

  for (int i = 0; i < n; i++) {
    int bit = cur[i];
    if (bit) continue;
    for (int j = 0; j < deg[i]; j++) {
      int v = g[i][j];
      if (cur[v] != bit) cnt++;
    }
  }
  best = cnt;
  ansmsk = curmsk;
  gen(n / 2, n / 2);
  for (int i = 0; i <= n; i++) {
    if ((1 << i) & ansmsk) cout << i + 1 << " ";
  }
  return 0;
}
