#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; i++) cin >> s[i];

  for (int i = 0; i < m; i++) {  // pozycja
    char tmp = s[0][i];
    for (int j = 'a'; j <= 'z'; j++) {  // literka na itej pozycji
      s[0][i] = char(j);
      bool correct = true;
      for (int k = 0; k < n; k++) {
        int cnt = 0;
        for (int q = 0; q < m; q++) {  // pozycja w s[0]
          if (s[0][q] != s[k][q]) cnt++;
        }
        if (cnt > 1) correct = false;
      }
      if (correct) {
        cout << s[0] << '\n';
        return;
      }
    }
    s[0][i] = tmp;
  }
  cout << -1 << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
