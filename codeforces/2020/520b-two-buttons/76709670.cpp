#include <bits/stdc++.h>
using namespace std;
int const inf = 1e9, maxN = 1e5;
int min_steps = inf;
int vis[maxN];
void button(int rn, int n, int steps) {
  vis[rn] = steps;
  if (rn == n) {
    min_steps = min(min_steps, steps);
  } else if (rn != n && steps < min_steps) {
    if (rn < n)
      if (2 * rn < maxN && vis[2 * rn] > steps + 1)
        button(2 * rn, n, steps + 1);
    if (rn > 1 && vis[rn - 1] > steps + 1) button(rn - 1, n, steps + 1);
  }
}

void solution() {
  int n, m;
  fill_n(vis, maxN, inf);
  cin >> n >> m;
  button(n, m, 0);
  cout << min_steps << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  solution();
  return 0;
}
