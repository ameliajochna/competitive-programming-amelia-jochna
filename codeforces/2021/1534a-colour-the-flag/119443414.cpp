#include <bits/stdc++.h>
#define nd second
#define st first
using namespace std;
typedef long long ll;

void solution() {
  int n, m;
  cin >> n >> m;
  int ar[n + 1][m + 1];
  pair<int, int> coord = {0, 0};
  int val = 2;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char a;
      cin >> a;
      if (a == 'R') {
        ar[i][j] = 1;
        coord = {i, j};
        val = 1;
      } else if (a == 'W') {
        ar[i][j] = 2;
        coord = {i, j};
        val = 2;
      } else
        ar[i][j] = 0;
    }
  }
  vector<int> s = {2, 1};
  int pt = 0;
  if (coord.first % 2 == 1) {
    if (val == 1)
      val = 2;
    else
      val = 1;
  }
  if (coord.second % 2 == 1) {
    if (val == 1)
      val = 2;
    else
      val = 1;
  }
  if (val == 2)
    pt = 0;
  else
    pt = 1;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (ar[i][j] == 0)
        ar[i][j] = s[pt];
      else if (ar[i][j] != s[pt]) {
        cout << "NO\n";
        return;
      }
      if (pt == 0)
        pt = 1;
      else
        pt = 0;
    }
    if (m % 2 == 0) {
      if (pt == 0)
        pt = 1;
      else
        pt = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int cur, next, down;
      cur = ar[i][j];
      if (i < n - 1)
        next = ar[i + 1][j];
      else if (cur == 1)
        next = 2;
      else
        next = 1;

      if (j < m - 1)
        down = ar[i][j + 1];
      else
        down = next;

      if (down != next || cur == down) {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (ar[i][j] == 1)
        cout << "R";
      else
        cout << "W";
    }
    cout << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solution();
}
