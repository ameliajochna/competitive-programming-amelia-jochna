#include <bits/stdc++.h>
using namespace std;

void solution() {
  int n;
  cin >> n;
  vector<string> board;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    board.push_back(s);
  }
  int cnt = 0;
  pair<int, int> coords[2];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == '*') {
        coords[cnt++] = {i, j};
      }
    }
  }
  pair<int, int> add[2];
  if (coords[0].first == coords[1].first) {
    add[0] = {(coords[0].first + 1) % n, coords[0].second};
    add[1] = {(coords[0].first + 1) % n, coords[1].second};
  } else if (coords[0].second == coords[1].second) {
    add[0] = {coords[0].first, (coords[0].second + 1) % n};
    add[1] = {coords[1].first, (coords[0].second + 1) % n};
  } else {
    add[0] = {coords[0].first, coords[1].second};
    add[1] = {coords[1].first, coords[0].second};
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      pair<int, int> cur = {i, j};
      if (cur == add[0] || cur == add[1])
        cout << "*";
      else
        cout << board[i][j];
    }
    cout << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) solution();
}
