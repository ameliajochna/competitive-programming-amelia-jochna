#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
using namespace std;
typedef long long ll;

void solution() {
  int n;
  cin >> n;
  vector<int> G[n + 1];
  vector<int> indeg(n + 1);
  for (int i = 1; i <= n; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int cur;
      cin >> cur;
      G[cur].push_back(i);
      indeg[i]++;
    }
  }
  set<int> s;
  int cnt = 0;
  for (int i = 1; i <= n; i++)
    if (indeg[i] == 0) s.insert(i);

  while (!s.empty()) {
    int prev = -1;
    for (auto &x : s) {
      if (x < prev) continue;
      if (prev != -1) s.erase(prev);
      prev = x;
      for (auto v : G[x]) {
        indeg[v]--;
        if (indeg[v] == 0) s.insert(v);
      }
    }
    if (prev != -1) s.erase(prev);
    cnt++;
  }
  for (int i = 1; i <= n; i++)
    if (indeg[i] != 0) {
      cout << "-1\n";
      return;
    }
  cout << cnt << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();
}
