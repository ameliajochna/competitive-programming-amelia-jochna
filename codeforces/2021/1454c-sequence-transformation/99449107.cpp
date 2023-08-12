#include <bits/stdc++.h>
using namespace std;

void solution() {
  int mincost = INT_MAX;
  int n;
  cin >> n;
  map<int, vector<int> > m;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    m[a].push_back(i);
  }
  for (auto &x : m) {
    int cost = 0;
    if (x.second[x.second.size() - 1] != n - 1) x.second.push_back(n);
    for (int i = 0; i < x.second.size(); i++) {
      int cur = x.second[i];
      int jump = i;
      bool change = false;
      while (jump < x.second.size() - 1 &&
             x.second[jump] + 1 == x.second[jump + 1])
        jump++, change = true;
      if (cur == 0) {
        i = jump;
        continue;
      }
      cost++;
      i = jump;
    }
    mincost = min(mincost, cost);
  }
  cout << mincost << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) solution();
}
