#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
using namespace std;
typedef long long ll;

bool intersect(pii a, pii b) {  // czy
  return (b.st < a.st && a.st < b.nd && b.nd < a.nd);
}

void solution() {
  int n, k;
  cin >> n >> k;
  vector<pii> edge(k);
  for (int i = 0; i < k; i++) {
    cin >> edge[i].st >> edge[i].nd;
    edge[i].st--;
    edge[i].nd--;
  }

  vector<bool> vis(2 * n + 1);
  for (auto x : edge) vis[x.st] = true, vis[x.nd] = true;
  vector<int> g1, g2;
  int free = n - k;
  for (int i = 0; i < 2 * n; i++) {
    if (vis[i]) continue;
    if (free > 0) {
      g1.push_back(i);
      free--;
    } else
      g2.push_back(i);
  }
  for (int i = 0; i < (n - k); i++) edge.push_back({g1[i], g2[i]});

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      // czy i i j sie przecinaja
      pii &e1 = edge[i], &e2 = edge[j];
      if (e1.st > e1.nd) swap(e1.st, e1.nd);
      if (e2.st > e2.nd) swap(e2.st, e2.nd);
      cnt += (intersect(e1, e2) | intersect(e2, e1));
    }
  }
  cout << cnt / 2 << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) solution();
}
