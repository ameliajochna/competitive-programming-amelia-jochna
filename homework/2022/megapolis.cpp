#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define nd second
#define st first
#define pii pair<int, int>
#define pb push_back
typedef long long ll;
int const maxN = (int)25e4 + 10, shift = 1 << 18;  // 1<<18

vector<int> G[maxN];
int n, q, preorder[maxN], postorder[maxN], tree[2 * shift + 10], cnt = -1,
                                                                 dist = -1;

void dfs(int u = 1, int prev = 1) {
  dist++, cnt++;
  preorder[u] = cnt;
  tree[preorder[u] + shift] = dist;
  for (auto v : G[u])
    if (v != prev) dfs(v, u);
  postorder[u] = cnt;
  dist--;
}

int query(int u) {
  u += shift;
  int ans = 0;
  while (u) {
    ans += tree[u];
    u /= 2;
  }
  return ans;
}

void update(int l, int r, int val) {
  l += shift, r += shift;
  tree[l] += val;
  if (l == r) return;
  tree[r] += val;
  while (l / 2 != r / 2) {
    if (l % 2 == 0) tree[l + 1] += val;
    if (r % 2 == 1) tree[r - 1] += val;
    l /= 2, r /= 2;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();

  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    G[u].pb(v);
    G[v].pb(u);
  }

  dfs();

  cin >> q;
  for (int i = 0; i < n + q - 1; i++) {
    char type;
    cin >> type;
    if (type == 'W') {
      int a;
      cin >> a;
      cout << query(preorder[a]) << '\n';
    }
    if (type == 'A') {
      int a, b;
      cin >> a >> b;
      update(preorder[b], postorder[b], -1);
    }
  }
}
