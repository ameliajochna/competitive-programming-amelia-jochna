#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
using namespace std;
typedef long long ll;

void solution() {
  int n;
  cin >> n;
  vector<vector<int> > w(n);
  int winner = 0;
  for (int i = 0; i < n; i++) {
    w[i].resize(5);
    for (int j = 0; j < 5; j++) cin >> w[i][j];
    int cnt = 0;
    for (int j = 0; j < 5; j++)
      if (w[i][j] < w[winner][j]) cnt++;
    if (cnt >= 3) winner = i;
  }
  for (int i = 0; i < n; i++) {
    if (i == winner) continue;
    int cnt = 0;
    for (int j = 0; j < 5; j++) {
      if (w[i][j] < w[winner][j]) cnt++;
    }
    if (cnt >= 3) {
      cout << "-1\n";
      return;
    }
  }
  cout << winner + 1 << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) solution();
}
