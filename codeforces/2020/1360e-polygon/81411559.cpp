#include <bits/stdc++.h>
using namespace std;
void solution() {
  int n;
  cin >> n;
  vector<string> s(n + 1);
  for (int i = 0; i < n; i++) {
    string tmp;
    cin >> tmp;
    tmp = tmp + '1';
    s[i] = tmp;
  }
  string tmp;
  for (int i = 0; i <= n; i++) tmp += '1';
  s[n] = tmp;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (s[i][j] == '1') {
        if (s[i][j + 1] != '1' && s[i + 1][j] != '1') {
          cout << "NO\n";
          return;
        }
      }
    }
  }
  cout << "YES\n";
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
