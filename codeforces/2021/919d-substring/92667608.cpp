#include <bits/stdc++.h>
using namespace std;
int const maxN = 3e5 + 10;
vector<int> v[maxN];
int lettercnt[maxN]['z' - 'a' + 1];
int incnt[maxN], n, m;
string s;

void add(int a, int b) {
  for (int i = 0; i <= 'z' - 'a'; i++) {
    lettercnt[b][i] =
        max(lettercnt[b][i], lettercnt[a][i] + (s[b - 1] - 'a' == i));
  }
}

void topsort() {
  for (int i = 1; i <= n; i++) lettercnt[i][s[i - 1] - 'a']++;
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (incnt[i] == 0) q.push(i);
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto w : v[u]) {
      incnt[w]--;
      add(u, w);
      if (incnt[w] == 0) q.push(w);
    }
  }
}

int main() {
  cin >> n >> m >> s;
  for (int i = 0; i < m; i++) {
    int u, w;
    cin >> u >> w;
    v[u].push_back(w);
    incnt[w]++;
  }
  topsort();
  for (int i = 1; i <= n; i++) {
    if (incnt[i] != 0) {
      cout << "-1";
      return 0;
    }
  }
  int maxans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 'z' - 'a'; j++) maxans = max(maxans, lettercnt[i][j]);
  }
  cout << maxans << '\n';
}
