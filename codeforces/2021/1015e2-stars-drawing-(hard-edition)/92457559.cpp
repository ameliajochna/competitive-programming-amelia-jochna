#include <bits/stdc++.h>
using namespace std;
int const maxN = 1002;
int n, m;
int _left[maxN][maxN], _right[maxN][maxN], up[maxN][maxN], down[maxN][maxN],
    a[maxN][maxN];
vector<vector<int> > v;

bool check() {
  for (auto vect : v) {
    int x = vect[0] - 1, y = vect[1] - 1, len = vect[2];
    a[x][y] = 0;
    int tmp = x, cnt = 0;
    while (tmp >= 0 && cnt <= len) a[tmp][y] = 0, tmp--, cnt++;
    cnt = 0, tmp = x;
    while (tmp < n && cnt <= len) a[tmp][y] = 0, tmp++, cnt++;
    cnt = 0, tmp = y;
    while (tmp >= 0 && cnt <= len) a[x][tmp] = 0, tmp--, cnt++;
    cnt = 0, tmp = y;
    while (tmp < m && cnt <= len) a[x][tmp] = 0, tmp++, cnt++;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      if (a[i][j]) return false;
  }
  return true;
}

void arcalcs() {
  // left
  for (int i = 0; i < n; i++)
    if (a[i][0]) _left[i][0] = 1;
  for (int i = 0; i < n; i++)
    for (int j = 1; j < m; j++) {
      if (a[i][j]) _left[i][j] = _left[i][j - 1] + 1;
    }
  // right
  for (int i = n - 1; i >= 0; i--)
    if (a[i][m - 1]) _right[i][m - 1] = 1;
  for (int i = n - 1; i >= 0; i--)
    for (int j = m - 2; j >= 0; j--) {
      if (a[i][j]) _right[i][j] = _right[i][j + 1] + 1;
    }
  // up
  for (int j = 0; j < m; j++)
    if (a[0][j]) up[0][j] = 1;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j]) up[i][j] = up[i - 1][j] + 1;
    }
  }
  // down
  for (int j = 0; j < m; j++)
    if (a[n - 1][j]) down[n - 1][j] = 1;
  for (int i = n - 2; i >= 0; i--) {
    for (int j = 0; j < m; j++) {
      if (a[i][j]) down[i][j] = down[i + 1][j] + 1;
    }
  }
}

void ans() {
  for (int i = 1; i < n - 1; i++) {
    for (int j = 1; j < m - 1; j++) {
      if (a[i][j]) {
        int tmp = min(
            {_left[i][j - 1], up[i - 1][j], _right[i][j + 1], down[i + 1][j]});
        if (tmp > 0) v.push_back({i + 1, j + 1, tmp});
      }
    }
  }
  if (!check())
    cout << -1;
  else {
    cout << v.size() << '\n';
    for (auto vect : v)
      cout << vect[0] << " " << vect[1] << " " << vect[2] << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();

  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      if (c == '*')
        a[i][j] = 1;
      else
        a[i][j] = 0;
    }
  arcalcs();
  ans();
}
