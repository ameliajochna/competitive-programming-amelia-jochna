#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solution() {
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    string tmp;
    cin >> tmp;
    tmp.push_back('*');
    s[i] = tmp;
  }
  if (2 * x <= y) {
    int whitecnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        if (s[i][j] == '.') whitecnt++;
    }
    cout << whitecnt * x << '\n';
  } else {
    int price = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (s[i][j] == '.') {
          if (s[i][j + 1] == '.')
            price += y, j++;
          else
            price += x;
        }
      }
    }
    cout << price << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();
  return 0;
}
