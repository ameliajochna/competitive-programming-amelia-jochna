#include <bits/stdc++.h>
#define nd second
#define st first
#define pll pair<ll, ll>
using namespace std;
typedef long long ll;
typedef long double ld;

void solution() {
  int n, m;
  cin >> n >> m;
  vector<string> v(n), shuf(n - 1);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    v[i] = s;
  }
  for (int i = 0; i < n - 1; i++) {
    string s;
    cin >> s;
    shuf[i] = s;
  }
  vector<vector<int> > bef(m + 1);
  for (int i = 0; i < m; i++) bef[i].resize(27);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char cur = v[i][j];
      bef[j][cur - 'a']++;
    }
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m; j++) {
      char cur = shuf[i][j];
      bef[j][cur - 'a']--;
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 27; j++) {
      if (bef[i][j] > 0) {
        cout << char('a' + j);
      }
    }
  }
  cout << '\n';
  cout.flush();
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();
}
